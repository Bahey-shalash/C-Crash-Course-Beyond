/*
    ### C++ Course: Functions and the Principles of Abstraction and Reusability
    
    Functions promote abstraction and reusability by:
    1. Abstracting complex tasks into named blocks, simplifying code.
    2. Allowing reusable code blocks that can be called multiple times.

    Example: A function to calculate factorial, reusable and abstracting the logic from main.
*/

#include <iostream>
using namespace std;

// Function to calculate factorial of a number
int factorial(int n);

int main() {
    int num = 5;
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    return 0;
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

/*
    - Abstraction: The `factorial` function hides the details of the factorial calculation, 
      allowing us to use it without needing to know how it works.
    - Reusability: The `factorial` function can be called with any integer value.

    Compile and run:
        g++ functions_abstraction_reusability.cpp -o functions_abstraction_reusability
        ./functions_abstraction_reusability
*/