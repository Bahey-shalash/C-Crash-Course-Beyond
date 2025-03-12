/*
Class 6: Double Pointers (Pointers to Pointers)
----------------------------------------------
In this class, we will explore:
1. Definition and use of double pointers (`int**`).
2. Dynamic allocation of multidimensional arrays using double pointers.
3. Use cases for double pointers (e.g., modifying pointers in functions).

Key concepts:
- A double pointer stores the address of another pointer, effectively creating a "pointer to pointer."
- Useful for dynamic 2D arrays, managing complex data structures, and modifying pointers in functions.

*/

#include <iostream>
using namespace std;

// Function to demonstrate modifying a pointer using a double pointer
void modifyPointer(int** pptr) {
    static int value = 42; // Static to ensure it persists outside the function
    *pptr = &value; // Modify the pointer to point to value
}

// Function to dynamically allocate a 2D array
int** create2DArray(int rows, int cols) {
    int** array = new int*[rows]; // Array of int pointers
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols]; // Each pointer points to an array of ints
    }
    return array;
}

void delete2DArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i]; // Delete each row
    }
    delete[] array; // Delete the array of pointers
}

int main() {
    // Step 1: Basic Double Pointer
    int x = 10;
    int* ptr = &x; // Single pointer to x
    int** pptr = &ptr; // Double pointer to ptr

    cout << "Value of x: " << x << endl;
    cout << "Value of ptr (*pptr): " << *pptr << endl; // Accessing ptr
    cout << "Value pointed to by ptr (**pptr): " << **pptr << endl; // Accessing x through pptr

    // Step 2: Modifying a Pointer in a Function
    cout << "\nBefore modifying, ptr points to: " << ptr << endl;
    modifyPointer(&ptr); // Pass address of ptr (a double pointer is needed)
    cout << "After modifying, ptr points to value: " << *ptr << endl;

    // Step 3: Dynamic Allocation of a 2D Array
    cout << "\nDynamic 2D array:" << endl;
    int rows = 3, cols = 4;
    int** array = create2DArray(rows, cols);

    // Fill the array with values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * cols + j + 1; // Sequential numbers
        }
    }

    // Print the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Clean up memory
    delete2DArray(array, rows);

    return 0;
}