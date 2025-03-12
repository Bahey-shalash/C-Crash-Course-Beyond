/*
======================================
  MATH UTILITIES HEADER FILE
======================================

📌 **What is a Header File?**
   - Declares functions but does not define them.
   - Used to share function prototypes across multiple files.
   - Helps keep code **clean and organized**.

📌 **Header Guards (`#ifndef ... #define ...`)**
   - Prevents multiple inclusions of the same file.
   - Ensures the compiler processes the header **only once**.

!never use `using namespace` in header files. It can cause name clashes and ambiguity.
*/

#ifndef MATH_UTILS_H  // Prevent multiple inclusions
#define MATH_UTILS_H

// Declare math functions
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

#endif // MATH_UTILS_H