
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <pthread.h>
#include "task_queue.h"

class Scheduler {
private:
    int thread_count;
    std::vector<pthread_t> workers;
    TaskQueue taskQueue;

    static void* worker(void* arg);

public:
    Scheduler(int threads);
    ~Scheduler();

    void submit(Task task);
    void shutdown();
};

#endif
