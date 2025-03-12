/* ### Course 1: Basics of `std::string` and Concatenation ###

   In this course, we introduce the `std::string` type in C++, which is a 
   convenient way to work with text data. Unlike C-style strings (char arrays),
   `std::string` provides numerous built-in methods for easy manipulation.

   **Key Concepts:**
   - Declaring and initializing `std::string` variables
   - Basic concatenation of `std::string` objects
*/

#include <iostream>
#include <string>

int main() {
    // Initializing strings
    std::string school("EPFL"); // Direct initialization with a string literal
    std::string firstName = "John";
    std::string lastName = "Doe";

    // Concatenation using `+` operator
    std::string fullName = firstName + ' ' + lastName; // Space added between names
    std::cout << "Full Name: " << fullName << '\n';

    // Concatenation with assignment
    fullName += " (" + school + ')';
    std::cout << "Full Name with School: " << fullName << '\n';

    return 0;
}

/*
Output:
Full Name: John Doe
Full Name with School: John Doe (EPFL)

Explanation:
- `+` operator allows us to concatenate `std::string` and `char` objects directly.
- `+=` operator appends text to an existing `std::string`.
*/