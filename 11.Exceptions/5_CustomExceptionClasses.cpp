/*
File: 5_CustomExceptionClasses.cpp
Description: Demonstrates how to create and use a custom exception class.
*/

#include <iostream>
#include <exception>

// Define a custom exception class by inheriting from std::exception.
class CustomError : public std::exception {
public:
    // Override what() to provide a custom error message.
    const char* what() const noexcept override {
        return "CustomError: An error occurred in the custom exception class.";
    }
};

void functionThatThrowsCustom() {
    std::cout << "Inside functionThatThrowsCustom: About to throw CustomError." << std::endl;
    throw CustomError();
}

int main() {
    std::cout << "=== Lesson 5: Custom Exception Classes ===" << std::endl;
    
    // Example 1: Throwing and catching the custom exception from a function.
    try {
        functionThatThrowsCustom();
    } catch (const CustomError& e) {
        std::cout << "Caught CustomError: " << e.what() << std::endl;
    }
    
    // Example 2: Throwing the custom exception directly in main.
    try {
        std::cout << "\nAdditional Example: Throwing CustomError directly in main." << std::endl;
        throw CustomError();
    } catch (const CustomError& e) {
        std::cout << "Caught CustomError: " << e.what() << std::endl;
    }
    
    return 0;
}