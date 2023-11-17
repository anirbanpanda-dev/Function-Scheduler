#include "Task.h"

Task::Task(std::function<void()> taskFunctor, int interval): 
    _taskFunctor(taskFunctor),
    taskInterval(interval){
        taskStatus = Status::IDLE;
        auto now = chrono::system_clock::now();
        auto t = chrono::duration_cast<chrono::minutes>(now.time_since_epoch());
        // cout << t.count() << endl;
        startTime = t.count();
        std::cout << "Task Created \n";
}

int Task::GetInterval(){
    return taskInterval;
}

std::function<void()> Task::GetExecutor(){
    return _taskFunctor;
}

void Task::setStatus(Status status){
    taskStatus = status;
}

time_t Task::getstartTime(){
    return startTime;
}