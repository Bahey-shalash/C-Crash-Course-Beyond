/*
File: 7_StandardLibraryExceptions.cpp
Description: Demonstrates handling of standard library exceptions such as std::bad_alloc.
*/

#include <iostream>
#include <new>      // For std::bad_alloc
#include <vector>

int main() {
    std::cout << "=== Lesson 7: Standard Library Exceptions ===" << std::endl;
    
    // Example 1: Attempt to allocate a huge vector to simulate memory allocation failure.
    try {
        std::cout << "Attempting to allocate a huge vector..." << std::endl;
        std::vector<int> hugeVector;
        // Reserving an extremely large amount of memory may trigger a bad_alloc.
        hugeVector.reserve(100000000000ULL);
    } catch (const std::bad_alloc& e) {
        std::cout << "Caught std::bad_alloc: " << e.what() << std::endl;
    }
    
    // Example 2: Manually throwing std::bad_alloc.
    try {
        std::cout << "\nManually throwing std::bad_alloc..." << std::endl;
        throw std::bad_alloc();
    } catch (const std::bad_alloc& e) {
        std::cout << "Caught std::bad_alloc: " << e.what() << std::endl;
    }
    
    return 0;
}