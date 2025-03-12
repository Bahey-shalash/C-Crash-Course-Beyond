/*
Class 5: Void Pointers
----------------------
In this class, we will explore:
1. Definition and use of `void*` (void pointers).
2. Type casting with `void*`.
3. Practical use cases of `void*`.

Key concepts:
- A `void*` pointer is a generic pointer that can hold the address of any data type.
- It cannot be dereferenced directly; you must cast it to the appropriate type.
- Useful in scenarios like memory management and generic data handling (e.g., in
libraries like malloc).

*/

#include <cstring>  // For memcpy
#include <iostream>
using namespace std;

int main() {
    // Step 1: Declaring and Using a Void Pointer
    int a = 10;
    float b = 20.5f;
    /* the f at the end tells the compiler to treat 20.5 as a float rather
             than a double. Without the "f" suffix, 20.5 would be a double. */
    char c = 'Z';

    void* ptr = nullptr;  // A void pointer
    ptr = &a;             // Store address of an int
    cout << "Void pointer pointing to an int: " << *(static_cast<int*>(ptr)) << endl;

    ptr = &b;  // Store address of a float
    cout << "Void pointer pointing to a float: " << *(static_cast<float*>(ptr))
         << endl;

    ptr = &c;  // Store address of a char
    cout << "Void pointer pointing to a char: " << *(static_cast<char*>(ptr)) << endl;

    // Step 2: Memory Management with Void Pointers
    cout << "\nMemory allocation using malloc and void pointer:" << endl;
    void* buffer = malloc(10 * sizeof(int));  // Allocate memory for 10 integers
    if (buffer == nullptr) {
        cerr << "Memory allocation failed!" << endl;
        return 1;
    }

    // Store data in the allocated memory
    int* intArray = static_cast<int*>(buffer);
    for (int i = 0; i < 10; i++) {
        intArray[i] = i + 1;  // Fill with values 1 to 10
    }

    // Access the data
    cout << "Values in dynamically allocated memory:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    // Free the allocated memory
    free(buffer);

    // Step 3: Generic Data Copy with Void Pointer
    int source = 42;
    int destination;
    void* srcPtr = &source;
    void* destPtr = &destination;

    // Use memcpy to copy data
    memcpy(destPtr, srcPtr, sizeof(int));
    cout << "\nCopied value using memcpy: " << destination << endl;

    return 0;
}