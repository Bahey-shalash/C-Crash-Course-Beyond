/*
Function Pointers in C++ Explanation
-------------------------------------
- A function pointer is essentially a variable that stores the address of a function.
- Unlike regular pointers that point to data, function pointers point to executable
  code sections in memory.
- This feature enables dynamic calling of functions, passing functions as arguments, 
  and implementing callback mechanisms.

Advantages:
1. Flexibility: Allows for dynamic function invocation without needing to know the
   function names at compile time.
2. Callbacks: Useful for implementing callback mechanisms, enabling lower-level code 
   to call higher-level functions.
3. Interface Design: Enables the creation of plugin architectures or interfaces that 
   can be extended or modified dynamically.

Syntax:
    returnType (*pointerName)(parameterTypes);
- `returnType` is the function's return type.
- `pointerName` is the name of the function pointer variable.
- `parameterTypes` are the types of parameters the function accepts.

Example Usage:
*/

#include <iostream>
using namespace std;

// Function prototype
int Add(int x, int y);

// Function that takes a function pointer as an argument
void PrintOperation(int a, int b, int (*operation)(int, int));

int main() {
    // Declaring a function pointer 'op' and assigning it the address of the 'Add' function
    int (*op)(int, int) = &Add;
    int result = op(5, 3); // Expected: 8

    cout << "Result of 5 + 3 is: " << result << endl;

    // Passing a function pointer to another function
    PrintOperation(10, 5, &Add); // Expected: "The operation result is: 15"

    return 0;
}

// Definition of 'Add'
int Add(int x, int y) {
    return x + y;
}

// Implementation of 'PrintOperation'
void PrintOperation(int a, int b, int (*operation)(int, int)) {
    cout << "The operation result is: " << operation(a, b) << endl;
}