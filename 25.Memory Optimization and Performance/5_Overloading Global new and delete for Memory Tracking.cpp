/* ==========================================================================
Lesson 5: Overloading Global new and delete for Memory Tracking

Theory:
---------
You can overload the global new and delete operators to track dynamic memory
allocations. This can help you detect memory leaks and analyze memory usage.

Key Points:
- Maintain a global counter and mapping of allocations.
- Ensure thread safety in production code (this example is simplified).
- Edge Cases: Overloading new/delete for arrays (use delete[] for new[]).

Example:
---------
Overload new and delete to log allocations and deallocations.
========================================================================== */

#include <cstdlib>  // For malloc/free
#include <iostream>
#include <map>
#include <new>  // For std::bad_alloc
using namespace std;

size_t totalAllocated = 0;
size_t totalDeallocated = 0;
std::map<void*, size_t> allocationMap;

void* operator new(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        throw std::bad_alloc();
    }
    totalAllocated += size;
    allocationMap[ptr] = size;
    cout << "[Alloc] Address: " << ptr << ", Size: " << size << " bytes\n";
    return ptr;
}

void operator delete(void* ptr) noexcept {
    if (ptr) {
        auto it = allocationMap.find(ptr);
        if (it != allocationMap.end()) {
            totalDeallocated += it->second;
            cout << "[Free] Address: " << ptr << ", Size: " << it->second
                 << " bytes\n";
            allocationMap.erase(it);
        }
        free(ptr);
    }
}

int main() {
    int* arr = new int[10];  // Allocate array
    delete[] arr;            // Free array (calls overloaded delete)

    double* d = new double;
    delete d;

    cout << "\nTotal allocated: " << totalAllocated << " bytes\n";
    cout << "Total deallocated: " << totalDeallocated << " bytes\n";
    cout << "Net memory in use: " << (totalAllocated - totalDeallocated) << " bytes\n";
    return 0;
}