/* Function Pointers in C++ Explanation */

/*
- A function pointer is essentially a variable that stores the address of a function.
- Unlike regular pointers that point to data, function pointers point to executable
code sections in memory.
- This feature enables the dynamic calling of functions, passing functions as
arguments, and implementing callback mechanisms.

Advantages:
1. Flexibility: Allows for dynamic function invocation without needing to know the
function names at compile time.
2. Callbacks: Useful for implementing callback mechanisms, enabling lower-level code to
call higher-level functions.
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

// Function prototype
int Add(int x, int y);



// Function that takes a function pointer as an argument
void PrintOperation(int a, int b, int (*operation)(int, int));

int main() {
    // Declaring a function pointer 'op' and assigning it the address of the 'Add'
    // function
    double (*f_ptrr)(char, int) =nullptr;  // pointer to a function that takes a char and an int
                                   // as arguments and returns a double
    int (*op)(int, int) = &Add;
    int (*op_)(int, int) = Add;
    // both are equivilant (i prefer the use of &function_name)

    int (*ptr_f)(int, int);
    // pointer to a function that takes two ints as arguments and returns an int

    int *g(double);  // fonction that returs a pointer to an int and takes a double as
                     // argument and NOT a pointer to the function g

    // Using the function pointer 'op' to call 'Add'
    int result = op(5, 3);  // Expected: 8

    int result_ = (*op)(5, 3);  // Expected: 8 other way to call the function

    std::cout << "Result of 5 + 3 is: " << result << std::endl;

    // Passing a function pointer to another function
    PrintOperation(10, 5, &Add);  // Expected: "The operation result is: 15"

    return 0;
}

// Definition of 'Add'
int Add(int x, int y) {
    return x + y;
}

// Implementation of 'PrintOperation'
//! IMPOTAANT
void PrintOperation(int a, int b, int (*operation)(int, int)) {
    std::cout << "The operation result is: " << operation(a, b) << std::endl;
}

//! exemple cours ,rectangle 
double integ(double (*f_ptr)(double), int nb, double min, double max) {
    double h = (max - min) / nb; // step size voir cours analyse numerique CMS 
    double sum = 0;
    for (int i = 0; i < nb; i++) {
        sum += f_ptr(min + i * h);
    }
    return h * sum;
}

/*
In this example, 'op' is a function pointer that points to 'Add', allowing us to call
'Add' through 'op'. Furthermore, 'PrintOperation' demonstrates how function pointers
can be passed as arguments, enabling dynamic function calls. This is a foundational
concept for understanding more advanced features in C++ like callbacks and event-driven
programming.
*/
