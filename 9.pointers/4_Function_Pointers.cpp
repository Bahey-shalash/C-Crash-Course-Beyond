/*
Class 4: Function Pointers
--------------------------
In this class, we will explore:
1. Defining and using function pointers.
2. Passing function pointers as arguments to functions.
3. Using function pointers for callback mechanisms.
4. Practical applications of function pointers.

Key concepts:
- Function pointers store the address of a function, allowing dynamic function calls.
- The syntax involves using parentheses and the dereference operator.
- Function pointers enable runtime flexibility by allowing different functions to be called dynamically.

*/

#include <iostream>
using namespace std;

// Step 1: A Simple Function
int add(int a, int b) {
    return a + b;
}

// Another function for demonstration
int multiply(int a, int b) {
    return a * b;
}

// Step 2: Function that Accepts a Function Pointer as an Argument
void calculate(int x, int y, int (*operation)(int, int)) {
    cout << "Result: " << operation(x, y) << endl; // Call the function through the pointer
}

int main() {
    // Step 3: Declare a Function Pointer
    int (*funcPtr)(int, int); // Pointer to a function taking two ints and returning an int

    // Step 4: Assign a Function to the Pointer
    funcPtr = &add;
    cout << "Calling add through function pointer: " << funcPtr(5, 3) << endl; // Outputs 8

    funcPtr = &multiply;
    cout << "Calling multiply through function pointer: " << funcPtr(5, 3) << endl; // Outputs 15

    // Step 5: Passing Function Pointers to Functions
    cout << "\nUsing function pointers as arguments:" << endl;
    calculate(10, 20, add); // Passing the add function
    calculate(10, 20, multiply); // Passing the multiply function

    // Step 6: Callback Example
    // An array of function pointers
    int (*operations[])(int, int) = {add, multiply};
    cout << "\nIterating through function pointer array:" << endl;
    for (auto& op : operations) {
        cout << "Result: " << op(6, 2) << endl; // Call each function dynamically
    }

    return 0;
}