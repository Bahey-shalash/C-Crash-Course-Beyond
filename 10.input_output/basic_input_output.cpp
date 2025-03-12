/* ### File: basic_input_output.cpp ###
   ### Course: Basic User Input and Output in C++ ###

   **Overview**
   This file demonstrates the basics of input and output in C++. It includes:
   - Prompting the user for different types of data
   - Reading and displaying the data
   - Basic error handling for invalid input

   **Key Concepts**
   - Using `cin` for input and `cout` for output
   - Reading different data types (int, double, string)
   - Handling basic input errors
*/

#include <iostream>
#include <string>

int main() {
    // Declare variables to store user input
    int age;
    double salary;
    std::string name;

    // Prompt the user for their age
    std::cout << "Enter your age: ";
    std::cin >> age;

    // Check if the input was valid
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid integer for age." << std::endl;
        std::cin.clear();              // Clear the error state
        std::cin.ignore(100, '\n');    // Ignore remaining characters in the input buffer
    } else {
        std::cout << "You entered: " << age << " years old." << std::endl;
    }

    // Clear the input buffer and prompt for the user's name
    std::cout << "Enter your name: ";
    std::cin.ignore();                 // Consume any leftover newline character
    std::getline(std::cin, name);      // Read an entire line of text

    std::cout << "Hello, " << name << "!" << std::endl;

    // Prompt the user for their salary
    std::cout << "Enter your salary: ";
    std::cin >> salary;

    // Check if the salary input was valid
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid number for salary." << std::endl;
        std::cin.clear();              // Clear the error state
        std::cin.ignore(100, '\n');    // Ignore remaining characters in the input buffer
    } else {
        std::cout << "Your salary is: $" << salary << std::endl;
    }

    return 0;
}

/*
Expected Output:
1. If the user provides valid input:
   Enter your age: 25
   You entered: 25 years old.
   Enter your name: Alice Johnson
   Hello, Alice Johnson!
   Enter your salary: 55000
   Your salary is: $55000

2. If the user provides invalid input:
   Enter your age: twenty
   Invalid input. Please enter a valid integer for age.
*/