/* ==========================================================================
Lesson 1: Basic Exception Handling

Theory:
---------
Exception handling in C++ uses try, catch, and throw to manage error conditions.
Exceptions allow programs to handle errors gracefully without crashing.

Key Points:
- Use try blocks to enclose code that may throw exceptions.
- Use catch blocks to handle specific exceptions.
- Use throw to signal an error.
- Edge Cases: Catching by value vs. by reference.

Example:
---------
A simple function that throws an exception if a division by zero is attempted.
========================================================================== */

#include <iostream>
#include <stdexcept>
using namespace std;

double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw std::runtime_error("Division by zero error!");
    }
    return numerator / denominator;
}

int main() {
    try {
        cout << "Result: " << divide(10, 0) << endl;
    } catch (const std::exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }
    return 0;
}