/*
    ### C++ Course: Array Memory Layout and Out-of-Bounds Access

    Arrays in C++ are stored contiguously in memory, which enables fast access.
    However, accessing elements out-of-bounds (i.e., beyond their allocated memory) is
   undefined behavior. While the program may run without visible issues, out-of-bounds
   access can lead to subtle and severe bugs.

    Topics Covered:
    1. Memory Layout of Multidimensional Arrays
    2. Potential Consequences of Out-of-Bounds Access
*/

#include <array>
#include <iostream>
using namespace std;

int main() {
    // Define a 2x3 array, with 2 rows and 3 columns, allocated contiguously in memory
    /* 
    A B C
    D E F
     */
    array<array<char, 3>, 2> mat = {'A', 'B', 'C', 'D', 'E', 'F'};

    // 1. Accessing elements within bounds
    cout << "Accessing mat[0][1] and mat[0][0]: ";
    cout << mat[0][1] << mat[0][0] << mat[0][3]<< endl;  // Expected output: B A

    // 2. Demonstrating contiguous memory layout
    cout << "Memory addresses of mat elements:\n";
    cout << "mat[0][0] address: " << static_cast<void*>(&mat[0][0]) << endl;
    cout << "mat[0][1] address: " << static_cast<void*>(&mat[0][1]) << endl;
    cout << "mat[0][2] address: " << static_cast<void*>(&mat[0][2]) << endl;
    cout << "mat[1][0] address: " << static_cast<void*>(&mat[1][0]) << endl;
    

    // Explanation:
    // Elements are stored in contiguous memory blocks, allowing fast access.
    // `mat[0][2]` is directly followed by `mat[1][0]` in memory.

    // 3. Out-of-bounds access (undefined behavior)
    /*
        Trying to access `mat[0][3]` goes out-of-bounds. Since `mat[0]` only has 3
       elements (indices 0-2), `mat[0][3]` does not have a valid allocated memory
       location.

        Although it may "appear" to work in some environments (because it may access
       adjacent memory), this is not guaranteed by C++ and could lead to a program
       crash or unexpected behavior.
    */
    cout << "\nAttempting to access mat[0][3] (out-of-bounds): ";
    cout << mat[0][3] << endl;  // This is undefined behavior, though it might appear
                                // to work on some systems

    return 0;
}

/*
    Compile and run:
        g++ array_memory_layout.cpp -o array_memory_layout
        ./array_memory_layout
*/

/*
    Key Takeaways:
    - Arrays are stored contiguously in memory, allowing efficient indexing and pointer
   arithmetic.
    - Accessing elements outside of their defined bounds (like `mat[0][3]`) results in
   undefined behavior.
    - Undefined behavior may appear to work on some systems due to adjacent memory, but
   it is not reliable or safe.
*/