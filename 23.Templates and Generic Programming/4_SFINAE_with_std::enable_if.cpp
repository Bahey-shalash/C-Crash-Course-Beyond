/* ==========================================================================
Lesson 4: SFINAE (Substitution Failure Is Not An Error)

Theory:
---------
SFINAE is a technique that allows a template to fail substitution without causing
a compilation error. It is often used to conditionally enable template overloads.

Key Points:
- Use std::enable_if to constrain function templates.
- Helps select the correct overload when types differ.
- Edge Cases: Overuse or complex SFINAE expressions can lead to confusing compiler
errors.

Example:
---------
A multiply function that only works for integral types.
========================================================================== */

#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type multiply(T a, T b) {
    return a * b;
}

int main() {
    cout << "multiply(3, 4) = " << multiply(3, 4) << endl;
    // Uncommenting the following line would cause a compile error because double is
    // not integral. cout << "multiply(3.14, 2.5) = " << multiply(3.14, 2.5) << endl;
    return 0;
}