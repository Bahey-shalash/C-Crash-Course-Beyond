/*
    ### C++ Course: Using `.reserve()` with `std::vector` vs. Arrays

    The `.reserve()` method in `std::vector` pre-allocates memory to avoid repeated
   allocations. Arrays, by contrast, have fixed sizes that cannot be reserved or
   resized.

    Topics Covered:
    1. Using `.reserve()` with `std::vector`
    2. Comparison with Fixed-Size Arrays
    3. Performance Impact of Reserving Memory
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Without `.reserve()`
    vector<int> vecWithoutReserve;
    for (int i = 0; i < 100; ++i) {
        vecWithoutReserve.push_back(i);  // May cause multiple allocations
    }

    // With `.reserve()`
    vector<int> vecWithReserve;
    vecWithReserve.reserve(100);  // Reserves memory for 100 elements
    for (int i = 0; i < 100; ++i) {
        vecWithReserve.push_back(i);  // No additional allocations
    }

    /*
        Explanation:
        - Reserving memory with `.reserve()` reduces allocation overhead.
        - Arrays, by design, don’t need `.reserve()` because they are fixed-size and
       allocated once.
    */

    return 0;
}

/*
    Compile and run:
        g++ vector_reserve_vs_array.cpp -o vector_reserve_vs_array
        ./vector_reserve_vs_array
*/