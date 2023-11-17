#pragma once

#define MAX_THREADS_PER_MINUTE 2
#define MINUTE 60

enum class Status{
    IDLE = -1,
    CACHED,
    QUEUED,
    RUNNING,
    SUCCESS,
    ERROR
};