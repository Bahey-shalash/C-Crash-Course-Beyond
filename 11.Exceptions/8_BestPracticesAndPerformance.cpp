/*
File: 8_BestPracticesAndPerformance.cpp
Description: Demonstrates best practices in exception handling and performance considerations.
It shows catching exceptions by reference and using RAII to ensure proper resource management.
*/

#include <iostream>
#include <stdexcept>

// A simple RAII class to simulate a managed resource.
class ManagedResource {
public:
    ManagedResource() {
        std::cout << "ManagedResource acquired." << std::endl;
    }
    ~ManagedResource() {
        std::cout << "ManagedResource released." << std::endl;
    }
};

// Function that performs an operation and may trigger an error.
void performOperation(bool triggerError) {
    ManagedResource resource;  // RAII ensures cleanup.
    std::cout << "Performing operation..." << std::endl;
    if (triggerError) {
        throw std::runtime_error("Operation failed due to an unexpected error.");
    }
    std::cout << "Operation completed successfully." << std::endl;
}

int main() {
    std::cout << "=== Lesson 8: Best Practices and Performance Considerations ===" << std::endl;
    
    // Example 1: Operation completes without error.
    try {
        std::cout << "\nExample 1: Operation without error." << std::endl;
        performOperation(false);
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    // Example 2: Operation triggers an error.
    try {
        std::cout << "\nExample 2: Operation with error triggered." << std::endl;
        performOperation(true);
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    // Note on best practices:
    // - Catch exceptions by reference to prevent object slicing.
    // - Use exceptions only for truly exceptional situations.
    // - Keep try blocks minimal to isolate error-prone code.
    
    return 0;
}