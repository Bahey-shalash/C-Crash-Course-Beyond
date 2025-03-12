/* ### File: basic_enum.cpp ###
   ### Course 1: Basic `enum` in C++ ###

   This file demonstrates the basic usage of `enum` in C++.
   `enum` defines a set of named integer constants, improving code readability 
   and helping organize related constants.

   **Key Concepts**
   - Declaring and initializing an `enum`
   - Default values and custom value assignments
   - Using `enum` constants in switch statements and conditions
*/

#include <iostream>

enum Day {
    MONDAY,         // Default value: 0
    TUESDAY,        // 1
    WEDNESDAY,      // 2
    THURSDAY = 10,  // Custom value: 10
    FRIDAY,         // 11 (continues from previous value)
    SATURDAY = 20,  // Custom value: 20
    SUNDAY          // 21
};

int main() {
    Day today = WEDNESDAY;

    // Using `enum` in a switch statement
    switch (today) {
        case MONDAY:
            std::cout << "It's Monday!\n";
            break;
        case WEDNESDAY:
            std::cout << "It's Wednesday!\n";
            break;
        case FRIDAY:
            std::cout << "It's Friday!\n";
            break;
        default:
            std::cout << "It's another day.\n";
            break;
    }

    // Accessing enum values directly
    std::cout << "Enum value for THURSDAY: " << THURSDAY << '\n';
    std::cout << "Enum value for SATURDAY: " << SATURDAY << '\n';

    return 0;
}

/*
   Expected Output:
   It's Wednesday!
   Enum value for THURSDAY: 10
   Enum value for SATURDAY: 20
*/