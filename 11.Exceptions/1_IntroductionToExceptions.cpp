/*
File: 1_IntroductionToExceptions.cpp
Description: Demonstrates the basics of exception handling in C++.
It shows how to use try, throw, and catch with multiple examples.
*/

#include <iostream>
#include <stdexcept>

// Example 1: Basic try-catch mechanism.
void basicExample() {
    std::cout << "Example 1: Basic try-catch" << std::endl;
    try {
        // Throw a standard runtime_error.
        throw std::runtime_error("Error in basicExample");
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

// Example 2: Multiple throw scenarios in one try block.
void multipleThrowsExample() {
    std::cout << "\nExample 2: Multiple throws within the same try block" << std::endl;
    try {
        int x = 0;
        if (x == 0) {
            throw std::runtime_error("x is zero!");
        }
        // The following line will not be executed.
        throw std::logic_error("This error will not be thrown.");
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "=== Lesson 1: Introduction to Exceptions ===" << std::endl;
    basicExample();
    multipleThrowsExample();
    return 0;
}