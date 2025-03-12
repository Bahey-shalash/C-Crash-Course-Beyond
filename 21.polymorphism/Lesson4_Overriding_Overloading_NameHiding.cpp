/* ==========================================================================
Lesson 4: Overriding vs. Overloading and Name Hiding
        •	Overriding:
A derived class redefines a virtual function from its base class using the same
signature. •	Overloading: Functions with the same name in the same scope but with
different parameter lists. •	Name Hiding (Masquage): When a derived class declares a
function with the same name as one in the base class, all base class versions of that
function become hidden. You can bring them into scope with a using declaration.

This lesson demonstrates these concepts.
========================================================================== */
// Lesson4_Overriding_Overloading_NameHiding.cpp

#include <iostream>

class Base {
public:
    // Two overloaded functions in Base.
    virtual void foo(int x) { std::cout << "Base::foo(int): " << x << std::endl; }
    virtual void foo(double x) {
        std::cout << "Base::foo(double): " << x << std::endl;
    }
};

class Derived : public Base {
public:
    // This function overrides Base::foo(int).
    void foo(int x) override { std::cout << "Derived::foo(int): " << x << std::endl; }

    // This is an overload in Derived.
    void foo(char x) { std::cout << "Derived::foo(char): " << x << std::endl; }

    // Uncomment the following line to bring Base's foo(double) into Derived's scope:
    // using Base::foo;
};

int main() {
    Derived d;
    d.foo(10);   // Calls Derived::foo(int)
    d.foo('A');  // Calls Derived::foo(char)

    // The following would cause an error because Base::foo(double) is hidden.
    // d.foo(3.14);

    // You can call the hidden version explicitly:
    d.Base::foo(3.14);

    return 0;
}

/*
•Derived::foo(int) overrides Base::foo(int), replacing it in the vtable.
•Derived::foo(char) is a new function, but it has the same name (foo) as
the functions in Base.

Now, because Derived has at least one function named foo, all functions named foo in
Base are hidden.

What Happens When We Call foo(3.14)?

Derived d;
d.foo(3.14);  // ERROR: No matching function in Derived

Why does this fail?
•The compiler searches for foo(double) in Derived first.
•But Derived only has:
    •foo(int)
    •foo(char)
•foo(double) was only declared in Base, but because Derived has a foo(...), all
versions of foo in Base are hidden. 
•The compiler does not automatically look in Base
because Derived has its own foo functions.


 */