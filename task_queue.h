
#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

#include <queue>
#include <pthread.h>
#include "task.h"

class TaskQueue {
private:
    std::queue<Task> queue;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    bool shutdown_flag;

public:
    TaskQueue();
    ~TaskQueue();

    void push(Task task);
    bool pop(Task &task);
    void shutdown();
};

#endif
