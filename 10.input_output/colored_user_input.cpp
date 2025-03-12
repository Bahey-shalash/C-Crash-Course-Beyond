/* ### File: colored_user_input.cpp ###
   ### Course 2: Using Colors for Input Prompts and Error Messages ###

   **Overview**
   This file demonstrates using colors to highlight user prompts and 
   error messages, making them stand out for better user interaction.

   **Key Concepts**
   - Adding color to prompts and output messages
   - Using colors to display error messages for invalid input
   - Resetting color after each message
*/

#include <iostream>
#include <string>

int main() {
    // ANSI escape codes for colors
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string CYAN    = "\033[36m";
    const std::string RESET   = "\033[0m";

    int age;
    std::string name;

    // Prompt user for name in cyan
    std::cout << CYAN << "Enter your name: " << RESET;
    std::getline(std::cin, name);
    std::cout << GREEN << "Hello, " << name << "!" << RESET << std::endl;

    // Prompt user for age with error handling in red
    std::cout << CYAN << "Enter your age: " << RESET;
    std::cin >> age;

    if (std::cin.fail()) {
        std::cout << RED << "Invalid input. Please enter a valid number." << RESET << std::endl;
        std::cin.clear();              // Clear error state
        std::cin.ignore(100, '\n');    // Ignore remaining characters in buffer
    } else {
        std::cout << GREEN << "You entered: " << age << " years old." << RESET << std::endl;
    }

    return 0;
}

/*
Explanation:
1. Colored Prompts and Responses:
   - Prompts are displayed in cyan to make them distinct.
   - Successful messages are in green.
   - Error messages are in red, making them stand out.

2. Resetting After Each Use:
   - The `RESET` constant resets color to default to avoid coloring 
     subsequent text unintentionally.
*/