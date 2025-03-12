/*
File: 4_ExceptionSpecifications.cpp
Description: Demonstrates the use of exception specifications in C++.
This version is updated for C++17 and later, using noexcept.
*/

#include <iostream>
#include <stdexcept>

// functionNoThrow is declared noexcept, guaranteeing that it will not throw any exceptions.
void functionNoThrow() noexcept {
    std::cout << "Inside functionNoThrow: No exceptions will be thrown." << std::endl;
}

// functionMayThrow is declared with noexcept(false) to explicitly indicate that it may throw exceptions.
// Note: By default, functions are noexcept(false), so this is primarily for clarity.
void functionMayThrow() noexcept(false) {
    std::cout << "Inside functionMayThrow: About to throw std::runtime_error." << std::endl;
    throw std::runtime_error("Error thrown by functionMayThrow");
}

int main() {
    std::cout << "=== Lesson 4: Exception Specifications ===" << std::endl;
    
    // Example using noexcept.
    try {
        functionNoThrow();
    } catch (...) {
        std::cout << "Exception caught from functionNoThrow (unexpected)." << std::endl;
    }
    
    // Example using a function that may throw exceptions.
    try {
        functionMayThrow();
    } catch (const std::runtime_error& e) {
        std::cout << "Caught std::runtime_error: " << e.what() << std::endl;
    }
    
    return 0;
}