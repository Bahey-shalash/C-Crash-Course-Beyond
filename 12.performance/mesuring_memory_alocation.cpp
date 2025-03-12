/*
    Measuring memory allocation in C++: 
    ------------------------------------

    In C++, there is no direct *built-in* function to check the total memory allocation used by a program. However, we can track memory allocation in various ways. This is crucial for optimizing performance and detecting memory leaks (fuites de mémoire).

    Here are some methods to monitor memory allocation in C++:
    
    1. **Overloading the new and delete operators**:
       We can track memory allocations by overriding the global `new` and `delete` operators to log the size of each allocation and deallocation.
    
    2. **Using a memory profiling tool**:
       Tools like Valgrind (Linux), AddressSanitizer (Clang, GCC), or Visual Studio's built-in profiler (Windows) can give detailed reports on memory usage, including peak memory, allocations, and leaks.

    3. **Standard Library Containers**:
       Some STL containers (like `std::vector` or `std::string`) offer methods such as `.capacity()` or `.size()` which give indirect information about their memory usage. 

    4. **Custom tracking with malloc hooks**:
       For lower-level malloc-based allocation tracking (C-style), one can override `malloc`, `calloc`, and `free` to intercept calls and track them.

    Below, I will illustrate the approach of overloading `new` and `delete` operators for tracking heap allocations. This technique will allow us to monitor how much memory has been allocated and deallocated, giving insights into the program's memory footprint.
*/

#include <iostream>
#include <new>    // For overloading new/delete
#include <cstdlib>  // For malloc and free
#include <map>      // For tracking memory blocks

// Global variables to track memory usage
size_t totalMemoryAllocated = 0;
size_t totalMemoryDeallocated = 0;

// A map to track the size of each allocated block
std::map<void*, size_t> allocationMap;

// Overloading the global 'new' operator
void* operator new(size_t size) {
    void* ptr = malloc(size); // Allocate memory using malloc

    if (!ptr) {
        throw std::bad_alloc(); // Throw exception if malloc fails
    }

    // Record the allocation
    totalMemoryAllocated += size;
    allocationMap[ptr] = size;

    std::cout << "[Alloc] Address: " << ptr << ", Size: " << size << " bytes\n";
    return ptr;
}

// Overloading the global 'delete' operator
void operator delete(void* ptr) noexcept {
    if (ptr) {
        // Find the size of the allocation
        auto it = allocationMap.find(ptr);
        if (it != allocationMap.end()) {
            totalMemoryDeallocated += it->second;

            std::cout << "[Free] Address: " << ptr << ", Size: " << it->second << " bytes\n";

            allocationMap.erase(it); // Remove the block from tracking map
        }
        free(ptr); // Free the memory
    }
}

int main() {
    // Example of tracking allocations
    int* arr = new int[10];  // Allocate an array of 10 ints (40 bytes on most systems)
    delete[] arr;            // Free the memory

    double* d = new double;  // Allocate one double (8 bytes on most systems)
    delete d;                // Free the memory

    // Report memory usage
    std::cout << "\nTotal memory allocated: " << totalMemoryAllocated << " bytes\n";
    std::cout << "Total memory deallocated: " << totalMemoryDeallocated << " bytes\n";
    std::cout << "Current memory in use: " << (totalMemoryAllocated - totalMemoryDeallocated) << " bytes\n";

    return 0;
}