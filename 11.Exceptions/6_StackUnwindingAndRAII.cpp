/*
File: 6_StackUnwindingAndRAII.cpp
Description: Demonstrates stack unwinding and the RAII (Resource Acquisition Is Initialization) pattern.
*/

#include <iostream>
#include <stdexcept>

// A simple class demonstrating RAII. The constructor acquires a resource and the destructor releases it.
class Resource {
public:
    Resource() {
        std::cout << "Resource acquired." << std::endl;
    }
    ~Resource() {
        std::cout << "Resource released." << std::endl;
    }
};

// A function that uses a resource and then throws an exception.
void functionUsingResource() {
    Resource res;
    std::cout << "Inside functionUsingResource: Resource is in use." << std::endl;
    // Simulate an error.
    throw std::runtime_error("Error during resource usage");
    // Even though we never explicitly free the resource, the destructor is called.
}

int main() {
    std::cout << "=== Lesson 6: Stack Unwinding and RAII ===" << std::endl;
    
    try {
        functionUsingResource();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    return 0;
}