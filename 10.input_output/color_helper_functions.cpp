/* ### File: color_helper_functions.cpp ###
   ### Course 3: Using Helper Functions for Colored Output in C++ ###

   **Overview**
   This file introduces helper functions to simplify colored output and error 
   messages. By encapsulating colors into functions, the code is cleaner and 
   more maintainable.

   **Key Concepts**
   - Defining functions for colored output
   - Using helper functions to color text for input, success, and error messages
*/

#include <iostream>
#include <string>

// ANSI escape codes for colors
const std::string RED     = "\033[31m";
const std::string GREEN   = "\033[32m";
const std::string CYAN    = "\033[36m";
const std::string RESET   = "\033[0m";

// Function to output a message in cyan (for prompts)
void printPrompt(const std::string& message) {
    std::cout << CYAN << message << RESET;
}

// Function to output a message in green (for success messages)
void printSuccess(const std::string& message) {
    std::cout << GREEN << message << RESET << std::endl;
}

// Function to output a message in red (for error messages)
void printError(const std::string& message) {
    std::cout << RED << message << RESET << std::endl;
}

int main() {
    int age;
    std::string name;

    // Use helper function to prompt user for name
    printPrompt("Enter your name: ");
    std::getline(std::cin, name);
    printSuccess("Hello, " + name + "!");

    // Use helper function to prompt for age
    printPrompt("Enter your age: ");
    std::cin >> age;

    if (std::cin.fail()) {
        printError("Invalid input. Please enter a valid number.");
        std::cin.clear();              // Clear error state
        std::cin.ignore(100, '\n');    // Ignore remaining characters in buffer
    } else {
        printSuccess("You entered: " + std::to_string(age) + " years old.");
    }

    return 0;
}

/*
Explanation:
1. Helper Functions:
   - `printPrompt`: Displays prompts in cyan.
   - `printSuccess`: Displays success messages in green.
   - `printError`: Displays error messages in red.

2. Encapsulation:
   - Encapsulating color formatting in functions reduces repetition and 
     centralizes color usage, making the code more readable and easier to update.
*/