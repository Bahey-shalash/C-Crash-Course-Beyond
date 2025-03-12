/*
    ### C++ Course: Range-Based Loops - `for(auto elem : tab)` vs. `for(auto& elem : tab)`

    In range-based loops, choosing `auto elem` vs. `auto& elem` affects performance:
    - `auto elem`: Copies each element.
    - `auto& elem`: Accesses elements by reference, avoiding copies.

    Topics Covered:
    1. Performance of Copying vs. Referencing in Loops
    2. When to Use Each Form
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> data = {1, 2, 3, 4, 5};

    // Loop with copying (auto elem)
    cout << "Using `for(auto elem : data)`:\n";
    for (auto elem : data) {
        elem += 1;  // Modifies local copy only
        cout << elem << " ";
    }
    cout << "\nOriginal vector after copying loop: ";
    for (const auto& elem : data) {
        cout << elem << " ";  // Original vector remains unchanged
    }

    // Loop with referencing (auto& elem)
    cout << "\n\nUsing `for(auto& elem : data)`:\n";
    for (auto& elem : data) {
        elem += 1;  // Modifies original element in the vector
        cout << elem << " ";
    }

    return 0;
}

/*
    Compile and run:
        g++ range_based_loops.cpp -o range_based_loops
        ./range_based_loops
*/