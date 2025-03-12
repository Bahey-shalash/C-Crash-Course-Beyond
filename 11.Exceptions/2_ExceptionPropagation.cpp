/*
File: 2_ExceptionPropagation.cpp
Description: Demonstrates how exceptions propagate through multiple function calls.
*/

#include <iostream>
#include <stdexcept>

// A helper function that directly throws an exception.
void innerFunction() {
    std::cout << "Inside innerFunction, about to throw an exception." << std::endl;
    throw std::runtime_error("Error thrown in innerFunction");
}

// A middle function that calls innerFunction.
void middleFunction() {
    std::cout << "Inside middleFunction, calling innerFunction." << std::endl;
    innerFunction();  // Exception propagates from here.
}

int main() {
    std::cout << "=== Lesson 2: Exception Propagation ===" << std::endl;
    try {
        std::cout << "Calling middleFunction from main." << std::endl;
        middleFunction();
    } catch (const std::exception& e) {
        std::cout << "Caught exception in main: " << e.what() << std::endl;
    }
    return 0;
}