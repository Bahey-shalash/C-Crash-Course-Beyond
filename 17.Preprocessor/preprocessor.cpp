/*
====================================
   C++ PREPROCESSOR: IN-DEPTH GUIDE (IMPROVED)
====================================
The C++ preprocessor processes source code before actual compilation.
It handles tasks such as:
- Including header files
- Defining macros
- Conditional compilation
- Preventing multiple inclusions of files

This guide covers:
1. The role of the preprocessor
2. #include directives and header files
3. #define directives and macros
4. Conditional compilation (#ifdef, #ifndef, #if, #else, #endif)
5. Debugging tools (assert and NDEBUG)
6. Preventing multiple inclusions (header guards)
*/

// ================================
// 1. INCLUDE DIRECTIVES
// ================================

// Standard headers
#include <cassert>   // Provides the assert() macro for debugging
#include <cmath>     // Includes mathematical functions and constants
#include <iostream>  // Provides std::cout and std::endl

// User-defined header with header guards (ensure "my_header.h" exists and is properly
// guarded)
#include "my_header.h"

// ================================
// 2. MACRO DEFINITIONS
// ================================

// Constant replacement
#define PI 3.14159

// Function-like macro for calculating the square of a number.
// Parentheses ensure correct evaluation in complex expressions.
#define SQUARE(x) ((x) * (x))

// Uncomment the following line to enable debug mode via conditional compilation.
// Alternatively, define DEBUG_MODE as a compiler flag (e.g., -DDEBUG_MODE).
#define DEBUG_MODE

// ================================
// 3. MAIN FUNCTION
// ================================

int main() {
    // Display constant values and macro results.
    std::cout << "Pi: " << PI << std::endl;
    std::cout << "Square of 5: " << SQUARE(5) << std::endl;

// --------------------------
// Conditional Compilation:
// --------------------------
// Checks if DEBUG_MODE is defined. This allows including or excluding code
// based on whether you are in debug or release mode.
#ifdef DEBUG_MODE
    std::cout << "Debug mode is ON" << std::endl;
#else
    std::cout << "Debug mode is OFF" << std::endl;
#endif

    // --------------------------
    // Debugging with assert():
    // --------------------------
    // The assert() macro checks that a condition is true.
    // If the condition is false, the program terminates with an error message.
    int a = 10;
    assert(a > 0 && "Variable 'a' must be positive.");

    // Uncommenting the following line would trigger an assertion failure:
    // assert(a < 0 && "Variable 'a' should be negative (forced failure).");

    return 0;
}