/*
    ### C++ Course: `const` vs. `constexpr`

    This course explains the differences between `const` and `constexpr`, introduced in
   C++11. While they appear similar, `const` and `constexpr` differ in key ways related
   to runtime versus compile-time values. Understanding these distinctions is crucial
   for writing efficient and error-free code.

    Topics Covered:
    1. `const` - Creating Read-Only Variables at Runtime
    2. `constexpr` - Defining Compile-Time Constants
    3. Practical Examples and Common Errors
*/

#include <cmath>  // For mathematical operations
#include <iostream>
#include <limits>  // For numeric limits
using namespace std;

// for line 94
constexpr int square(int x) {
    return x * x;
}  // Compile-time square function 


int main() {
    // 1. `const` - Read-Only Variables at Runtime
    /*
        The `const` keyword in C++ makes a variable read-only through the specified
       name. This does not mean the value itself is truly constant; instead, `const`
       prevents modification through that specific variable name.

        Example:
    */

    int const i = 3;  // `i` is read-only; cannot be changed via the name `i`
    // i = 5;  // This line would cause a compilation error because `i` is `const`

    // However, `const` does not guarantee absolute immutability.
    // Dangerous example - Modifying `i` through a pointer:
    int* ptr = (int*)&i;  // Casting away `const` - generally bad practice
    *ptr = 5;  // Modifies the value of `i` through `ptr`, although `i` is const
    cout << "Value of i after modification through pointer: " << i << endl;

    // Explanation: The `const` keyword only makes `i` read-only through the identifier
    // `i`. It does not prevent changing the value of `i` if accessed differently, such
    // as through a pointer.

    // 2. `const` with Runtime Values
    /*
        `const` can also apply to values that are not known at compile-time.
        Example: Obtaining user input, then marking it `const` to prevent
       modifications.
    */

    int userValue;
    cout << "Enter an integer value: ";
    cin >> userValue;
    const int runtimeConst =
        userValue;  // This value is fixed at runtime but unknown at compile-time
    cout << "Runtime const value: " << runtimeConst << endl;

    // This demonstrates that `const` can apply to dynamically assigned values,
    // but only enforces immutability from that point forward.

    // 3. `constexpr` - Compile-Time Constants
    /*
        `constexpr` was introduced to address two limitations of `const`:
        - It ensures a variable's value is known at compile-time.
        - The value is truly constant and cannot change.

        This is ideal for values that should be fixed at compile-time, allowing the
       compiler to optimize further by embedding the values directly into the binary
       code.

        Example:
    */

    constexpr double pi = 3.14159265358;  // Value known and fixed at compile-time
    cout << "Compile-time constant (pi): " << pi << endl;

    // Attempting to assign a non-compile-time value to `constexpr` will fail:
    // int userInput;
    // cin >> userInput;
    // constexpr int invalidConstExpr = userInput; // Error: Not known at compile-time

    // 4. Practical Usage of `constexpr` Functions
    /*
        `constexpr` can also apply to functions, making them callable at compile-time
        if all arguments are known at compile-time. This is useful for mathematical
        constants or configurations fixed at compile-time.

        Example:
    */

    constexpr int squaredValue = square(5);  // Computed at compile-time
    cout << "Square of 5 (constexpr function): " << squaredValue << endl;

    // Using the constexpr function with runtime values will compute at runtime:
    int runtimeInput;
    cout << "Enter a number to square: ";
    cin >> runtimeInput;
    cout << "Square of entered number (runtime): " << square(runtimeInput) << endl;

    // 5. Practical Examples of Errors with `const` and `constexpr`
    /*
        Common errors occur when trying to assign non-constant values to `constexpr` or
       modify `const`.

        Example of `const` misuse:
    */

    const int constValue = 10;
    // constValue = 20; // Error: Cannot modify `const` variable after initialization

    /*
        Example of `constexpr` misuse:
        The following would cause an error because `userValue` is not known at
       compile-time.
    */

    // constexpr int invalidCompileTimeValue = userValue; // Error: Requires
    // compile-time constant

    /*
        Summary:
        - Use `const` for values that are fixed at runtime but may not be known at
       compile-time.
        - Use `constexpr` for values that are both fixed and known at compile-time.
    */

    return 0;
}