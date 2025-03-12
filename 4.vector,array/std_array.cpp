/*
    ### C++ Course: `std::array` (C++11)

    `std::array` is a fixed-size array from the C++ Standard Library. It is allocated on the stack
    and offers better safety and utility compared to C-style arrays.

    Topics Covered:
    1. Declaration and Initialization
    2. Memory Layout and Stack Allocation
    3. Advantages over C-style Arrays
*/

#include <iostream>
#include <array>  // Required for std::array
using namespace std;

int main() {
    // 1. Declaration and Initialization
    array<int, 5> numbers = {1, 2, 3, 4, 5};  // std::array with 5 elements

    // Accessing elements
    cout << "`std::array` elements: ";
    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // 2. Memory Layout and Stack Allocation
    /*
        `std::array` is allocated on the stack, similar to C-style arrays.
        - Provides size and bounds checking with `.size()` and `.at()`.
    */
    cout << "Size of `std::array` (elements): " << numbers.size() << endl;
    cout << "Memory address of `numbers[0]`: " << &numbers[0] << endl;

    // Access with bounds checking
    try {
        cout << "Accessing out-of-bounds element: ";
        cout << numbers.at(10) << endl;  // Throws an exception
    } catch (const out_of_range &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

/*
    Compile and run:
        g++ std_array.cpp -o std_array
        ./std_array
*/