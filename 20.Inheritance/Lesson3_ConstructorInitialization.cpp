/* ==========================================================================
Lesson 3: Constructor Initialization Lists in Inheritance

In this lesson we demonstrate how to explicitly call a base class constructor
from a derived class using an initialization list. This is required when:
	•	The base class does not have a default constructor.
	•	You wish to initialize the base class with specific parameters.

We define a base class “Person” with a parameterized constructor, and a derived class “Student”
that calls the Person constructor explicitly in its initializer list.
========================================================================== */
// Lesson3_ConstructorInitialization.cpp

#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
public:
    // Parameterized constructor.
    Person(const std::string& n) : name(n) {
        std::cout << "Person constructor called for " << name << std::endl;
    }
    ~Person() {
        std::cout << "Person destructor called for " << name << std::endl;
    }
    void introduce() {
        std::cout << "Hello, my name is " << name << std::endl;
    }
};

class Student : public Person {
private:
    int studentID;
public:
    // The Student constructor explicitly calls the Person constructor in its initializer list.
    Student(const std::string& n, int id) : Person(n), studentID(id) {
        std::cout << "Student constructor called for " << name << " with ID " << studentID << std::endl;
    }
    ~Student() {
        std::cout << "Student destructor called for " << name << std::endl;
    }
    void showID() {
        std::cout << name << "'s student ID is " << studentID << std::endl;
    }
};

int main() {
    std::cout << "Creating a Student object..." << std::endl;
    Student s("Alice", 12345);
    s.introduce();
    s.showID();
    // When s goes out of scope, destructors are called: Student's destructor then Person's destructor.
    return 0;
}