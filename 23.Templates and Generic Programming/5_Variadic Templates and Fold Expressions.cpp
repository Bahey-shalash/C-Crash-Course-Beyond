/* ==========================================================================
Lesson 5: Variadic Templates and Fold Expressions

Theory:
---------
Variadic templates allow functions and classes to accept an arbitrary number of template parameters.
Fold expressions (introduced in C++17) simplify writing operations over parameter packs.

Key Points:
- Parameter packs and recursion were traditionally used to process variadic templates.
- Fold expressions simplify summing or combining arguments.
- Edge Cases: Ensure that your fold expression covers the base case (e.g., an empty pack).

Example:
---------
A sum function that adds an arbitrary number of arguments using a fold expression.
========================================================================== */

#include <iostream>
using namespace std;

template<typename... Args>
auto sum(Args... args) {
    return (args + ...);  // Fold expression: sums all arguments.
}

int main() {
    cout << "Sum(1, 2, 3, 4, 5) = " << sum(1, 2, 3, 4, 5) << endl;  // Should output 15
    // Edge case: sum() with no arguments would be ill-formed unless handled separately.
    return 0;
}