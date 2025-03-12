/* ==========================================================================
Lesson 2: Function Overriding with Virtual Functions

In this lesson we demonstrate how a derived class can override a base class function.
To achieve polymorphic behavior (so that calls via a base class pointer invoke the derived version),
the base class function must be declared as virtual.

We define a base class “Animal” with a virtual function “speak()”
and a derived class “Dog” that overrides speak().
========================================================================== */
// Lesson2_FunctionOverriding.cpp

#include <iostream>

class Animal {
public:
    Animal() {
        std::cout << "Animal constructor called." << std::endl;
    }
    // Declare the destructor virtual to ensure proper cleanup in polymorphic use.
    virtual ~Animal() {
        std::cout << "Animal destructor called." << std::endl;
    }
    // Virtual function that can be overridden by derived classes.
    virtual void speak() {
        std::cout << "Animal speaks in a generic way." << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog() {
        std::cout << "Dog constructor called." << std::endl;
    }
    ~Dog() {
        std::cout << "Dog destructor called." << std::endl;
    }
    // Override the speak() function.
    void speak() override {
        std::cout << "Dog barks: Woof Woof!" << std::endl;
    }
};

int main() {
    std::cout << "Creating an Animal pointer to a Dog object..." << std::endl;
    Animal* pet = new Dog();
    pet->speak();  // Because speak() is virtual, Dog's version is called.
    delete pet;    // Proper deletion: Dog destructor then Animal destructor are invoked.
    return 0;
}