/*
Class 7: Pointers and Dynamic Memory
------------------------------------
In this class, we will explore:
1. Using `new` and `delete` for dynamic memory allocation.
2. Preventing memory leaks by proper resource management.
3. Introduction to smart pointers (C++11 and beyond).
4. Real-world scenarios where dynamic memory is crucial.

Key concepts:
- `new` allocates memory dynamically and returns a pointer.
- `delete` frees the memory allocated by `new`.
- Dynamic memory allows flexible program behavior but requires careful management.
- Smart pointers provide automatic memory management, reducing the risk of leaks.

*/

#include <iostream>
#include <memory> // For smart pointers
using namespace std;

// Step 1: Dynamic Allocation of a Single Variable
void singleDynamicVariable() {
    int* ptr = new int(42); // Allocate memory and initialize to 42
    cout << "Dynamically allocated integer: " << *ptr << endl;

    // Free memory
    delete ptr;
}

// Step 2: Dynamic Allocation of Arrays
void dynamicArray() {
    int size = 5;
    int* arr = new int[size]; // Allocate an array of 5 integers

    // Assign values
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;
    }

    // Print values
    cout << "Dynamically allocated array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free memory
    delete[] arr;
}

// Step 3: Preventing Memory Leaks
void memoryLeakExample() {
    int* ptr = new int(99); // Dynamically allocated memory
    cout << "Value allocated: " << *ptr << endl;

    // Forgetting to free memory results in a memory leak
    delete ptr;
}

// Step 4: Using Smart Pointers (C++11 and Beyond)
void smartPointerExample() {
    unique_ptr<int> uPtr = make_unique<int>(88); // Unique ownership
    cout << "Value managed by unique_ptr: " << *uPtr << endl;

    shared_ptr<int> sPtr1 = make_shared<int>(77); // Shared ownership
    shared_ptr<int> sPtr2 = sPtr1; // sPtr1 and sPtr2 share ownership
    cout << "Value managed by shared_ptr: " << *sPtr1 << " (shared by two)" << endl;
}

int main() {
    // Step 1: Single Variable Allocation
    cout << "Dynamic memory allocation for a single variable:" << endl;
    singleDynamicVariable();

    // Step 2: Dynamic Array Allocation
    cout << "\nDynamic memory allocation for arrays:" << endl;
    dynamicArray();

    // Step 3: Memory Leaks
    cout << "\nDemonstrating memory leaks:" << endl;
    memoryLeakExample();

    // Step 4: Smart Pointers
    cout << "\nSmart pointers (modern C++):" << endl;
    smartPointerExample();

    return 0;
}