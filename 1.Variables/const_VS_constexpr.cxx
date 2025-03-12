/*
    ### Comprehensive Course: `const` vs. `constexpr` in C++

    This course explores the `const` and `constexpr` keywords in C++ from the basics to
   advanced concepts, highlighting their differences, usage, and practical
   implications.

    #### Key Concepts:
    1. Introduction to `const` and its use cases.
    2. Introduction to `constexpr` and how it enhances compile-time computations.
    3. Detailed comparison of `const` vs. `constexpr`.
    4. Practical examples, including pitfalls and best practices.
    5. Advanced usage: `constexpr` with functions, classes, and templates.
*/

#include <cmath>     // For mathematical operations
#include <iostream>  // For I/O operations
using namespace std;

// Example of a `constexpr` function
constexpr int square(int x) {
    return x * x;
}

/*
    ### 1. `const`: Read-Only Variables
    The `const` keyword makes a variable or an object immutable through a given
   identifier. However, it applies only to the name, not the underlying data, which can
   still be changed indirectly.

    **Key Characteristics of `const`:**
    - Can be applied to variables, pointers, and function arguments.
    - The value of a `const` variable is determined at runtime or compile-time.
    - Guarantees immutability through the specified identifier but not absolute
   immutability.

    Example:
    - Fixing runtime or compile-time values as read-only.
    - Preventing accidental modification of variables or function parameters.
*/

void constExample() {
    cout << "### Example 1: `const` Basics\n";

    const int runtimeConst = 42;  // Compile-time or runtime value
    cout << "Runtime constant value: " << runtimeConst << endl;

    // Attempting to modify `runtimeConst` will cause an error:
    // runtimeConst = 100; // Uncommenting this line causes a compilation error

    // `const` with pointers:
    int value = 10;
    const int* ptr = &value;  // Pointer to a `const` value
    // *ptr = 20;  // Error: Cannot modify the value via a `const` pointer
    value = 20;  // OK: The value itself is not immutable
    cout << "Value pointed to by `ptr`: " << *ptr << endl;

    // Danger: Modifying `const` through a pointer cast (bad practice):
    int const immutable = 50;
    int* hackPtr = (int*)&immutable;  // Cast away `const` (not recommended)
    *hackPtr = 99;
    cout << "Value of `immutable` after indirect modification: " << immutable << endl;

    // Note: `const` ensures immutability through the identifier, not memory
    // protection.
}

/*
    ### 2. `constexpr`: Compile-Time Constants
    The `constexpr` keyword enforces that the variable, function, or object is
   evaluated at compile-time if possible. This allows the compiler to optimize by
   embedding values directly into the binary.

    **Key Characteristics of `constexpr`:**
    - Requires compile-time constant values for initialization.
    - Ideal for mathematical constants or fixed configurations.
    - Works with functions to ensure they can be evaluated at compile-time.

    Differences from `const`:
    - `const` allows runtime-determined values; `constexpr` requires compile-time
   values.
    - `constexpr` enables compile-time evaluation for functions.

    Example:
    - Defining mathematical constants or functions for compile-time optimization.
*/

void constexprExample() {
    cout << "\n### Example 2: `constexpr` Basics\n";

    constexpr int compileTimeConst = 25;  // Must be known at compile-time
    cout << "Compile-time constant: " << compileTimeConst << endl;

    // Using `constexpr` with functions:
    constexpr int squaredValue = square(5);  // Computed at compile-time
    cout << "Square of 5 (constexpr function): " << squaredValue << endl;

    // Using a `constexpr` function with runtime values:
    int runtimeValue;
    cout << "Enter a number to square: ";
    cin >> runtimeValue;
    cout << "Square of entered number (runtime computation): " << square(runtimeValue)
         << endl;

    // Error: Assigning a runtime value to a `constexpr` variable:
    // constexpr int invalidConstExpr = runtimeValue; // Uncommenting causes an error
}

/*
    ### 3. Comparing `const` vs. `constexpr`
    - `const` can be initialized with runtime or compile-time values; `constexpr`
   requires compile-time values.
    - `const` ensures immutability through its identifier; `constexpr` enforces
   immutability and compile-time evaluation.
    - `constexpr` supports functions that allow compile-time computations.

    Example:
    - Practical scenarios comparing both.
*/

void compareConstAndConstexpr() {
    cout << "\n### Example 3: Comparing `const` vs. `constexpr`\n";

    // `const` allows runtime initialization:
    int userInput;
    cout << "Enter a value: ";
    cin >> userInput;
    const int runtimeConst = userInput;
    cout << "Runtime constant: " << runtimeConst << endl;

    // `constexpr` requires compile-time values:
    constexpr int compileTimeConst = 50;  // Fixed at compile-time
    cout << "Compile-time constant: " << compileTimeConst << endl;

    // Attempting to use runtime values with `constexpr` causes errors:
    // constexpr int invalidCompileTimeConst = userInput;  // Uncommenting causes an
    // error

    // Function comparison:
    constexpr int compileTimeSquare = square(4);  // Computed at compile-time
    int runtimeSquare = square(runtimeConst);     // Computed at runtime
    cout << "Square (compile-time): " << compileTimeSquare << endl;
    cout << "Square (runtime): " << runtimeSquare << endl;
}

/*
    ### 4. Advanced Usage: `constexpr` with Classes and Templates
    `constexpr` can also be applied to class constructors and template arguments,
   enabling compile-time objects and computations.

    Example:
    - Using `constexpr` for constant objects.
*/

class Point {
public:
    constexpr Point(int x, int y) : x_(x), y_(y) {}
    constexpr int x() const { return x_; }
    constexpr int y() const { return y_; }

private:
    int x_, y_;
};

void advancedConstexprUsage() {
    cout << "\n### Example 4: Advanced `constexpr` Usage\n";

    // Compile-time object:
    constexpr Point p(3, 4);
    cout << "Point coordinates (compile-time): (" << p.x() << ", " << p.y() << ")\n";

    // Error: Modifying `constexpr` objects:
    // p.x_ = 5; // Uncommenting causes an error: cannot modify a `constexpr` object
}

/*
    ### 5. Pitfalls and Best Practices
    **Common Pitfalls:**
    - Casting away `const` is dangerous and should be avoided.
    - Misunderstanding `constexpr` and attempting to assign runtime values.

    **Best Practices:**
    - Use `const` for runtime-fixed values.
    - Use `constexpr` for compile-time constants or functions.
    - Avoid modifying memory indirectly when using `const`.
    - Leverage `constexpr` for performance-critical computations.

    **Example:**
    - Preventing misuse and ensuring clean, efficient code.
*/

void pitfallsAndBestPractices() {
    cout << "\n### Example 5: Pitfalls and Best Practices\n";

    const int runtimeConst = 100;
    // runtimeConst = 200;  // Error: Modifying `const` variable

    constexpr int compileTimeConst = 20;
    // constexpr int invalidConst = runtimeConst;  // Error: Requires compile-time
    // value

    // Avoid using pointers to modify `const` values:
    const int immutable = 42;
    // int* badPtr = (int*)&immutable;  // Avoid this practice
    // *badPtr = 50;
}

int main() {
    constExample();
    constexprExample();
    compareConstAndConstexpr();
    advancedConstexprUsage();
    pitfallsAndBestPractices();

    return 0;
}