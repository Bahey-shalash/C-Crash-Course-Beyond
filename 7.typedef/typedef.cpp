/* ### File: typedef_advanced.cpp ###
   ### Course 1: Understanding `typedef` in C++ ###

   **Overview**
   `typedef` is used to create aliases for existing types, which can simplify 
   code, enhance readability, and make types easier to change if needed. 
   `typedef` is especially useful in complex data structures and for 
   portability, though `using` is often preferred in modern C++ for type aliases.

   **Key Concepts**
   - Basic `typedef` usage
   - Creating aliases for complex types (e.g., function pointers, structures)
   - Advantages and disadvantages of `typedef`
*/

#include <iostream>
#include <vector>

// Basic `typedef` example: creating an alias for a fundamental type
typedef unsigned long long ULL;

// Using `typedef` with more complex types
typedef std::vector<int> IntVector;
typedef std::vector<std::vector<int>> Matrix;

// `typedef` with function pointers
typedef void (*FunctionPointer)(int);

void printInt(int x) {
    std::cout << "Integer: " << x << '\n';
}

int main() {
    // Using a `typedef` alias for an unsigned long long variable
    ULL largeNumber = 123456789012345ULL;
    std::cout << "Large number (ULL): " << largeNumber << '\n';

    // Using typedef with vector and matrix types
    IntVector numbers = {1, 2, 3, 4, 5};
    Matrix grid = {{1, 2}, {3, 4}, {5, 6}};

    std::cout << "First number: " << numbers[0] << '\n';
    std::cout << "First row in grid: " << grid[0][0] << ", " << grid[0][1] << '\n';

    // Using `typedef` with a function pointer
    FunctionPointer fp = &printInt;
    fp(10);

    return 0;
}

/*
Advantages of `typedef`:
- Improves readability, especially for complex types.
- Can make future changes easier, as type definitions need only be updated in one place.
- Useful for platform-dependent code (e.g., `typedef` different integer types for different platforms).

Disadvantages of `typedef`:
- Can lead to confusion if overused, making code harder to understand.
- Lacks clarity with complex types in comparison to `using` (preferred in modern C++).

Note: `typedef` can be replaced with `using` in C++11 for improved readability:
   using ULL = unsigned long long;
*/