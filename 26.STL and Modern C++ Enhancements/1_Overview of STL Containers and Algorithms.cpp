/* ==========================================================================
Lesson 1: Overview of STL Containers and Algorithms

Theory:
---------
The Standard Template Library (STL) provides generic containers, iterators, and
algorithms. Using STL can greatly simplify coding and improve performance.

Key Points:
- Containers: vector, list, map, set, unordered_map, etc.
- Iterators provide a uniform way to traverse containers.
- Algorithms such as sort, find, transform are highly optimized.
- Edge Cases: Know the complexity and behavior of each container and algorithm.

Example:
---------
Using std::vector and std::sort to sort a list of integers.
========================================================================== */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {5, 2, 9, 1, 5, 6};
    cout << "Original vector: ";
    for (int num : numbers)
        cout << num << " ";
    cout << endl;

    // Using std::sort algorithm (O(n log n) average)
    sort(numbers.begin(), numbers.end());

    cout << "Sorted vector: ";
    for (int num : numbers)
        cout << num << " ";
    cout << endl;

    return 0;
}