/*
    ### C++ Course: Recursive Functions

    Recursive functions are functions that call themselves. They are particularly useful 
    for problems that can be broken down into smaller, similar subproblems, like factorial 
    calculations, Fibonacci sequences, and tree traversals.

    Topics Covered:
    1. Basics of Recursion
    2. Base Cases and Recursive Calls
    3. Advantages and Pitfalls of Recursion
*/

#include <iostream>
using namespace std;

// Recursive function to calculate factorial of a number
int factorial(int n);

int main() {
    int num = 5;
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    return 0;
}

int factorial(int n) {
    /*
        The `factorial` function calculates `n!` (n factorial) recursively:
        - Base Case: If `n` is 0, return 1 (by definition, 0! = 1).
        - Recursive Case: Return `n * factorial(n - 1)`.
        
        This breakdown allows the problem to be solved in smaller, similar steps.
    */
    
    if (n <= 1)  // Base case
        return 1;
    else
        return n * factorial(n - 1);  // Recursive call
}

/*
    Explanation:
    - The function `factorial` calls itself with a smaller argument each time.
    - Each recursive call reduces `n` by 1, eventually reaching the base case where `n` is 1.
    - Without a base case, the recursion would continue indefinitely, causing a stack overflow.

    Example of how it works for factorial(3):
    - factorial(3) calls factorial(2)
    - factorial(2) calls factorial(1)
    - factorial(1) returns 1 (base case)
    - Then, factorial(2) returns 2 * 1 = 2
    - Finally, factorial(3) returns 3 * 2 = 6
    
    Recursive functions must always have:
    1. A Base Case: This prevents infinite recursion by stopping the recursive calls.
    2. A Recursive Case: This breaks the problem down and moves it toward the base case.
    
    Advantages:
    - Simplicity: Recursion often makes code easier to read, especially for naturally recursive problems.
    
    Pitfalls:
    - Stack Overflow: If the base case is not reached, recursion can consume too much memory.
    - Slower Performance: Recursive calls add function-call overhead, especially in deep recursion.
    
    Compile and run:
        g++ functions_recursion.cpp -o functions_recursion
        ./functions_recursion
*/