/* ==========================================================================
Lesson 2: Futures, Promises, and std::async

Theory:
---------
Futures and promises provide a way to retrieve results from asynchronous operations.
std::async simplifies launching asynchronous tasks.

Key Points:
- std::async launches a task asynchronously and returns a std::future.
- std::promise can be used to set a value that a std::future will later retrieve.
- Edge Cases: Proper error propagation and exception handling in asynchronous code.

Example:
---------
Using std::async to compute a value asynchronously.
========================================================================== */

#include <iostream>
#include <future>
#include <chrono>
using namespace std;

int slowComputation() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    return 42;
}

int main() {
    // Launch asynchronous task.
    future<int> result = async(slowComputation);

    cout << "Doing other work..." << endl;

    // Retrieve result (waits if not ready).
    cout << "Result from async computation: " << result.get() << endl;

    return 0;
}