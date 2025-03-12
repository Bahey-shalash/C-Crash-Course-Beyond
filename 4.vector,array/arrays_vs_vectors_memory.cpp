/*
    ### C++ Course: Prioritizing Arrays over Vectors for Memory Efficiency

    Arrays, especially C-style arrays and `std::array`, are often more memory efficient
   than `std::vector`. This is due to:
    - **Fixed Size**: Arrays are allocated once on the stack (or statically) and do not
   require extra memory.
    - **No Dynamic Resizing**: `std::vector` manages its own dynamic memory on the
   heap, which incurs overhead.

    Topics Covered:
    1. Memory Efficiency of Arrays vs. Vectors
    2. Performance Implications for Large Data Structures
*/

#include <array>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Example with std::array (fixed-size)
    array<int, 1000> staticArray;
    cout << "Size of `std::array`: " << sizeof(staticArray)
         << " bytes (stack allocated)" << endl;

    // Example with std::vector (dynamic-size)
    vector<int> dynamicVector(1000);
    cout << "Size of `std::vector`: " << sizeof(dynamicVector)
         << " bytes (heap allocated)" << endl;

    /*
        Explanation:
        - `std::array` is allocated on the stack, so accessing its elements is
       generally faster.
        - `std::vector` is allocated on the heap and includes extra space for resizing,
       which adds overhead.
        - For small, fixed-size data, `std::array` and C-style arrays are more memory
       efficient.
    */

    return 0;
}

/*
    Compile and run:
        g++ arrays_vs_vectors_memory.cpp -o arrays_vs_vectors_memory
        ./arrays_vs_vectors_memory
*/