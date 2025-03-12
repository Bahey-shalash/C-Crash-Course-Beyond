/* ==========================================================================
Lesson 1: Basic Multithreading with std::thread

Theory:
---------
C++11 introduced the <thread> library, allowing you to write multithreaded applications.
A thread represents an independent unit of execution.

Key Points:
- Create threads by instantiating std::thread.
- Use join() to wait for thread completion.
- Use mutexes (std::mutex) to protect shared data.
- Edge Cases: Data races, deadlocks, and proper synchronization.

Example:
---------
Creating a simple multithreaded program that prints messages from different threads.
========================================================================== */

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex coutMutex;

void printMessage(const string& message, int id) {
    // Lock mutex to protect std::cout access.
    lock_guard<mutex> lock(coutMutex);
    cout << "Thread " << id << ": " << message << endl;
}

int main() {
    thread t1(printMessage, "Hello from thread 1", 1);
    thread t2(printMessage, "Hello from thread 2", 2);

    // Wait for threads to finish.
    t1.join();
    t2.join();

    return 0;
}