#include "ThreadPool.h"

ThreadPool* ThreadPool::pool = NULL;

ThreadPool::ThreadPool(){
    poolSize = MAX_THREADS_PER_MINUTE;
    runThreads();
}

void ThreadPool::runThreads(){
    for(int i = 0; i<4; i++){
        threadList.emplace_back([this](){
            std::function<void()> workFunctor;
            while(true){
                std::unique_lock<std::mutex> lck(poolMutex);
                cond_var.wait(lck, [this](){return !taskQueue.empty();});

                std::function<void()> workFunctor = taskQueue.front();
                taskQueue.pop();
                workFunctor();

            }

        });
    }
}

ThreadPool* ThreadPool::getInstance(){
    if(!pool){
        pool = new ThreadPool();
    }
    return pool;
}

void ThreadPool::EnQueueTask(Task* task){
    std::cout << " ThreadPool::EnQueueTask \n";
    // PoolEnqueueMutex.lock();
    taskQueue.push(task->GetExecutor());
    task->setStatus(Status::QUEUED);
    cond_var.notify_all();
    // PoolEnqueueMutex.unlock();


}