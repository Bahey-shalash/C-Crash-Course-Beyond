/* ==========================================================================
Lesson 1: Basic Multiple Inheritance

In multiple inheritance, a derived class inherits from more than one base class.
This lesson demonstrates a simple example of multiple inheritance without any conflicts.
We define two base classes, Base1 and Base2, and a derived class that inherits from both.
========================================================================== */
// Lesson1_BasicMultipleInheritance.cpp

#include <iostream>
using namespace std;

// First base class.
class Base1 {
public:
    void methodBase1() const {
        cout << "Method of Base1." << endl;
    }
};

// Second base class.
class Base2 {
public:
    void methodBase2() const {
        cout << "Method of Base2." << endl;
    }
};

// Derived class that inherits from both Base1 and Base2.
class Derived : public Base1, public Base2 {
public:
    void methodDerived() const {
        cout << "Method of Derived." << endl;
    }
};

int main() {
    Derived d;
    // The Derived object can use methods from both base classes.
    d.methodBase1();
    d.methodBase2();
    d.methodDerived();
    return 0;
}
// Output
// Method of Base1.
// Method of Base2.
// Method of Derived.