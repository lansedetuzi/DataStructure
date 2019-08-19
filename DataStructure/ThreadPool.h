#pragma once

#include <list>
#include <Windows.h>
using namespace std;

#define THRESHOLE_OF_WAIT_TASK  20

typedef int (*TaskFunc)(void *param);           // ������
typedef void (*TaskCallbackFunc)(int result);   // �ص�����

class ThreadPool
{
    class WaitTask;
    class Thread;
public:
    ThreadPool(size_t minNumOfThread = 2, size_t maxNumOfThread = 10);
    ~ThreadPool();

    BOOL PushBackTaskItem(TaskFunc task, void *param, TaskCallbackFunc taskCb = nullptr, BOOL bLongFunc = FALSE);    // ������������б�

private:
    static unsigned int __stdcall GetTaskThreadProc(PVOID param);

    void ExecTask();                                      // �����������ȡ����ִ��
    WaitTask *GetTask();                                // �����������ȡ����

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

        BOOL IsBusy();                                                          // �Ƿ���������ִ��
        void DoTask(TaskFunc task, void *param, TaskCallbackFunc taskCb);       // ִ������

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

        TaskFunc m_task;                    // ����
        void *m_param;                      // �������
        TaskCallbackFunc m_taskCallback;    // ����ص�
        BOOL m_bLongFunc;                   // �Ƿ�ʱ������
    };

    /*
    @brief: �߳��ٽ�����
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

    size_t GetCurNumOfThread();                                 // ��ȡ�̳߳��еĵ�ǰ�߳���
    size_t GetIdleThreadNum();                                  // ��ȡ�̳߳��е��߳���
    size_t GetBusyThreadNum();                                  // ��ȡ�̳߳��е��߳���
    size_t GetMaxNumOfThread();                                 // ��ȡ�̳߳��е�����߳���
    void SetMaxNumOfThread(size_t size);                        // �����̳߳��е�����߳���
    size_t GetMinNumOfThread();                                 // ��ȡ�̳߳��е���С�߳���
    void SetMinNumOfThread(size_t size);                        // �����̳߳��е���С�߳���

    void CreateIdleThread(size_t size);                         // ���������߳�
    void DeleteIdleThread(size_t size);                         // ɾ�������߳�
    Thread* GetIdleThread();                                    // ��ȡ�����߳�

    void MoveBusyThreadToIdleList(Thread *busyThread);              // æµ�̼߳�������б�
    void MoveThreadToBusyList(Thread *thread);                      // �̼߳���æµ�б�

    CSLock m_idleThreadLock;                                    // �����߳��б���
    list<Thread*> m_lIdleThreadList;                            // �����߳��б�

    CSLock m_busyThreadLock;                                    // �����߳��б���
    list<Thread*> m_lBusyThreadList;                            // �����߳��б�

    CSLock m_waitTaskLock;                                      // �����б���
    list<WaitTask*> m_lWaitTaskList;                            // �����б�

    HANDLE m_hDispatchThread;                                 // �ַ������߳�
    HANDLE m_hStopEvent;                                      // ֪ͨ�߳��˳����¼�
    HANDLE m_hCompletionPort;                                 // ��ɶ˿�

    size_t m_maxNumOfThread;                                  // �̳߳��������߳���
    size_t m_minNumOfThread;                                  // �̳߳�����С���߳���
    size_t m_numOfLongFun;                                    // �̳߳��д���ʱ��������߳���
};
