/*
    ### C++ Course: Scope, Lifetime, and the Stack in Functions

    This file covers:
    1. Variable Scope: Determines where a variable can be accessed.
    2. Variable Lifetime: Defines how long a variable exists in memory.
    3. Stack Behavior: Shows how functions and local variables are managed on the stack.
*/

#include <iostream>
using namespace std;

void functionA();
void functionB();

int main() {
    int x = 10;  // Local to `main`
    cout << "In main, x: " << x << endl;

    functionA();
    functionB();

    // Scope Example
    // cout << "Trying to access y from main: " << y << endl; // Error: `y` is not in scope

    return 0;
}

void functionA() {
    int y = 20;  // Local to `functionA`
    cout << "In functionA, y: " << y << endl;
}

void functionB() {
    static int z = 0;  // `z` retains its value between calls
    z++;
    cout << "In functionB, z: " << z << endl;
}

/*
    - Scope: `y` in `functionA` is not accessible in `main`.
    - Lifetime: `x` in `main` exists only for the duration of `main`, while `z` in `functionB` retains its value.
    - Stack: Each function call creates a new frame on the stack with local variables that are cleaned up after the function exits.

    Compile and run:
        g++ functions_scope_lifetime.cpp -o functions_scope_lifetime
        ./functions_scope_lifetime
*/