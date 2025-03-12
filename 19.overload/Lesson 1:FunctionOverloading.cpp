/* ==========================================================================
Lesson 1: Function Overloading Basics

This lesson demonstrates how to overload functions.
•Two functions can share the same name as long as their parameter lists differ.

•The function signature consists of the function name and its parameters
(number, types, order). The return type is not part of the signature.

In this example:
- show(int) prints an integer.
- show(double) prints a double.

Note: Uncommenting the duplicate show(int) (differing only in return type)
will result in a compile-time error.
========================================================================== */

// Lesson1_FunctionOverloading.cpp

#include <iostream>

// Overloaded function: takes an int.
int show(int x) {
    std::cout << "show(int): " << x << std::endl;
    return x;
}

// Overloaded function: takes a double.
double show(double x) {
    std::cout << "show(double): " << x << std::endl;
    return x;
}

/*
This version is illegal because it has the same signature as show(int)
 even though the return type is different:

int show(int x) {return x;}
*/

int main() {
    // Calls show(int)
    show(10);

    // Calls show(double)
    show(3.14);

    return 0;
}