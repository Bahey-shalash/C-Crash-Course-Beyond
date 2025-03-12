/* ==========================================================================
Crash Course: Grouping Multiple Values with std::pair and std::tuple

Theory:
---------
- std::pair stores two related values, laid out contiguously in memory.
  
      +-------------+-------------+
      | first (T1)  | second (T2) |
      +-------------+-------------+
  
- std::tuple can store an arbitrary number of values (possibly of different types).
  Its layout is similar to a sequence of values (with possible padding between them):

      +---------+----------+---------+
      | Elem 0  |  Elem 1  |  Elem 2 |
      +---------+----------+---------+
  
They are useful for returning multiple values from a function.

Edge Cases:
- Accessing a tuple with the wrong index or type results in a compile-time error.
  
Examples:
---------
1. Creating and accessing a std::pair.
2. Creating, accessing, and unpacking a std::tuple.
3. Concatenating tuples with std::tuple_cat.
========================================================================== */

#include <iostream>
#include <tuple>
#include <string>
using namespace std;

int main() {
    // Example 1: std::pair
    pair<int, string> myPair = {1, "one"};
    cout << "Pair: " << myPair.first << " -> " << myPair.second << endl;

    // Example 2: std::tuple
    tuple<int, double, string> myTuple = {42, 3.14, "Hello"};
    cout << "Tuple elements: " << get<0>(myTuple) << ", "
         << get<1>(myTuple) << ", " << get<2>(myTuple) << endl;

    // Example 3: Unpacking with std::tie
    int a;
    double b;
    string c;
    tie(a, b, c) = myTuple;
    cout << "Unpacked tuple: " << a << ", " << b << ", " << c << endl;

    // Extra Example: Concatenating tuples.
    tuple<int, char> t1 = {10, 'A'};
    tuple<double, string> t2 = {2.718, "pi"};
    auto t3 = tuple_cat(t1, t2);
    cout << "Concatenated tuple: " 
         << get<0>(t3) << ", " << get<1>(t3) << ", " 
         << get<2>(t3) << ", " << get<3>(t3) << endl;

    return 0;
}