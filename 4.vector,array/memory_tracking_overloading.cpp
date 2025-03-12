/*
    ### C++ Course: Tracking Memory Allocation by Overloading `new` and `delete`

    Overloading the `new` and `delete` operators allows us to track and debug memory allocation.
    This technique is useful for understanding memory usage, especially with dynamic structures like `std::vector`.

    Topics Covered:
    1. Overloading Global `new` and `delete`
    2. Tracking Memory Allocation for Debugging Purposes
*/

#include <iostream>
#include <new>
using namespace std;

// Global counters for tracking memory allocation
size_t allocationCount = 0;
size_t deallocationCount = 0;

// Overload `new` to track memory allocations
void* operator new(size_t size) {
    allocationCount += size;
    cout << "Allocated " << size << " bytes. Total allocated: " << allocationCount << " bytes.\n";
    return malloc(size);
}

// Overload `delete` to track memory deallocations
void operator delete(void* ptr, size_t size) noexcept {
    deallocationCount += size;
    cout << "Deallocated " << size << " bytes. Total deallocated: " << deallocationCount << " bytes.\n";
    free(ptr);
}

int main() {
    // Allocate memory with `new`
    int* dynamicArray = new int[100];
    delete[] dynamicArray;  // Deallocate memory

    return 0;
}

/*
    Compile and run:
        g++ memory_tracking_overloading.cpp -o memory_tracking_overloading
        ./memory_tracking_overloading
*/