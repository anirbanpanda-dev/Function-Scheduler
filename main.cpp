/**
 * Tasks : workFunctor , callbackFunctor , errorData
 * Status : enum
 * SchedulerService 
 * WorkerPool : WorkQueue
 * ExecutorService : 
*/

#include <iostream>
#include "SchedulerService.h"
#include "ExecutorService.h"

void testSchedule(){
    SchedulerService::getInstance()->Schedule([&](){
        cout << "Hello World ";
        auto now = chrono::high_resolution_clock::now();
        auto t = now.time_since_epoch();
        cout << t.count()/1e9 << endl;
        sleep(2);
    }, 1);
}

void test0(){
    for(int i = 0; i<4; i++){
        testSchedule();
    }
}

void test1(){
    std::vector<std::thread> threads;
    for(int i = 0; i<4; i++){
        threads.emplace_back(testSchedule);
    }

    for(int i = 0; i<4; i++){
        threads[i].join();
    }

}


int main(){
    ExecutorService::getInstance()->run();
    test1();
    sleep(120);
}



