/*
File: namespace_basic.cpp
Description:
  This file demonstrates the most basic usage of namespaces. It defines a namespace called 
  MathOperations that contains a function to add two numbers. The main() function shows how 
  to use the fully qualified name to call the function.

When to use namespaces:
  - To group related functions, classes, or variables.
  - To avoid naming collisions in larger projects or when integrating with libraries.
*/

#include <iostream>

namespace MathOperations {
    int add(int a, int b) {
        return a + b;
    }
}

int main() {
    int result = MathOperations::add(3, 4);
    std::cout << "3 + 4 = " << result << std::endl;
    return 0;
}
/*

g++ -std=c++17 namespace_basic.cpp -o namespace_basic
./namespace_basic

*/