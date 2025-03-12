/* ==========================================================================
Crash Course: Unordered Sets with std::unordered_set

Theory:
---------
std::unordered_set is implemented as a hash table to store unique elements.
Its conceptual memory layout is similar to std::unordered_map but without the values:

       +----------------------------------+
       |        Bucket Array              |  <-- Buckets array (hash table)
       +----------------------------------+
         /     |      \   ...     \
        v      v       v            v
   +--------+ +--------+ ... +--------+
   | Node   | | Node   |     | Node   |  <-- Each node contains a value and a pointer.
   | (value)| | (value)|     | (value)|
   | next-> | | next-> |     | next-> |
   +--------+ +--------+     +--------+

- Average-case operations are O(1).
- The order of elements is not defined.

Edge Cases:
- Duplicate insertions are ignored.
- Worst-case complexity may degrade to O(n) with poor hash functions.

Examples:
---------
1. Inserting and iterating over elements.
2. Lookup of an element.
3. Erasing an element.
========================================================================== */

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> uset;

    // Example 1: Insert elements.
    uset.insert(10);
    uset.insert(20);
    uset.insert(30);
    uset.insert(20); // Duplicate; ignored.

    cout << "Contents of std::unordered_set:" << endl;
    for (int elem : uset) {
        cout << elem << " ";
    }
    cout << endl;

    // Example 2: Check existence.
    if (uset.find(10) != uset.end()) {
        cout << "10 is in the unordered_set." << endl;
    } else {
        cout << "10 is not in the unordered_set." << endl;
    }

    // Example 3: Erase an element.
    uset.erase(20);
    cout << "After erasing 20:" << endl;
    for (int elem : uset) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}