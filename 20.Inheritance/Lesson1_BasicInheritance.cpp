/* ==========================================================================
Lesson 1: Basic Inheritance – Constructor and Destructor Order

In this lesson we demonstrate simple inheritance with a Base class and a Derived class.
Key points:
	•	When a derived object is created, the base class constructor is called first, then the derived constructor.
	•	When the object is destroyed (goes out of scope), the derived destructor is called first, then the base destructor.

We define a base class “Animal” and a derived class “Dog” to illustrate this order.
========================================================================== */
// Lesson1_BasicInheritance.cpp

#include <iostream>

class Animal {
public:
    Animal() {
        std::cout << "Animal constructor called." << std::endl;
    }
    ~Animal() {
        std::cout << "Animal destructor called." << std::endl;
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
};

int main() {
    std::cout << "Creating a Dog object..." << std::endl;
    Dog myDog;
    std::cout << "Dog object created." << std::endl;
    // When main() ends, myDog goes out of scope and the destructors are called in reverse order.
    return 0;
}