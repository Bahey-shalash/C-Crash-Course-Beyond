/*
    ### C++ Course: C-Style Arrays

    C-style arrays are fixed-size sequences of elements stored contiguously in memory.
    They are allocated on the stack or statically in the data segment if declared
   globally.

    Topics Covered:
    1. Declaration and Initialization
    2. Memory Layout and Stack Allocation
    3. Common Pitfalls and Limitations
*/

#include <iostream>
using namespace std;

int main() {
    // 1. Declaration and Initialization
    int numbers[5] = {1, 2, 3, 4, 5};  // Declaration of a C-style array

    // Accessing elements
    cout << "C-Style Array elements: ";
    for (int i = 0; i < 5; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // 2. Memory Layout and Stack Allocation
    /*
        C-style arrays are stored contiguously in memory, with each element adjacent to
       the next.
        - Since `numbers` is declared inside `main`, it is allocated on the stack.
        - Stack memory is fast but limited in size, so large arrays can cause stack
       overflow.
    */
    cout << "Memory address of `numbers`: " << numbers << endl;
    cout << "Memory address of `numbers[0]`: " << &numbers[0] << endl;
    cout << "Memory address of `numbers[1]`: " << &numbers[1] << endl;

    // 3. Common Pitfalls and Limitations
    /*
        - Fixed Size: The size of a C-style array must be known at compile time and
       cannot be changed.
        - No Bounds Checking: Accessing elements outside the array size (e.g.,
       `numbers[5]`) causes undefined behavior.
        - Lack of Size Information: `sizeof(numbers)` only provides the size in bytes,
       not the number of elements.
    */
    cout << "Size of `numbers` array (bytes): " << sizeof(numbers) << endl;

    return 0;
}

/*
    Compile and run:
        g++ c_arrays.cpp -o c_arrays
        ./c_arrays
*/