/* 
Class 1: Introduction to Pointers
---------------------------------
In this class, we will explore:
1. Memory addresses and how to access them.
2. Pointer declaration, initialization, and usage.
3. The concept of `nullptr` and the importance of pointer initialization.

Pointers are variables that store memory addresses. They are a powerful feature of C++ that allow us to directly manipulate memory, enabling low-level programming and efficient resource management.

Key terms:
- Address of operator (&): Retrieves the memory address of a variable.
- Dereference operator (*): Accesses the value at a pointer's address.
- nullptr: A special value indicating that a pointer does not point to any valid memory.

*/

#include <iostream>
using namespace std;

int main() {
    // Step 1: Declaring and Initializing Pointers
    int x = 42; // A simple integer variable
    int* ptr = &x; // Pointer to x, stores the memory address of x

    cout << "Value of x: " << x << endl; // Outputs 42
    cout << "Address of x (&x): " << &x << endl; // Outputs the address of x
    cout << "Value of ptr (address it points to): " << ptr << endl; // Same as &x
    cout << "Value pointed to by ptr (*ptr): " << *ptr << endl; // Dereferencing pointer to get the value of x

    // Step 2: Working with nullptr
    int* nullPtr = nullptr; // A pointer initialized to nullptr
    if (nullPtr == nullptr) {
        cout << "nullPtr is null and does not point to any valid memory." << endl;
    }

    // Step 3: Changing Pointer Values
    int y = 99;
    ptr = &y; // Now ptr points to y
    cout << "Value of y: " << y << endl; // Outputs 99
    cout << "Value pointed to by ptr (*ptr): " << *ptr << endl; // Outputs the value of y

    // Step 4: Avoiding Undefined Behavior
    int* uninitializedPtr; // This pointer is not initialized
    // cout << *uninitializedPtr; // Accessing this pointer would lead to undefined behavior
    uninitializedPtr = nullptr; // Always initialize pointers

    return 0;
}