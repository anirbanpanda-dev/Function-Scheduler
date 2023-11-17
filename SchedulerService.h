#pragma once
#include <iostream>
#include "Common.h"
#include "TaskCache.h"
#include "Task.h"
#include <chrono>
#include <mutex>

class SchedulerService{
    static SchedulerService* m_schedulerservice;
    TaskCache* cache;
    static std::mutex schedulerMutex;
    std::mutex enqueueTaskMutex;
    SchedulerService();
    public : 
    static SchedulerService* getInstance();
    void Schedule(std::function<void()> workFunctor, int interval);
};