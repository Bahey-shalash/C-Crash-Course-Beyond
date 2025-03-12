/* ==========================================================================
Lesson 7: Heterogeneous Collections Using Pointers

Polymorphism allows us to store pointers to different derived class objects in a single
collection, as long as they share a common base class. This is especially useful when
dealing with abstract classes.

This lesson demonstrates creating a heterogeneous collection using a vector of
base class pointers.
========================================================================== */
// Lesson7_HeterogeneousCollections.cpp

#include <iostream>
#include <vector>
#include <memory> // For smart pointers

// Abstract base class.
class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() {
        std::cout << "Animal destroyed." << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Dog barks: Woof!" << std::endl;
    }
    ~Dog() {
        std::cout << "Dog destroyed." << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Cat meows: Meow!" << std::endl;
    }
    ~Cat() {
        std::cout << "Cat destroyed." << std::endl;
    }
};

int main() {
    // Use a vector of smart pointers (unique_ptr) to hold different Animal objects.
    std::vector<std::unique_ptr<Animal>> animals;
    
    // Add various derived objects.
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());
    
    // Iterate over the collection and call the virtual method.
    for (const auto& animal : animals) {
        animal->makeSound(); // Calls the appropriate derived function.
    }
    
    // Smart pointers automatically clean up.
    return 0;
}