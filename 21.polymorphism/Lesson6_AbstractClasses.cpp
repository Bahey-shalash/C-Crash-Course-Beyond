/* ==========================================================================
Lesson 6: Pure Virtual Functions and Abstract Classes

A pure virtual function is declared by assigning 0 to the virtual function. This makes
the class abstract (i.e. it cannot be instantiated) and forces derived classes to provide an
implementation.

This lesson demonstrates how to declare a pure virtual function and create abstract classes.
========================================================================== */
// Lesson6_AbstractClasses.cpp

#include <iostream>

// Abstract base class with a pure virtual function.
class Animal {
public:
    // Pure virtual function makes Animal abstract.
    virtual void makeSound() = 0;
    
    // Virtual destructor for proper cleanup.
    virtual ~Animal() {
        std::cout << "Animal destructor called." << std::endl;
    }
};

class Dog : public Animal {
public:
    // Implement the pure virtual function.
    void makeSound() override {
        std::cout << "Dog barks: Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    // Implement the pure virtual function.
    void makeSound() override {
        std::cout << "Cat meows: Meow!" << std::endl;
    }
};

int main() {
    // Animal a; // Error: Cannot instantiate an abstract class.
    
    // Create objects of derived classes.
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    
    dog->makeSound();
    cat->makeSound();
    
    delete dog;
    delete cat;
    return 0;
}