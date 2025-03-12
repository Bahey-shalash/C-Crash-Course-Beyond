/* ==========================================================================
Lesson 6: Advanced Template Topics

Part A: CRTP (Curiously Recurring Template Pattern)
------------------------------------------------------
CRTP is a technique where a class template uses its derived class as a template
parameter. It can be used to implement static polymorphism.

Part B: Concepts (C++20)
------------------------
Concepts allow you to constrain template parameters, improving error messages and code
clarity.

Example:
---------
- CRTP to provide a common interface.
- A simple concept to constrain a type.
========================================================================== */

#include <concepts>
#include <iostream>
using namespace std;

// Part A: CRTP example
template <typename Derived>
class BaseCRTP {
public:
    void interface() const {
        // Call a function implemented in the derived class.
        static_cast<const Derived*>(this)->implementation();
    }
};

class DerivedCRTP : public BaseCRTP<DerivedCRTP> {
public:
    void implementation() const {
        cout << "DerivedCRTP implementation called." << endl;
    }
};

// Part B: Concepts example (requires C++20)
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};

template <Addable T>
T addConcept(T a, T b) {
    return a + b;
}

int main() {
    // CRTP demonstration:
    DerivedCRTP obj;
    obj.interface();  // Calls DerivedCRTP::implementation()

    // Concepts demonstration:
    cout << "addConcept(10, 20) = " << addConcept(10, 20) << endl;
    // addConcept("Hello ", "World");  // Error: std::string doesn't satisfy the
    // concept if '+' isn’t defined accordingly.
    return 0;
}