#pragma once

#include <list>
#include <Windows.h>
using namespace std;

#define THRESHOLE_OF_WAIT_TASK  20

typedef int (*TaskFunc)(void *param);           // 任务函数
typedef void (*TaskCallbackFunc)(int result);   // 回调函数

class ThreadPool
{
    class WaitTask;
    class Thread;
public:
    ThreadPool(size_t minNumOfThread = 2, size_t maxNumOfThread = 10);
    ~ThreadPool();

    BOOL PushBackTaskItem(TaskFunc task, void *param, TaskCallbackFunc taskCb = nullptr, BOOL bLongFunc = FALSE);    // 任务插入任务列表

private:
    static unsigned int __stdcall GetTaskThreadProc(PVOID param);

    void ExecTask();                                      // 从任务队列中取任务执行
    WaitTask *GetTask();                                // 从任务队列中取任务

    enum OPER_TYPE
    {
        TASK,
        EXIT
    };

    class Thread
    {
    public:
        Thread(ThreadPool *threadPool);
        ~Thread();

        BOOL IsBusy();                                                          // 是否有任务在执行
        void DoTask(TaskFunc task, void *param, TaskCallbackFunc taskCb);       // 执行任务

    private:
        ThreadPool *m_threadPool;
        BOOL m_bBusy;
        BOOL m_bExit;
        HANDLE m_hThread;
        TaskFunc m_task;
        void *m_param;
        TaskCallbackFunc m_taskCb;
        static unsigned int __stdcall ThreadProc(PVOID param);
    };

    class WaitTask
    {
    public:
        WaitTask(TaskFunc task, void* param, TaskCallbackFunc taskCb, BOOL bLong);
        ~WaitTask();

        TaskFunc m_task;                    // 任务
        void *m_param;                      // 任务参数
        TaskCallbackFunc m_taskCallback;    // 任务回调
        BOOL m_bLongFunc;                   // 是否时长任务
    };

    /*
    @brief: 线程临界区锁
    */
    class CSLock
    {
    public:
        CSLock();
        ~CSLock();
        void Lock();
        void Unlock();
    private:
        CRITICAL_SECTION cs;
    };

    size_t GetCurNumOfThread();                                 // 获取线程池中的当前线程数
    size_t GetIdleThreadNum();                                  // 获取线程池中的线程数
    size_t GetBusyThreadNum();                                  // 获取线程池中的线程数
    size_t GetMaxNumOfThread();                                 // 获取线程池中的最大线程数
    void SetMaxNumOfThread(size_t size);                        // 设置线程池中的最大线程数
    size_t GetMinNumOfThread();                                 // 获取线程池中的最小线程数
    void SetMinNumOfThread(size_t size);                        // 设置线程池中的最小线程数

    void CreateIdleThread(size_t size);                         // 创建空闲线程
    void DeleteIdleThread(size_t size);                         // 删除空闲线程
    Thread* GetIdleThread();                                    // 获取空闲线程

    void MoveBusyThreadToIdleList(Thread *busyThread);              // 忙碌线程加入空闲列表
    void MoveThreadToBusyList(Thread *thread);                      // 线程加入忙碌列表

    CSLock m_idleThreadLock;                                    // 空闲线程列表锁
    list<Thread*> m_lIdleThreadList;                            // 空闲线程列表

    CSLock m_busyThreadLock;                                    // 工作线程列表锁
    list<Thread*> m_lBusyThreadList;                            // 工作线程列表

    CSLock m_waitTaskLock;                                      // 任务列表锁
    list<WaitTask*> m_lWaitTaskList;                            // 任务列表

    HANDLE m_hDispatchThread;                                 // 分发任务线程
    HANDLE m_hStopEvent;                                      // 通知线程退出的事件
    HANDLE m_hCompletionPort;                                 // 完成端口

    size_t m_maxNumOfThread;                                  // 线程池中最大的线程数
    size_t m_minNumOfThread;                                  // 线程池中最小的线程数
    size_t m_numOfLongFun;                                    // 线程池中处理时长任务的线程数
};
