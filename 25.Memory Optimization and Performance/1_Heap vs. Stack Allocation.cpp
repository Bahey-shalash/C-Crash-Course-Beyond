/* ==========================================================================
Lesson 1: Heap vs. Stack Allocation

Theory:
---------
Memory in C++ is divided mainly into two regions:
- The stack: used for static (local) allocations with automatic lifetime.
- The heap: used for dynamic allocations with manual management.

Key Points:
- Stack allocation is fast but limited in size.
- Heap allocation is more flexible but slower and must be managed manually.
- Edge Cases: Stack overflow with deep recursion; memory leaks if heap memory is not
freed.

Example:
---------
Comparing stack allocation (for simple variables and arrays) and heap allocation.
========================================================================== */

#include <iostream>
using namespace std;

int main() {
    // Stack allocation:
    int a = 10;
    cout << "Stack variable a = " << a << endl;

    // Heap allocation:
    int* b = new int(20);
    cout << "Heap variable *b = " << *b << endl;
    delete b;  // Manual deallocation

    // Stack-based array:
    int stackArray[5] = {1, 2, 3, 4, 5};
    cout << "Stack array: ";
    for (int i = 0; i < 5; ++i) {
        cout << stackArray[i] << " ";
    }
    cout << endl;

    // Heap-based array:
    int size = 5;
    int* heapArray = new int[size];
    for (int i = 0; i < size; ++i) {
        heapArray[i] = i * 2;
    }
    cout << "Heap array: ";
    for (int i = 0; i < size; ++i) {
        cout << heapArray[i] << " ";
    }
    cout << endl;
    delete[] heapArray;  // Use delete[] for arrays

    return 0;
}