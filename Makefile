
CXX = g++
CXXFLAGS = -Wall -pthread

all:
	$(CXX) main.cpp scheduler.cpp task_queue.cpp -o scheduler $(CXXFLAGS)

clean:
	rm -f scheduler
