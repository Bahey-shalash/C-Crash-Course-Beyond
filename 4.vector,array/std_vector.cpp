/*
    ### C++ Course: `std::vector`

    `std::vector` is a dynamic array provided by the C++ Standard Library. It resizes automatically 
    and is stored in the heap, making it suitable for large or variable-sized arrays.

    Topics Covered:
    1. Declaration and Dynamic Resizing
    2. Memory Allocation on the Heap
    3. Advantages and Common Operations
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. Declaration and Dynamic Resizing
    vector<int> numbers = {1, 2, 3};  // Initial size is 3

    // Adding elements dynamically
    numbers.push_back(4);
    numbers.push_back(5);

    // Accessing elements
    cout << "`std::vector` elements: ";
    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // 2. Memory Allocation on the Heap
    /*
        `std::vector` allocates memory on the heap, allowing it to grow as needed.
        - Slower than stack allocation but provides flexibility for dynamic sizing.
    */
    cout << "Size of `std::vector`: " << numbers.size() << endl;
    cout << "Capacity of `std::vector`: " << numbers.capacity() << endl;

    // 3. Advantages and Common Operations
    /*
        - Dynamic Resizing: `push_back` and `resize` allow flexible growth.
        - Bounds Checking: `.at()` provides bounds checking, though indexing with `[]` does not.
        - Performance: `std::vector` may perform slower than stack-allocated arrays for very large data.
    */

    return 0;
}

/*
    Compile and run:
        g++ std_vector.cpp -o std_vector
        ./std_vector
*/