
#include "scheduler.h"
#include <iostream>

int main() {
    Scheduler scheduler(4);

    for (int i = 1; i <= 10; i++) {
        scheduler.submit(Task(i, 500, 1));
    }

    sleep(3);

    scheduler.shutdown();
    return 0;
}
