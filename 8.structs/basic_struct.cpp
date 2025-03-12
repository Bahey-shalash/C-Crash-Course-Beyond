/* ### File: basic_struct.cpp ###
   ### Course: Basics of `struct` in C++

   This course covers the basics of using `struct` in C++. A `struct` 
   (short for "structure") is a user-defined data type that groups multiple 
   variables under a single name, allowing us to model related data together.

   **Concepts Covered**
   - Defining a `struct`
   - Initializing and accessing struct members
   - Passing structs to functions

    **Note**
    - In C++, `struct` and `class` are similar, with the main difference being 
      that members of a `struct` are public by default, while members of a `class` 
      are private by default. will see that in details in the OOP folder.
*/

#include <iostream>
#include <string>

// Define a `struct` to represent a Person
struct Person {
    std::string name;  // Member: name of the person
    int age;           // Member: age of the person
    double height;     // Member: height of the person in meters
};

// Function to print information about a `Person`
// We use `const Person&` to avoid copying and to prevent modification
void printPersonInfo(const Person& person) {
    std::cout << "Name: " << person.name << '\n';
    std::cout << "Age: " << person.age << '\n';
    std::cout << "Height: " << person.height << " m\n";
}

int main() {
    // Initialize a `Person` instance by setting each member individually
    Person person1;
    person1.name = "Alice";
    person1.age = 30;
    person1.height = 1.65;

    // Initialize another `Person` using an aggregate initializer (C++11 and later)
    Person person2 = {"Bob", 25, 1.80};

    // Access and print each person's information using a function
    std::cout << "Person 1 Info:\n";
    printPersonInfo(person1);

    std::cout << "\nPerson 2 Info:\n";
    printPersonInfo(person2);

    // Modifying a member of `person1`
    person1.age += 1;  // Alice has a birthday
    std::cout << "\nAfter modifying age:\n";
    printPersonInfo(person1);

    return 0;
}

/*
Expected Output:
Person 1 Info:
Name: Alice
Age: 30
Height: 1.65 m

Person 2 Info:
Name: Bob
Age: 25
Height: 1.8 m

After modifying age:
Name: Alice
Age: 31
Height: 1.65 m
*/

