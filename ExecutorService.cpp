#include "ExecutorService.h"

ExecutorService* ExecutorService::executorService = NULL;
std::mutex ExecutorService::executorMutex;

ExecutorService::ExecutorService(){}
    
ExecutorService* ExecutorService::getInstance(){
    if(!executorService){
        executorMutex.lock();
        if(!executorService){
            executorService = new ExecutorService();
        }
        executorMutex.unlock();
    }
    
    return executorService;
}

void ExecutorService::run(){
    ExecutorThread = std::thread([this](){
        while(true){
            BatchProcessData();
            sleep(MINUTE);
        }
    });
}

void ExecutorService::BatchProcessData(){
    // BatchProcessMutex.lock();
    auto now = chrono::system_clock::now();
    auto t = chrono::duration_cast<chrono::minutes>(now.time_since_epoch());
    time_t currentTime = t.count();
    cout << " ExecutorService::BatchProcessData " << endl;
    for(auto it : TaskCache::getInstance()->GetPriorityTask()){
        if(it.first==currentTime){
            ThreadPool::getInstance()->EnQueueTask(it.second);
        }
    }
    // BatchProcessMutex.unlock();
}
