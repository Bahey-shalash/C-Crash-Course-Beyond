/* ==========================================================================
Crash Course: Sorted Unique Values with std::set

Theory:
---------
std::set stores unique values in sorted order. It is typically implemented as a 
balanced binary search tree. Its nodes contain a single value and pointers to 
child nodes.

Conceptual node diagram:

       +---------------------+
       |      Node           |
       |  Value: 5           |  <-- Only unique values are stored.
       |  Left -> Node*      |
       |  Right -> Node*     |
       +---------------------+
  
- Insertion, lookup, and deletion are O(log n).
- Duplicate insertions are ignored.

Edge Cases:
- Attempting to insert a duplicate does nothing.
- Use std::multiset if duplicates are needed.

Examples:
---------
1. Inserting values and iterating in sorted order.
2. Checking existence with find().
3. Erasing an element.
========================================================================== */

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // Example 1: Insert elements.
    s.insert(5);
    s.insert(3);
    s.insert(8);
    s.insert(1);
    s.insert(5);  // Duplicate; ignored.

    cout << "Contents of std::set:" << endl;
    for (int elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    // Example 2: Lookup an element.
    if (s.find(3) != s.end()) {
        cout << "3 is in the set." << endl;
    } else {
        cout << "3 is not in the set." << endl;
    }

    // Example 3: Erase an element.
    s.erase(3);
    cout << "After erasing 3:" << endl;
    for (int elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}