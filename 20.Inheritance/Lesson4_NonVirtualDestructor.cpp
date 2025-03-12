/* ==========================================================================
Lesson 4: The Importance of Virtual Destructors

In this lesson we illustrate why a base class destructor should be declared as virtual.
Without a virtual destructor, if you delete a derived class object through a base class pointer,
the derived class destructor might not be called, potentially leading to resource leaks
or other undefined behavior.

Below, we compare a base class with a non-virtual destructor (not recommended)
to show what can go wrong.
========================================================================== */

// Lesson4_NonVirtualDestructor.cpp

#include <iostream>

class Base {
public:
    Base() { std::cout << "Base constructor called." << std::endl; }
    // Non-virtual destructor: not safe for polymorphic deletion.
    ~Base() { std::cout << "Base destructor called." << std::endl; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor called." << std::endl; }
    ~Derived() { std::cout << "Derived destructor called." << std::endl; }
};

int main() {
    std::cout << "Creating a Derived object with a Base pointer (non-virtual destructor)..." << std::endl;
    Base* ptr = new Derived();
    std::cout << "Deleting the Base pointer..." << std::endl;
    // Only Base's destructor will be called—not Derived's—which is incorrect for proper cleanup.
    delete ptr;
    return 0;
}