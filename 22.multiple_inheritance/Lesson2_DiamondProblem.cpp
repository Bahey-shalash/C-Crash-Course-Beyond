/* ==========================================================================
Lesson 2: The Diamond Problem (Without Virtual Inheritance)

The diamond problem occurs when a class inherits from two classes that both derive
from a common base class. Without special handling, the derived class contains two
copies of the base class members, leading to ambiguity.

In this example:
- Class A is the common base.
- Classes B and C inherit from A.
- Class D inherits from both B and C.
Calling A’s members from D becomes ambiguous.
========================================================================== */
// Lesson2_DiamondProblem.cpp

#include <iostream>
using namespace std;

class A {
public:
    void info() const { cout << "I am class A." << endl; }
};

class B : public A {
    // B inherits A publicly.
};

class C : public A {
    // C inherits A publicly.
};

class D : public B, public C {
    // D inherits from both B and C.
};

int main() {
    D d;

    // The following call is ambiguous because D has two copies of A.
    // Uncommenting the next line will cause a compile-time error.
    // d.info();

    // To resolve the ambiguity, you must specify which A subobject to use:
    d.B::info();  // Calls the A subobject inherited via B.
    d.C::info();  // Calls the A subobject inherited via C.

    return 0;
}
/*
Explanation:
Without virtual inheritance, class D contains two separate A subobjects (one via B and
one via C), so calling info() without qualification is ambiguous. */