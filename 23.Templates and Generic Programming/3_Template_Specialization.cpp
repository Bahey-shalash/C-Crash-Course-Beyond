/* ==========================================================================
Lesson 3: Template Specialization

Theory:
---------
Sometimes a generic implementation is not ideal for every type.
Template specialization lets you provide a custom implementation for a specific type.

Key Points:
- Full specialization: Provide an implementation for one specific type.
- Partial specialization (only for class templates): Specialize for a range of types.
- Edge Cases: Over-specializing can lead to maintenance challenges.

Example:
---------
A Printer class with a general implementation and a specialization for bool.
========================================================================== */

#include <iostream>
using namespace std;

template <typename T>
class Printer {
public:
    void print(const T& value) { cout << "General printer: " << value << endl; }
};

// Full specialization for bool
template <>
class Printer<bool> {
public:
    void print(const bool& value) {
        cout << "Boolean printer: " << (value ? "true" : "false") << endl;
    }
};

int main() {
    Printer<int> intPrinter;
    intPrinter.print(42);

    Printer<bool> boolPrinter;
    boolPrinter.print(true);

    return 0;
}