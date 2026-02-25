# Concurrent Task Scheduler (C++ & POSIX Threads)

A concurrent task scheduler implemented in C++ using POSIX threads (pthreads) in a Linux environment.
The project demonstrates low-level concurrency control, thread synchronization, and OS scheduling concepts through a thread-safe task execution framework.

This implementation focuses on correctness, synchronization safety, and experimental performance evaluation under concurrent workloads.

---

## Overview

The scheduler implements a producer–consumer architecture:

* Tasks are submitted to a shared task queue.
* Worker threads fetch tasks concurrently.
* Synchronization is enforced using POSIX mutexes and condition variables.
* The system avoids busy waiting and ensures safe shutdown semantics.

The design emphasizes deterministic behavior under concurrent access and prevention of race conditions and deadlocks.

---

## Architecture

Core components:

* `Task` – Represents a unit of work with execution time and priority metadata.
* `TaskQueue` – Thread-safe queue protected by `pthread_mutex_t` and `pthread_cond_t`.
* `Scheduler` – Manages worker threads and dispatches tasks.
* Worker Threads – Execute tasks using blocking synchronization.

Concurrency model:

* Producer threads submit tasks.
* Consumer worker threads block on condition variables when the queue is empty.
* Graceful shutdown is implemented via broadcast signaling.

---

## Key Concepts Applied

* POSIX Threads (pthreads)
* Mutex-based mutual exclusion
* Condition variables for blocking synchronization
* Producer–Consumer problem
* Deadlock avoidance through disciplined locking
* Thread lifecycle management (create, join, shutdown)
* Performance benchmarking using controlled workload simulation

---

## Build Requirements

* Linux environment (Ubuntu or equivalent recommended)
* g++ (GCC 9+ recommended)
* POSIX threads library (typically available by default)

Verify installation:

```
g++ --version
```

---

## Installation and Build

Clone the repository:

```
git clone https://github.com/neeraj542/ctx-cpp.git
cd ctx-cpp
```

Build using Make:

```
make
```

This generates the executable:

```
scheduler
```

If building manually:

```
g++ main.cpp scheduler.cpp task_queue.cpp -o scheduler -Wall -pthread
```

---

## Running the Scheduler

Execute:

```
./scheduler
```

The program will:

1. Create a fixed-size worker thread pool.
2. Submit tasks to the queue.
3. Execute tasks concurrently.
4. Shutdown gracefully after completion.

---

## Experimental Evaluation

The scheduler can be tested under varying:

* Thread pool sizes
* Task submission rates
* Execution durations
* Queue load intensity

To benchmark:

* Increase number of submitted tasks.
* Reduce execution time to simulate high-throughput workload.
* Increase worker threads to observe scalability limits.

Metrics to observe:

* Throughput (tasks per second)
* Latency (time to completion)
* CPU utilization
* Thread contention behavior

For precise measurement, integrate `clock_gettime()` or `std::chrono` for timestamp analysis.

---

## Design Considerations

* Blocking synchronization is used instead of busy-waiting.
* Condition variables prevent unnecessary CPU usage.
* Shutdown mechanism prevents dangling threads.
* Mutex locking is scoped carefully to minimize contention.

The implementation prioritizes clarity and correctness over micro-optimizations.

---

## Possible Extensions

* Priority-based scheduling using priority queues
* Round-robin scheduling with time slicing
* Dynamic thread pool resizing
* Lock-free queue implementation
* Work stealing architecture
* Detailed latency profiling

---

## License

This project is intended for academic and experimental systems programming exploration.
