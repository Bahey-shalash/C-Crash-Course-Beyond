/* ==========================================================================
Lesson 1: Inlining, constexpr, and Compiler Optimizations

Theory:
---------
- **Inlining:**  
  Suggests that the compiler replaces a function call with the function's body,
  reducing function call overhead.
- **constexpr:**  
  Allows functions and variables to be evaluated at compile-time, improving runtime performance.
- **Compiler Optimizations:**  
  Flags like -O2 or -O3 enable further optimizations.

Key Points:
- Use inline for small, frequently called functions.
- constexpr functions must be defined entirely in the header.
- Edge Cases: Excessive inlining may lead to larger binary sizes.

Example:
---------
A constexpr function to compute factorial at compile time.
========================================================================== */

#include <iostream>
using namespace std;

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

inline int addInline(int a, int b) {
    return a + b;
}

int main() {
    // The factorial will be computed at compile-time.
    constexpr int fact5 = factorial(5);
    cout << "Factorial of 5 is: " << fact5 << endl;

    // Inline function usage.
    cout << "addInline(10, 20) = " << addInline(10, 20) << endl;
    return 0;
}