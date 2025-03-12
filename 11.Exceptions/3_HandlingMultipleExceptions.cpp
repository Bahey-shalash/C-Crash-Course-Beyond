/*
File: 3_HandlingMultipleExceptions.cpp
Description: Demonstrates how to handle multiple types of exceptions using multiple catch blocks.
*/

#include <iostream>
#include <stdexcept>

// Function to test different exceptions based on the provided type.
void testMultipleExceptions(int type) {
    if (type == 1) {
        throw std::runtime_error("Runtime error occurred.");
    } else if (type == 2) {
        throw std::logic_error("Logic error occurred.");
    } else {
        // Throw a C-style string exception.
        throw "Unknown error occurred.";
    }
}

int main() {
    std::cout << "=== Lesson 3: Handling Multiple Exceptions ===" << std::endl;
    
    // Test for type 1 (std::runtime_error)
    try {
        std::cout << "\nTesting type 1 exception:" << std::endl;
        testMultipleExceptions(1);
    } catch (const std::runtime_error& e) {
        std::cout << "Caught runtime_error: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception." << std::endl;
    }
    
    // Test for type 2 (std::logic_error)
    try {
        std::cout << "\nTesting type 2 exception:" << std::endl;
        testMultipleExceptions(2);
    } catch (const std::logic_error& e) {
        std::cout << "Caught logic_error: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception." << std::endl;
    }
    
    // Test for type 3 (C-style exception)
    try {
        std::cout << "\nTesting type 3 exception:" << std::endl;
        testMultipleExceptions(3);
    } catch (const std::exception& e) {
        // This block won't catch a C-style string exception.
        std::cout << "Caught exception: " << e.what() << std::endl;
    } catch (const char* e) {
        std::cout << "Caught C-string exception: " << e << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception." << std::endl;
    }
    
    return 0;
}