/*
======================================
  COURSE 2: BREAKING CODE INTO SEPARATE FILES
======================================

📌 **Why Separate Code into Files?**
   - As programs grow, one big file becomes **hard to manage**.
   - We split code into **Header Files (.h)** and **Implementation Files (.cpp)**.
   - This makes **code modular, reusable, and easy to debug**.

📌 **Structure of a Modular Program**
   - **Header File (`math_utils.h`)** → Declares functions (like a blueprint).
   - **Implementation File (`math_utils.cpp`)** → Defines functions.
   - **Main File (`main.cpp`)** → Uses the module.

📌 **Example: Math Utilities Module**
   - We will create a module for simple math functions.
   - `math_utils.h` → Function declarations.
   - `math_utils.cpp` → Function definitions.
   - `main.cpp` → Uses the functions.


📂 Modular_Separation/
 ├── math_utils.h       // Header file (Interface)
 ├── math_utils.cpp     // Source file (Implementation)
 ├── main.cpp           // Main program (Uses the module)

*/

#include <iostream>

#include "math_utils.h"  // Include our custom module

using namespace std;

int main() {
    double a = 10, b = 5;

    cout << "Addition: " << add(a, b) << endl;
    cout << "Subtraction: " << subtract(a, b) << endl;
    cout << "Multiplication: " << multiply(a, b) << endl;
    cout << "Division: " << divide(a, b) << endl;

    return 0;
}