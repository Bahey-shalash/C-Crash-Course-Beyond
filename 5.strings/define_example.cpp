/* ### File: define_example.cpp ###
   ### Course 7: Using `#define` in C++ ###

   `#define` is a preprocessor directive in C++ that defines macros or constants.
   It performs text substitution before compilation, offering flexibility but 
   lacking type safety. Constants and inline functions are often preferred, but 
   `#define` is still commonly used in low-level programming.

   **Key Concepts**
   - Defining simple constants with `#define`
   - Using macros with parameters
   - Common pitfalls and alternatives to `#define`
*/

#include <iostream>

#define PI 3.14159       // Defining a constant for Pi for a project use pi from cmath
#define AREA(radius) (PI * (radius) * (radius)) // Macro with a parameter

int main() {
    // Using a simple `#define` constant
    std::cout << "Value of PI: " << PI << '\n';

    // Using a macro with a parameter to calculate area
    double radius = 5.0;
    std::cout << "Area of a circle with radius " << radius << ": " << AREA(radius) << '\n';

    // Demonstrating pitfalls with macros
    // Beware: `AREA(radius + 1)` expands to `(PI * (radius + 1) * (radius + 1))`
    std::cout << "Area with radius incremented by 1: " << AREA(radius + 1) << '\n';

    // Alternative to `#define` macros: use `const` and inline functions
    const double PiConst = 3.14159;

    auto area = [](double r) { return PiConst * r * r; }; // Inline lambda for area calculation
    std::cout << "Area (using inline function): " << area(radius) << '\n';

    return 0;
}

/*
   Expected Output:
   Value of PI: 3.14159
   Area of a circle with radius 5: 78.5398
   Area with radius incremented by 1: 113.097 (incorrect due to macro expansion)
   Area (using inline function): 78.5398
*/