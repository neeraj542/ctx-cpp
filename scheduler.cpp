
#include "scheduler.h"
#include <unistd.h>
#include <iostream>

Scheduler::Scheduler(int threads) : thread_count(threads) {
    workers.resize(thread_count);

    for (int i = 0; i < thread_count; i++) {
        pthread_create(&workers[i], NULL, worker, &taskQueue);
    }
}

void* Scheduler::worker(void* arg) {
    TaskQueue* queue = static_cast<TaskQueue*>(arg);
    Task task(0,0,0);

    while (queue->pop(task)) {
        std::cout << "Executing Task " << task.id << std::endl;
        usleep(task.execution_time * 1000);
    }

    pthread_exit(NULL);
}

void Scheduler::submit(Task task) {
    taskQueue.push(task);
}

void Scheduler::shutdown() {
    taskQueue.shutdown();

    for (int i = 0; i < thread_count; i++) {
        pthread_join(workers[i], NULL);
    }
}
