/*
======================================
  MATH UTILITIES IMPLEMENTATION FILE
======================================

📌 **What is an Implementation File?**
   - Defines the functions declared in the header file.
   - Keeps main files **clean and modular**.
*/

#include "math_utils.h"  // Include the function declarations
#include <stdexcept>      // For error handling

// Define math functions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Error: Division by zero!");
    }
    return a / b;
}