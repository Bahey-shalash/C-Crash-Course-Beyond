/* ==========================================================================
Lesson 3: Virtual Destructors

When using polymorphism, the destructor of the base class should be declared
as virtual. This ensures that when you delete a derived object through a base
class pointer, the derived class’s destructor is called, properly cleaning up
resources.

This lesson demonstrates the importance of virtual destructors.
========================================================================== */
// Lesson3_VirtualDestructors.cpp

#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor called." << std::endl;
    }
    // Virtual destructor to ensure proper cleanup.
    virtual ~Base() {
        std::cout << "Base destructor called." << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructor called." << std::endl;
    }
    ~Derived() {
        std::cout << "Derived destructor called." << std::endl;
    }
};

int main() {
    // Create a Derived object using a Base pointer.
    Base* obj = new Derived();
    // When deleting, both Derived and Base destructors are invoked.
    delete obj;
    return 0;
}