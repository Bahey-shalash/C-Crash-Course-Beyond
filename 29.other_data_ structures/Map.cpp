/* ==========================================================================
Crash Course: Sorted Key-Value Stores with std::map

Theory:
---------
std::map is an associative container implemented as a balanced binary search tree.
Each node contains a key-value pair and pointers to its left/right children.
  
       +---------------------+
       |      Node           |  <-- Node holds:
       |  Key: "apple"       |      • key ("apple")
       |  Value: 3           |      • value (3)
       |  Left -> Node*      |      • pointers to children
       |  Right -> Node*     |
       |  Parent -> Node*    |
       +---------------------+
  
- Operations (insert, lookup, deletion) run in O(log n) time.
- Elements are automatically sorted by key.

Edge Cases:
- Inserting a duplicate key updates the existing value.
- Iteration always follows sorted order.

Examples:
---------
1. Inserting and iterating over elements.
2. Using find() to lookup a key.
3. Demonstrating sorted order.
========================================================================== */

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> smap;

    // Example 1: Insert elements.
    smap["apple"] = 3;
    smap["banana"] = 5;
    smap["cherry"] = 2;
    smap.insert(make_pair("date", 7));

    cout << "Contents of std::map (sorted):" << endl;
    for (const auto& pair : smap) {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Example 2: Lookup using find()
    auto it = smap.find("banana");
    if (it != smap.end()) {
        cout << "Found 'banana' with value: " << it->second << endl;
    } else {
        cout << "'banana' not found." << endl;
    }

    // Example 3: Duplicate key updates value.
    smap["apple"] = 10;
    cout << "Updated 'apple' to " << smap["apple"] << endl;

    return 0;
}