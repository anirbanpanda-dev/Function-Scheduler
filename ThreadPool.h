#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include "Task.h"
#include "Common.h"
#include <condition_variable>
#include <mutex>

class ThreadPool{
    static ThreadPool* pool;
    std::vector<std::thread> threadList;
    // std::queue<std::function<void()>> taskQueue;
    std::queue<Task*> taskQueue;
    int poolSize;
    std::condition_variable cond_var;
    std::mutex poolMutex;
    std::mutex PoolEnqueueMutex;
    ThreadPool();
    void runThreads();
    public : 
    static ThreadPool* getInstance();
    void EnQueueTask(Task* task);
};