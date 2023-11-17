#pragma once

#include <iostream>
#include <unistd.h>
#include "Common.h"
#include <chrono>

using namespace std;

class Task{
    std::function<void()> _taskFunctor;
    int taskInterval;
    Status taskStatus;
    time_t startTime;
    public : 
    Task(std::function<void()> taskFunctor, int interval);
    int GetInterval();
    std::function<void()> GetExecutor();
    void setStatus(Status status);
    time_t getstartTime();
};

