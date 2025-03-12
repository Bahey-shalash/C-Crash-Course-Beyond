/* ==========================================================================
Lesson 4: Construction and Destruction Order in Virtual Inheritance

Virtual inheritance affects the order in which constructors and destructors are called.
When using virtual inheritance, the virtual base class is constructed before any
non-virtual base classes, regardless of the order in the inheritance list. Similarly,
destructors are called in the reverse order.

This lesson demonstrates the construction and destruction order in a diamond scenario.
========================================================================== */

// Lesson4_DiamondConstructionOrder.cpp

#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A constructor called." << endl; }
    virtual ~A() { cout << "A destructor called." << endl; }
};

// B virtually inherits from A.
class B : virtual public A {
public:
    B() { cout << "B constructor called." << endl; }
    ~B() { cout << "B destructor called." << endl; }
};

// C virtually inherits from A.
class C : virtual public A {
public:
    C() { cout << "C constructor called." << endl; }
    ~C() { cout << "C destructor called." << endl; }
};

// D inherits from B and C.
class D : public B, public C {
public:
    D() { cout << "D constructor called." << endl; }
    ~D() { cout << "D destructor called." << endl; }
};

int main() {
    cout << "Creating D object:" << endl;
    D d;
    cout << "D object created. Now destructing..." << endl;
    return 0;
}
/*

Expected Output (order may vary slightly by compiler but follows these principles):

A constructor called.
B constructor called.
C constructor called.
D constructor called.
D destructor called.
C destructor called.
B destructor called.
A destructor called.


Explanation:
•Construction:
The virtual base class A is constructed first. Then B and C are constructed, followed
by D. 

•Destruction: D is destroyed first, then C and B, and finally A is destroyed.
This order ensures proper cleanup of shared resources.
*/
