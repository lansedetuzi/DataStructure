#include "stdafx.h"
#include "ThreadPool.h"

#include <process.h>
ThreadPool::ThreadPool(size_t minNumOfThread /*= 2*/, size_t maxNumOfThread /*= 10*/)
{
    if (m_minNumOfThread < 2)
        m_minNumOfThread = 2;
    else
        m_minNumOfThread = minNumOfThread;

    if (m_maxNumOfThread < m_minNumOfThread * 2)
        m_maxNumOfThread = m_minNumOfThread * 2;
    else
        m_maxNumOfThread = maxNumOfThread;

    m_hStopEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    m_hCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 1);
    
    m_lIdleThreadList.clear();
    CreateIdleThread(m_minNumOfThread);
    m_lBusyThreadList.clear();

    m_hDispatchThread = (HANDLE)_beginthreadex(NULL, 0, GetTaskThreadProc, this, 0, 0);
    m_numOfLongFun = 0;
}

ThreadPool::~ThreadPool()
{
    SetEvent(m_hStopEvent);
    PostQueuedCompletionStatus(m_hCompletionPort, 0, (DWORD)EXIT, NULL);
    CloseHandle(m_hStopEvent);
}

BOOL ThreadPool::PushBackTaskItem(TaskFunc task, void *param, TaskCallbackFunc taskCb /*= nullptr*/, BOOL bLongFunc /*= FALSE*/)
{
    m_waitTaskLock.Lock();
    WaitTask *newTask = new WaitTask(task, param, taskCb, bLongFunc);
    m_lWaitTaskList.push_back(newTask);
    m_waitTaskLock.Unlock();
    ::PostQueuedCompletionStatus(m_hCompletionPort, 0, (DWORD)TASK, NULL);
    return TRUE;
}

unsigned int __stdcall ThreadPool::GetTaskThreadProc(PVOID param)
{
    ThreadPool *threadPool = (ThreadPool*)param;
    DWORD dwBytes = 0;
    OPER_TYPE type = TASK;
    OVERLAPPED *ol;
    while (WAIT_OBJECT_0 != WaitForSingleObject(threadPool->m_hStopEvent, 0))
    {
        GetQueuedCompletionStatus(threadPool->m_hCompletionPort, &dwBytes, (PULONG_PTR)&type, &ol, INFINITE);
        if (EXIT == (DWORD)type)
        {
            break;
        }
        else if (TASK == (DWORD)type)
        {
            threadPool->ExecTask();
        }
    }

    return 0;
}

void ThreadPool::ExecTask()
{
    WaitTask *waitTask = GetTask();
    if (nullptr == waitTask)
        return;

    Thread *pThread = nullptr;
    if (waitTask->m_bLongFunc)
    {
        if (m_lIdleThreadList.size() > m_minNumOfThread)
        {
            pThread = GetIdleThread();
        }
        else
        {
            pThread = new Thread(this);
            InterlockedIncrement(&m_numOfLongFun);
            InterlockedIncrement(&m_maxNumOfThread);
        }
    }
    else
    {
        pThread = GetIdleThread();
    }

    if (nullptr != pThread)
    {
        pThread->DoTask(waitTask->m_task, waitTask->m_param, waitTask->m_taskCallback);
        delete waitTask;
        MoveThreadToBusyList(pThread);
    }
    else
    {
        m_waitTaskLock.Lock();
        m_lWaitTaskList.push_back(waitTask);
        m_waitTaskLock.Unlock();
    }
}

ThreadPool::WaitTask * ThreadPool::GetTask()
{
    WaitTask *task = nullptr;
    m_waitTaskLock.Lock();
    if (m_lWaitTaskList.size() > 0)
    {
        task = m_lWaitTaskList.front();
        m_lWaitTaskList.pop_front();
    }
    m_waitTaskLock.Unlock();
    return task;
}

size_t ThreadPool::GetCurNumOfThread()
{
    return GetIdleThreadNum() + GetBusyThreadNum();
}

size_t ThreadPool::GetIdleThreadNum()
{
    return m_lIdleThreadList.size();
}

size_t ThreadPool::GetBusyThreadNum()
{
    return m_lBusyThreadList.size();
}

size_t ThreadPool::GetMaxNumOfThread()
{
    return m_maxNumOfThread - m_numOfLongFun;
}

void ThreadPool::SetMaxNumOfThread(size_t size)
{
    if (size < m_numOfLongFun)
    {
        m_maxNumOfThread = size + m_numOfLongFun;
    }
    else
    {
        m_maxNumOfThread = size;
    }
}

size_t ThreadPool::GetMinNumOfThread()
{
    return m_minNumOfThread;
}

void ThreadPool::SetMinNumOfThread(size_t size)
{
    m_minNumOfThread = size;
}

void ThreadPool::CreateIdleThread(size_t size)
{
    m_idleThreadLock.Lock();
    for (size_t i = 0; i < size; i++)
    {
        m_lIdleThreadList.push_back(new Thread(this));
    }
    m_idleThreadLock.Unlock();
}

void ThreadPool::DeleteIdleThread(size_t size)
{
    m_idleThreadLock.Lock();
    size_t delThreadCount = m_lIdleThreadList.size() >= size ? size : m_lIdleThreadList.size();
    for (size_t i = 0; i < delThreadCount; i++)
    {
        Thread *pThread = m_lIdleThreadList.back();
        delete pThread;
        m_lIdleThreadList.pop_back();
    }
    m_idleThreadLock.Unlock();
}

