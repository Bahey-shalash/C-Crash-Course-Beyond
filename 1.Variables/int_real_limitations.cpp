/*
Course: Limitations of Integer and Real Data Types in C++

This course explores the limitations of common data types in C++, such as `int`,
`long`, `float`, and `double`. These types are constrained by the system architecture
(e.g., 32-bit, 64-bit), and understanding these constraints helps prevent overflow
errors and ensures accurate calculations in your programs.

Topics Covered:
    1. Integer data types and their ranges.
    2. Real data types and precision limitations.
    3. Practical examples of overflow and precision errors.
*/

#include <cmath>  // For mathematical functions like sqrt
#include <iostream>
#include <limits>  // For numeric_limits
using namespace std;

int main() {
    // 1. Integer Type Limitations
    /*
        In C++, integer types (`int`, `short`, `long`, etc.) have fixed ranges. These
       ranges can be checked using `std::numeric_limits`, which provides the maximum
       and minimum values for each type.

        Common Integer Types and Ranges:
        - `int`: Typically -2,147,483,648 to 2,147,483,647 (on 32-bit systems).
        - `unsigned int`: 0 to 4,294,967,295.
        - `long int`: Varies by system, but at least as large as `int`.
    */

    cout << "Integer Type Limits:\n";
    cout << "Maximum int: " << numeric_limits<int>::max() << endl;
    cout << "Minimum int: " << numeric_limits<int>::min() << endl;
    cout << "Maximum unsigned int: " << numeric_limits<unsigned int>::max() << endl;

    // Demonstrating Overflow
    int n = 100000;
    cout << "\nOverflow Example with int:\n";
    cout << "Initial value of n: " << n << endl;
    n = n * n;  // Squaring n; this may exceed int range
    cout << "After squaring n: " << n << " (Check if overflow occurred)\n";

    // 2. Real Type Limitations and Precision Issues
    /*
        Real number types (`float`, `double`, and `long double`) cannot precisely
       represent all real values due to finite precision. This limitation can lead to
       inaccuracies in calculations, especially for very large or very small numbers.

        Real Types and Precision:
        - `float`: Typically up to 7 decimal places of precision.
        - `double`: Typically up to 15 decimal places of precision.
        - `long double`: Varies, often more precise than `double`.
    */

    cout << "\nReal Number Type Limits:\n";
    cout << "Maximum float: " << numeric_limits<float>::max() << endl;
    cout << "Maximum double: " << numeric_limits<double>::max() << endl;

    // Demonstrating Precision Issue
    double a = 37.0;
    double root = sqrt(a);
    cout << "\nPrecision Example with double:\n";
    cout << "Expected value of a - root * root (should be 0): " << a - root * root
         << endl;
    // The result is not exactly zero due to precision loss.

    // Precision Comparison
    /*
        To compare floating-point numbers safely, avoid direct equality checks.
        Use a small epsilon value instead, as shown below.
    */
    double epsilon = 1e-10;  // A small threshold value
    if (abs(a - root * root) < epsilon) {
        cout << "The result is close enough to zero.\n";
    } else {
        cout << "The result is not close enough to zero.\n";
    }

    return 0;
}