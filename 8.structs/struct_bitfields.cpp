/* ### File: struct_bitfields.cpp ###
   ### Course 3: Using Bit Fields in C++ Structs and Bitwise Operators ###

   **Overview**
   Bit fields in C++ allow for memory-efficient storage within structs by 
   specifying the number of bits allocated for each member. This is particularly 
   useful when working with limited memory or optimizing for space.

   We’ll also cover bitwise operators, which can be used with bit fields or 
   any other integer type for efficient data manipulation at the bit level.

   **Key Concepts**
   - Declaring bit fields in a struct
   - Using bitwise operators to manipulate bits
*/

#include <iostream>

// Define a struct with bit fields to optimize memory usage
struct StatusFlags {
    unsigned int isActive : 1;     // 1-bit field boolean variable
    unsigned int isVisible : 1;    // 1-bit field
    unsigned int hasError : 1;     // 1-bit field
    unsigned int errorCode : 4;    // 4-bit field for error codes (0-15)
};

int main() {
    // Initialize a StatusFlags struct
    StatusFlags flags = {1, 1, 0, 0b1011}; // Using binary for clarity

    std::cout << "Status:\n";
    std::cout << "  Active: " << flags.isActive << '\n';
    std::cout << "  Visible: " << flags.isVisible << '\n';
    std::cout << "  Has Error: " << flags.hasError << '\n';
    std::cout << "  Error Code: " << flags.errorCode << '\n';

    // Using bitwise operators
    int permissions = 0b1100;   // Example permissions: 1100 in binary
    permissions |= 0b0001;      // Set the lowest bit
    permissions &= ~0b0100;     // Clear the third bit

    std::cout << "\nUpdated permissions (binary): " << std::bitset<4>(permissions) << '\n';

    return 0;
}

/*
Explanation:
- **Bit Fields**: The `StatusFlags` struct demonstrates the use of bit fields, 
  reducing memory usage by allocating only a few bits per member instead of 
  full bytes. `errorCode` uses 4 bits, allowing values from 0 to 15.
  
- **Bitwise Operators**:
  - `|` (OR): Sets specific bits to 1.
  - `&` (AND): Clears specific bits.
  - `~` (NOT): Inverts bits.
  
  The `permissions` example demonstrates setting and clearing individual bits.
*/