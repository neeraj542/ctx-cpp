
#ifndef TASK_H
#define TASK_H

#include <functional>

struct Task {
    int id;
    int execution_time; // milliseconds
    int priority;

    Task(int id_, int exec_time_, int priority_)
        : id(id_), execution_time(exec_time_), priority(priority_) {}
};

#endif