ThreadPool::Thread* ThreadPool::GetIdleThread()
{
    Thread *pThread = nullptr;
    m_idleThreadLock.Lock();
    if (m_lIdleThreadList.size() > 0)
    {
        pThread = m_lIdleThreadList.front();
        m_lIdleThreadList.pop_front();
    }
    m_idleThreadLock.Unlock();

    if (nullptr == pThread && GetCurNumOfThread() < m_maxNumOfThread)
    {
        pThread = new Thread(this);
    }

    if (nullptr == pThread && m_lWaitTaskList.size() > THRESHOLE_OF_WAIT_TASK)
    {
        pThread = new Thread(this);
        InterlockedIncrement(&m_maxNumOfThread);
    }
    return pThread;
}

void ThreadPool::MoveBusyThreadToIdleList(Thread *busyThread)
{
    m_idleThreadLock.Lock();
    m_lIdleThreadList.push_back(busyThread);
    m_idleThreadLock.Unlock();

    m_busyThreadLock.Lock();
    for (auto it = m_lBusyThreadList.begin(); it != m_lBusyThreadList.end(); it++)
    {
        if (*it == busyThread)
        {
            m_lBusyThreadList.erase(it);
            break;
        }
    }
    m_busyThreadLock.Unlock();

    if (m_maxNumOfThread != 0 && m_lIdleThreadList.size() > m_maxNumOfThread * 0.8)
    {
        DeleteIdleThread(m_lIdleThreadList.size() / 2);
    }

    ::PostQueuedCompletionStatus(m_hCompletionPort, 0, (DWORD)TASK, NULL);
}

void ThreadPool::MoveThreadToBusyList(Thread *thread)
{
    m_busyThreadLock.Lock();
    m_lBusyThreadList.push_back(thread);
    m_busyThreadLock.Unlock();
}

ThreadPool::Thread::Thread(ThreadPool *threadPool) :
    m_threadPool(threadPool)
    , m_bBusy(FALSE)
    , m_bExit(FALSE)
    , m_task(nullptr)
    , m_param(nullptr)
    , m_taskCb(nullptr)
    , m_hThread(INVALID_HANDLE_VALUE)
{
    m_hThread = (HANDLE)_beginthreadex(NULL, 0, ThreadProc, this, CREATE_SUSPENDED, 0);
}

ThreadPool::Thread::~Thread()
{
    m_bExit = TRUE;
    m_task = nullptr;
    m_param = nullptr;
    m_taskCb = nullptr;
    ResumeThread(m_hThread);
    WaitForSingleObject(m_hThread, INFINITE);
    CloseHandle(m_hThread);
}

BOOL ThreadPool::Thread::IsBusy()
{
    return m_bBusy;
}

void ThreadPool::Thread::DoTask(TaskFunc task, void *param, TaskCallbackFunc taskCb)
{
    m_bBusy = TRUE;
    m_task = task;
    m_param = param;
    m_taskCb = taskCb;
    ResumeThread(m_hThread);
}

unsigned int __stdcall ThreadPool::Thread::ThreadProc(PVOID param)
{
    Thread *pThread = (Thread*)param;

    while (true)
    {
        if (pThread->m_bExit)
            break;

        if (nullptr == pThread->m_task && nullptr == pThread->m_taskCb)
        {
            pThread->m_bBusy = FALSE;
            pThread->m_threadPool->MoveBusyThreadToIdleList(pThread);
            SuspendThread(pThread->m_hThread);
            continue;
        }

        int nRel = pThread->m_task(pThread->m_param);
        if (pThread->m_taskCb)
            pThread->m_taskCb(nRel);

        WaitTask *waitTask = pThread->m_threadPool->GetTask();
        if (nullptr != waitTask)
        {
            pThread->m_task = waitTask->m_task;
            pThread->m_param = waitTask->m_param;
            pThread->m_taskCb = waitTask->m_taskCallback;
            delete waitTask;
            continue;
        }
        else
        {
            pThread->m_task = nullptr;
            pThread->m_param = nullptr;
            pThread->m_taskCb = nullptr;
            pThread->m_bBusy = FALSE;
            pThread->m_threadPool->MoveBusyThreadToIdleList(pThread);
            SuspendThread(pThread->m_hThread);
        }
    }

    return 0;
}

ThreadPool::CSLock::CSLock()
{
    InitializeCriticalSection(&cs);
}

ThreadPool::CSLock::~CSLock()
{
    DeleteCriticalSection(&cs);
}

void ThreadPool::CSLock::Lock()
{
    EnterCriticalSection(&cs);
}

void ThreadPool::CSLock::Unlock()
{
    LeaveCriticalSection(&cs);
}

ThreadPool::WaitTask::WaitTask(TaskFunc task, void* param, TaskCallbackFunc taskCb, BOOL bLong) :
    m_task(task)
    , m_param(param)
    , m_taskCallback(taskCb)
    , m_bLongFunc(bLong)
{

}

ThreadPool::WaitTask::~WaitTask()
{
    m_task = nullptr;
    m_param = nullptr;
    m_taskCallback = nullptr;
    m_bLongFunc = FALSE;
}
