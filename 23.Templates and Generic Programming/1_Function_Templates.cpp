/* ==========================================================================
Lesson 1: Function Templates

Theory:
---------
Function templates allow you to write a generic function that works with
multiple data types. The compiler automatically generates the correct
function instance based on the arguments provided.

Key Points:
- Template parameters are deduced automatically.
- They enable code reuse and type independence.
- Edge Cases: If types are incompatible (e.g., using a custom type that
  doesn’t support the '+' operator), you may get compilation errors.

Example:
---------
A generic function to add two values.
========================================================================== */

#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    // Works for integers:
    cout << "add(3, 4) = " << add(3, 4) << endl;
    // Works for doubles:
    cout << "add(3.5, 4.2) = " << add(3.5, 4.2) << endl;

    // Uncommenting the following may cause an error if the operator+ is not defined:
    // struct Dummy {};
    // Dummy d1, d2;
    // add(d1, d2); // Error: no operator+ for Dummy
    return 0;
}