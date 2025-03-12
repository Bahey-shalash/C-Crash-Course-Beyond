/*
    LESSON 1: The `static` Keyword Outside of Classes (File Scope & Function Scope)
    
    The `static` keyword in C++ changes **storage duration** and **visibility**.
    
    🔹 In **global scope**:
        - `static` variables/functions are **limited to the current file**.
        - They **cannot be accessed from other files**.
    
    🔹 In **function scope**:
        - `static` local variables **retain their value** between function calls.
        - Unlike normal local variables, they are **initialized only once**.
    
    ✅ This file demonstrates:
        1️⃣ `static` global variables (file scope)
        2️⃣ `static` functions (file scope)
        3️⃣ `static` local variables (function scope)
*/

#include <iostream>

// ---------------------------------------------
// 1️⃣ `static` Global Variable (File Scope)
// ---------------------------------------------

// Normal global variable (accessible everywhere in the program)
int globalVar = 10;

// `static` global variable - **restricted to this file only**
static int staticGlobalVar = 20;

// ---------------------------------------------
// 2️⃣ `static` Function (File Scope)
// ---------------------------------------------

// This function is **restricted to this file** (file-private)
static void privateFunction() {
    std::cout << "This function is private to this file.\n";
}

// A normal function that calls `static` function
void normalFunction() {
    privateFunction(); // Allowed since both are in the same file
}

int main() {
    std::cout << "Global variable: " << globalVar << "\n";
    std::cout << "Static global variable: " << staticGlobalVar << "\n";
    
    // Calling normalFunction, which calls privateFunction
    normalFunction();

    std::cout << "----------------------\n";

    // Testing static local variable behavior
    std::cout << "Calling counter function multiple times:\n";
    counterFunction();
    counterFunction();
    counterFunction();

    std::cout << "----------------------\n";

    // Testing static inside a function
    std::cout << "Calling computeOnce() multiple times:\n";
    computeOnce();
    computeOnce();
    computeOnce();

    return 0;
}

// ---------------------------------------------
// 3️⃣ `static` Local Variable (Function Scope)
// ---------------------------------------------

void counterFunction() {
    /*
        `static` local variable:
        - Unlike normal local variables, it **persists across function calls**.
        - It is **initialized only once** and retains its value.
    */
    static int count = 0;  // Initialized only once
    count++;  // Value is retained across function calls
    std::cout << "Counter: " << count << "\n";
}

void computeOnce() {
    /*
        `static` can be used in functions to **execute logic only once**.
        - Useful for caching and initialization.
    */
    static bool initialized = false;
    if (!initialized) {
        std::cout << "Initializing...\n";
        initialized = true;
    } else {
        std::cout << "Already initialized.\n";
    }
}