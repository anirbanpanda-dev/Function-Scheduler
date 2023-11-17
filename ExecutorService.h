#pragma once
#include <iostream>
#include <thread>
#include "ThreadPool.h"
#include "TaskCache.h"
#include <mutex>

class ExecutorService{
    static ExecutorService* executorService;
    std::thread ExecutorThread;
    static std::mutex executorMutex;
    std::mutex BatchProcessMutex;
    void BatchProcessData();
    ExecutorService();

    public : 
    static ExecutorService* getInstance();
    void run();


};
