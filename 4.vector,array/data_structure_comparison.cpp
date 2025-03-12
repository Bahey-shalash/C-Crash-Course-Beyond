/*
    ### C++ Course: Data Structure Comparison (`std::array`, `std::vector`, C-Style
   Arrays)

    Choosing the right data structure requires understanding the trade-offs between
   stack and heap allocation, performance, and flexibility.

    Topics Covered:
    1. Memory Layout and Access Speed
    2. Resizability and Safety
    3. Choosing the Right Data Structure
*/

#include <array>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. Memory Layout and Access Speed
    array<int, 3> stdArray = {1, 2, 3};  // Stack allocated
    int cArray[3] = {1, 2, 3};           // Stack allocated
    vector<int> vec = {1, 2, 3};         // Heap allocated

    cout << "`std::array` address: " << &stdArray[0] << endl;
    cout << "C-Style Array address: " << &cArray[0] << endl;
    cout << "`std::vector` address: " << &vec[0] << endl;

    // 2. Resizability and Safety
    vec.push_back(4);  // Resizing `std::vector`

    cout << "\nAfter resizing `std::vector`:\n";
    for (int v : vec)
        cout << v << " ";
    cout << endl;

    /*
        Choosing the Right Data Structure:
        - Use `std::array` for fixed-size, stack-allocated arrays with added safety.
        - Use `std::vector` for dynamic arrays requiring resizing, but be mindful of
       heap usage.
        - Use C-style arrays only in performance-critical code when size is fixed and
       safety is managed.

        always prioritize the use of the stack over the heap when possible. (unless you
       need dynamic memory allocation in that case you need to use the heap  but
       reserve the memory to avoid multiple allocations)
    */

    return 0;
}

/*
    Compile and run:
        g++ data_structure_comparison.cpp -o data_structure_comparison
        ./data_structure_comparison
*/