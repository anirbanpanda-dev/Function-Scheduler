#include "SchedulerService.h"

std::mutex SchedulerService::schedulerMutex;

SchedulerService* SchedulerService::m_schedulerservice  = NULL;

SchedulerService::SchedulerService(){}

SchedulerService* SchedulerService::getInstance(){
    if(!m_schedulerservice){
        schedulerMutex.lock();
        if(!m_schedulerservice){
            m_schedulerservice = new SchedulerService();
        }
        schedulerMutex.unlock();
    }
    return m_schedulerservice;
}

void SchedulerService::Schedule(std::function<void()> workFunctor, int interval){
    Task* task = new Task(workFunctor, interval);
    enqueueTaskMutex.lock();
    TaskCache::getInstance()->EnQueueTaskForRunning(task);
    enqueueTaskMutex.unlock();
}

