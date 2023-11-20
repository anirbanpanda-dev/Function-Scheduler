
cmake_minimum_required(VERSION 3.12)
project(FunctionScheduler)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FunctionScheduler 
                main.cpp 
                SchedulerService.cpp 
                ExecutorService.cpp 
                Task.cpp 
                TaskCache.cpp 
                ThreadPool.cpp)