
#include "task_queue.h"

TaskQueue::TaskQueue() : shutdown_flag(false) {
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
}

TaskQueue::~TaskQueue() {
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}

void TaskQueue::push(Task task) {
    pthread_mutex_lock(&mutex);
    queue.push(task);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

bool TaskQueue::pop(Task &task) {
    pthread_mutex_lock(&mutex);

    while (queue.empty() && !shutdown_flag) {
        pthread_cond_wait(&cond, &mutex);
    }

    if (shutdown_flag && queue.empty()) {
        pthread_mutex_unlock(&mutex);
        return false;
    }

    task = queue.front();
    queue.pop();

    pthread_mutex_unlock(&mutex);
    return true;
}

void TaskQueue::shutdown() {
    pthread_mutex_lock(&mutex);
    shutdown_flag = true;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
}
