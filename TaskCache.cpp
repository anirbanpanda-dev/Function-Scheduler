#include "TaskCache.h"

std::mutex TaskCache::cacheMutex;

TaskCache::TaskCache(){}

TaskCache* TaskCache::m_Cache = NULL;

void TaskCache::EnQueueTaskForRunning(Task* task){
    if(!task) throw -1;// exception calss
    time_t executionTime = task->getstartTime() + task->GetInterval();
    cout << "adding to cache with timestamp :: " << executionTime << endl;
    cacheMap.insert({executionTime, task});
    task->setStatus(Status::CACHED);
    addRecords(task);
}

void TaskCache::addRecords(Task* task){
    // for storing historical task data
}

multimap<int, Task*> TaskCache::GetPriorityTask(){
    return cacheMap;
}

TaskCache* TaskCache::getInstance(){
    if(!m_Cache){
        cacheMutex.lock();
        if(!m_Cache){
            m_Cache = new TaskCache();
        }
        cacheMutex.unlock();
    }
    
    return m_Cache;
}


