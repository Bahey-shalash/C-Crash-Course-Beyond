/*
    ### C++ Course: Initialization Styles in C++

    C++ supports multiple styles of variable initialization:
    1. Copy Initialization (`=`)
    2. Direct Initialization (`()`)
    3. Uniform Initialization (`{}`), introduced in C++11
    4. Default Initialization (e.g., uninitialized variables, zero initialization)

    Each style has specific use cases, and modern C++ encourages the use of brace
   initialization to avoid certain pitfalls, such as narrowing conversions.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 1. Copy Initialization (`=`)
    // This style initializes a variable by copying a value. It’s straightforward for
    // fundamental types.

    int x = 42;             // Copy initialization of an int
    double pi = 3.14159;    // Copy initialization of a double
    string name = "Alice";  // Copy initialization of a string

    cout << "Copy-initialized int x: " << x << endl;
    cout << "Copy-initialized double pi: " << pi << endl;
    cout << "Copy-initialized string name: " << name << endl;

    // 2. Direct Initialization (`()`)
    // Direct initialization is commonly used with objects. For primitive types, it’s
    // equivalent to copy initialization.

    int y(99);                 // Direct initialization of an int
    double e(2.71828);         // Direct initialization of a double
    string greeting("Hello");  // Direct initialization of a string

    cout << "\nDirectly-initialized int y: " << y << endl;
    cout << "Directly-initialized double e: " << e << endl;
    cout << "Directly-initialized string greeting: " << greeting << endl;

    // 3. Brace Initialization (`{}`) - C++11 and later
    // Brace initialization is highly recommended in modern C++ as it prevents implicit
    // narrowing conversions.

    int z{256};                       // Brace initialization of an int
    double phi{1.61803};              // Brace initialization of a double
    string phrase{"C++11"};           // Brace initialization of a string
    vector<int> numbers{1, 2, 3, 4};  // Brace initialization of a vector

    cout << "\nBrace-initialized int z: " << z << endl;
    cout << "Brace-initialized double phi: " << phi << endl;
    cout << "Brace-initialized string phrase: " << phrase << endl;
    cout << "Brace-initialized vector numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Brace initialization also prevents narrowing conversions.
    // Uncommenting the next line would cause a compilation error due to narrowing from
    // double to int. int invalid{3.14}; // Error: narrowing conversion from double to
    // int

    // 4. Zero Initialization and Default Initialization
    // Variables with static storage duration are zero-initialized by default.
    // Local variables without an initializer are uninitialized and contain
    // indeterminate values.

    int uninitialized;      // Uninitialized local variable (value is undefined)
    int zeroInitialized{};  // Zero-initialized variable, `int zeroInitialized = 0` is
                            // equivalent

    cout << "\nUninitialized int (undefined behavior): " << uninitialized << endl;
    cout << "Zero-initialized int zeroInitialized: " << zeroInitialized << endl;

    // Uniform initialization using {} is safer and generally preferred in modern C++
    // to avoid surprises and unexpected type conversions.

    return 0;
}