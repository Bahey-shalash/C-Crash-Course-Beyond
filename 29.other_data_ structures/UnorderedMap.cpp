/* ==========================================================================
Crash Course: Hash Tables with std::unordered_map

Theory:
---------
std::unordered_map is implemented as a hash table that stores key-value pairs.
Conceptually, its memory layout includes:

       +----------------------------------+
       |        Bucket Array              |   <-- Array of pointers (buckets)
       +----------------------------------+
         /     |      \   ...     \
        v      v       v            v
   +--------+ +--------+ ... +--------+
   | Node   | | Node   |     | Node   |    <-- Each node holds:
   | (key,  | | (key,  |     | (key,  |
   | value) | | value) |     | value) |
   | next-> | | next-> |     | next-> |
   +--------+ +--------+     +--------+

Key Points:
- Average-case time complexity: O(1) for insertions, lookups, and deletions.
- The order of elements is not preserved.
- Collisions are resolved using chaining (linked lists or trees).

Edge Cases:
- Inserting a duplicate key updates the value.
- Worst-case operations may degrade to O(n) if many collisions occur.

Examples:
---------
1. Basic insertion, lookup, and iteration.
2. Erasing an element and checking key count.
========================================================================== */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> umap;

    // Example 1: Insert elements using operator[]
    umap["apple"] = 3;
    umap["banana"] = 5;
    umap["cherry"] = 2;
    umap.insert({"date", 7});

    cout << "Contents of std::unordered_map:" << endl;
    for (const auto& pair : umap) {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Example 2: Lookup using find()
    if (umap.find("banana") != umap.end()) {
        cout << "Found 'banana' with value: " << umap["banana"] << endl;
    } else {
        cout << "'banana' not found." << endl;
    }

    // Example 3: Update and count
    umap["apple"] = 10;
    cout << "Updated 'apple' to " << umap["apple"] << endl;
    cout << "Count for 'apple': " << umap.count("apple") << endl;

    // Example 4: Erase an element
    umap.erase("cherry");
    cout << "After erasing 'cherry', size: " << umap.size() << endl;

    return 0;
}