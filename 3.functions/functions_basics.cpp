/*
    ### C++ Course: Function Basics
    
    This file introduces the basics of functions in C++:
    1. Function Prototypes
    2. Function Definitions
    3. Calling Functions
    
    Functions allow us to create modular, reusable code blocks. A function consists of:
    - Prototype: Declares the function signature.
    - Definition: Contains the function body (implementation).
    - Call: Executes the function.
*/

#include <iostream>
using namespace std;

// Function Prototype: Declares a function without implementing it
int add(int a, int b);

// Main function
int main() {
    int x = 5, y = 10;
    // Calling the `add` function
    int sum = add(x, y);
    cout << "Sum: " << sum << endl;

    return 0;
}

// Function Definition: Implements the function logic
int add(int a, int b) {
    return a + b;
}

/*
    - The prototype `int add(int a, int b);` informs the compiler about the function’s name, 
      return type, and parameters, allowing the function to be used before its definition.
    - In `main`, `add` is called with two arguments (`x` and `y`).
    - The result is stored in `sum` and printed.
    
    Compile and run:
        g++ functions_basics.cpp -o functions_basics
        ./functions_basics
*/