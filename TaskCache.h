#pragma once

#include <iostream>
#include <map>
#include "Common.h"
#include "Task.h"
#include <queue>
#include <vector>
#include <map>

using namespace std;

class TaskCache{

    static TaskCache* m_Cache;
    std::vector<int> taskRecords;
    multimap<int, Task*> cacheMap;
    static std::mutex cacheMutex;
    TaskCache();
    public : 
    static TaskCache* getInstance();
    void EnQueueTaskForRunning(Task* task);
    multimap<int, Task*> GetPriorityTask();
    void addRecords(Task* task);
    void getRecords(vector<int>& results);
    
};