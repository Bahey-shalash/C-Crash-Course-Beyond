/*
======================================
  COURSE 1: INTRODUCTION TO MODULAR PROGRAMMING
======================================

📌 **What is Modular Programming?**
   - A **way of organizing code** into separate, reusable parts.
   - Instead of writing everything in `main()`, we use **functions** and **modules**.

📌 **Why Modular Programming?**
   - Makes **code easier to read**.
   - Helps in **debugging and testing** small parts independently.
   - Allows **reuse** of code in different projects.
   - Enables **team collaboration**, where different people work on different modules.

📌 **How does it work?**
   - We **break a program into functions** first.
   - Later, we move functions to **separate files** (covered in later courses).

*/

#include <iostream>
using namespace std;

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers (with error check)
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

// Main function
int main() {
    double x, y;
    char op;

    // Ask the user for an operation
    cout << "Enter an operation (+, -, *, /): ";
    cin >> op;

    // Ask for two numbers
    cout << "Enter two numbers: ";
    cin >> x >> y;

    // Perform the operation
    double result = 0;
    if (op == '+') result = add(x, y);
    else if (op == '-') result = subtract(x, y);
    else if (op == '*') result = multiply(x, y);
    else if (op == '/') result = divide(x, y);
    else cout << "Invalid operation!" << endl;

    // Display result
    cout << "Result: " << result << endl;

    return 0;
}