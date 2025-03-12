/* ==========================================================================
Lesson 3: Solving the Diamond Problem with Virtual Inheritance

By using virtual inheritance, the diamond problem is solved by ensuring that only one
copy of the common base class (A) is present in the derived class (D), even when
multiple paths to the base exist.

In this example:
- B and C virtually inherit from A.
- D inherits from B and C.
There is only one shared A subobject, so calling A’s methods from D is unambiguous.
========================================================================== */

// Lesson3_VirtualInheritance_DiamondProblem.cpp

#include <iostream>
using namespace std;

class A {
public:
    void info() const { cout << "I am class A (virtually inherited)." << endl; }
};

// B virtually inherits from A.
class B : virtual public A {
    // Additional members of B can be defined here.
};

// C virtually inherits from A.
class C : virtual public A {
    // Additional members of C can be defined here.
};

// D inherits from both B and C.
// Due to virtual inheritance, there is only one A subobject.
class D : public B, public C {};

int main() {
    D d;

    // There is no ambiguity now: only one copy of A exists.
    d.info();  // Calls A::info() without qualification.

    return 0;
}

// Output
// I am class A (virtually inherited).

/*
Explanation:
By marking B and C with virtual public A, class D contains a single A subobject. The
call d.info() is resolved unambiguously.

 */