/* ==========================================================================
Crash Course: Structured Bindings (C++17)

Theory:
---------
Structured bindings let you "unpack" an object (such as a pair, tuple, array, or
a struct with public members) into individual variables, making code cleaner.
  
For example, given:
    tuple<int, double, char> t = {42, 3.14, 'a'};
The memory layout is still:
    [ int ][ double ][ char ]
But structured bindings allow you to write:
    auto [i, d, ch] = t;
Which creates variables i, d, and ch that map to the tuple’s elements.

Edge Cases:
- The number and types of bindings must match the object.
  
Examples:
---------
1. Unpacking a std::pair.
2. Unpacking a std::tuple.
3. Unpacking an array.
4. Unpacking a user-defined struct.
========================================================================== */

#include <iostream>
#include <tuple>
#include <array>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    // Example 1: Structured binding with std::pair.
    pair<int, string> myPair = {1, "one"};
    auto [number, word] = myPair;
    cout << "Pair unpacked: " << number << " -> " << word << endl;

    // Example 2: Structured binding with std::tuple.
    tuple<int, double, char> myTuple = {42, 3.14, 'a'};
    auto [i, d, ch] = myTuple;
    cout << "Tuple unpacked: " << i << ", " << d << ", " << ch << endl;

    // Example 3: Structured binding with an array.
    array<int, 3> myArray = {10, 20, 30};
    auto [x, y, z] = myArray;
    cout << "Array unpacked: " << x << ", " << y << ", " << z << endl;

    // Example 4: Structured binding with a user-defined struct.
    Point p = {5, 15};
    auto [px, py] = p;
    cout << "Point unpacked: (" << px << ", " << py << ")" << endl;

    return 0;
}