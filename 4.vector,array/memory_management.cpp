/*
    ### C++ Course: Memory Management (Stack vs. Heap)

    Stack and heap are the two main memory areas used in C++. Understanding their
   differences is crucial for choosing the right data structure and managing memory
   effectively.

    Topics Covered:
    1. Stack Memory
    2. Heap Memory
    3. Choosing Between Stack and Heap
*/

#include <iostream>
using namespace std;

void stackExample() {
    int localVariable = 10;  // Allocated on the stack
    cout << "Stack variable address: " << &localVariable << endl;
}

void heapExample() {
    int* heapVariable = new int(10);  // Allocated on the heap
    cout << "Heap variable address: " << heapVariable << endl;
    delete heapVariable;  // Free memory
}

int main() {
    // Stack Example
    stackExample();

    // Heap Example
    heapExample();

    /*
        Stack Memory:
        - Fast access with limited size.
        - Used for local variables and function calls.

        Heap Memory:
        - Larger and used for dynamic memory allocation (`new`).
        - Slower access and requires manual management with `delete`.
    */

    return 0;
}

/*
    Compile and run:
        g++ memory_management.cpp -o memory_management
        ./memory_management
*/