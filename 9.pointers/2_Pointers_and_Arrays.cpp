/*
Class 2: Pointers and Arrays
----------------------------
In this class, we will explore:
1. Using pointers to access array elements.
2. Pointer arithmetic and how it relates to arrays.
3. Differences between C-style arrays and pointers.

Key concepts:
- Arrays are contiguous blocks of memory.
- The name of an array is a pointer to its first element.
- Pointer arithmetic enables traversal of arrays efficiently.

*/

#include <iostream>
using namespace std;

int main() {
    // Step 1: Understanding the Relationship Between Arrays and Pointers
    int arr[5] = {10, 20, 30, 40, 50};

    // The name of the array (arr) is a pointer to the first element
    cout << "Address of the first element (arr): " << arr << endl;
    cout << "Address of the first element (&arr[0]): " << &arr[0] << endl;

    // Accessing elements using the array syntax
    cout << "First element (arr[0]): " << arr[0] << endl;

    // Accessing elements using pointers
    cout << "First element (*arr): " << *arr
         << endl;  // Dereferencing the pointer to the first element
    cout << "Second element (*(arr + 1)): " << *(arr + 1) << endl;

    // Step 2: Pointer Arithmetic
    int* ptr = arr;  // A pointer to the first element of the array
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << " (using pointer arithmetic): " << *(ptr + i)
             << endl;
    }

    // Step 3: Difference Between Array Name and Pointer
    cout << "Size of arr (array): " << sizeof(arr) << " bytes"
         << endl;  // Size of the entire array
    cout << "Size of ptr (pointer): " << sizeof(ptr) << " bytes"
         << endl;  // Size of a pointer (usually 8 bytes on 64-bit systems)

    // Step 4: Arrays as Function Arguments
    // When passing arrays to functions, they are treated as pointers
    cout << "Sum of elements (using pointer): " <<
        [](int* p, int size) {
            int sum = 0;
            for (int i = 0; i < size; i++) {
                sum += *(p + i);  // Using pointer arithmetic
            }
            return sum;
        }(arr, 5)
         << endl;

    return 0;
}