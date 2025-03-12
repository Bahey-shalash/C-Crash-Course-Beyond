/* ==========================================================================
Lesson 5: The ‘override’ and ‘final’ Specifiers

C++11 introduced override and final to improve code safety:
	•	override: Tells the compiler that a function is meant to override a base class virtual function.
	•	final: Prevents further overriding of a virtual function or prevents a class from being inherited.

This lesson shows how to use these specifiers.
========================================================================== */
// Lesson5_Override_Final.cpp

#include <iostream>

class Base {
public:
    virtual void display() {
        std::cout << "Base::display()" << std::endl;
    }
};

class Derived : public Base {
public:
    // Use 'override' to ensure we're correctly overriding Base::display().
    void display() override {
        std::cout << "Derived::display()" << std::endl;
    }
};

class MoreDerived final : public Derived {
public:
    // This override is valid, but no further class can inherit from MoreDerived.
    void display() override {
        std::cout << "MoreDerived::display()" << std::endl;
    }
};

// The following would produce a compile-time error because MoreDerived is final:
// class Attempt : public MoreDerived {};

int main() {
    Base* b = new Derived();
    b->display(); // Calls Derived::display()
    
    b = new MoreDerived();
    b->display(); // Calls MoreDerived::display()
    
    delete b;
    return 0;
}