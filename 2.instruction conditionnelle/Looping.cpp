/*
    ### C++ Course: Looping Constructs (`while`, `do-while`, `for`)

    C++ offers several types of loops for repeated code execution:
    1. `while` Loop: Repeats while a condition is true.
    2. `do-while` Loop: Similar to `while`, but guarantees at least one execution.
    3. `for` Loop: Typically used when the number of iterations is known.

    We’ll explore each loop type with syntax, use cases, and common pitfalls.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1. `while` Loop
    /*
        Syntax:
        ```
        while (condition) {
             Code to execute as long as condition is true
        }
        ```

        - The `while` loop checks the condition before each iteration.
        - If the condition is false initially, the loop will not run at all.
        - Useful for loops where the number of iterations is unknown beforehand.
    */

    int count = 0;
    cout << "Using `while` loop:\n";

    while (count < 5) {
        cout << "Count is: " << count << endl;
        count++;
    }

    // Common Pitfall: Infinite Loop
    // If the condition never becomes false, the loop will continue indefinitely.
    // For example:
    /*
    while (count < 5) {
        cout << "This would be an infinite loop without updating `count`.\n";
    }
    */

    // 2. `do-while` Loop
    /*
        Syntax:
        ```
        do {
            // Code to execute
        } while (condition);
        ```

        - The `do-while` loop executes the code block once before checking the
       condition.
        - This guarantees at least one execution, even if the condition is false.
        - Useful when the loop should run at least once regardless of the condition.
    */

    int input;
    do {
        cout << "\nEnter a number (0 to exit): ";
        cin >> input;
    } while (input != 0);

    // Explanation:
    // This loop prompts the user for input at least once, even if they enter `0`
    // immediately.

    // 3. `for` Loop
    /*
        Syntax:
        ```
        for (initialization; condition; update) {
            // Code to execute
        }
        ```

        - The `for` loop is typically used when the number of iterations is known.
        - Initialization: Sets up the loop variable (e.g., `int i = 0`).
        - Condition: Checks if the loop should continue.
        - Update: Modifies the loop variable after each iteration.
    */

    cout << "\nUsing `for` loop:\n";
    for (int i = 0; i < 5; i++) {
        cout << "i is: " << i << endl;
    }

    // Explanation:
    // Here, `i` is initialized to 0, increments by 1 in each iteration, and the loop
    // stops when `i < 5` is false.

    // Common Pitfall: Incorrect Loop Condition
    /*
    for (int i = 0; i <= 5; i++) {   // This would loop one extra time
        cout << "i is: " << i << endl;
    }
    */

    // 4. Range-Based `for` Loop (C++11 and Later)
    /*
        Syntax:
        ```
        for (type element : container) {
            // Code to execute with each element in the container
        }
        ```

        - Ideal for iterating over elements in a collection (e.g., arrays, vectors).
        - Reduces errors in indexing and simplifies the code.
    */

    vector<int> numbers = {10, 20, 30, 40, 50};
    cout << "\nUsing range-based `for` loop:\n";
    for (int num : numbers) {
        cout << "Number: " << num << endl;
    }

    // Explanation:
    // This loop iterates through each element in `numbers`, making `num` take each
    // value in turn.

    // 5. Nested Loops
    /*
        Loops can be nested (i.e., placed inside one another).
        - Useful for multidimensional data (e.g., matrices) or repeated processes.
    */

    cout << "\nNested `for` loops:\n";
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 2; j++) {
            cout << "i = " << i << ", j = " << j << endl;
        }
    }

    // Explanation:
    // The inner loop completes all its iterations for each iteration of the outer
    // loop.

    // 6. Loop Control Statements (`break` and `continue`)
    /*
        - `break`: Exits the loop immediately.
        - `continue`: Skips the remaining code in the loop and proceeds to the next
       iteration.
    */

    cout << "\nUsing `break` and `continue`:\n";

    for (int k = 0; k < 10; k++) {
        if (k == 5) {
            cout << "Breaking at k = 5\n";
            break;  // Exit the loop when k is 5
        }
        if (k % 2 == 0) {
            cout << "Skipping even number " << k << endl;
            continue;  // Skip even numbers
        }
        cout << "Odd number: " << k << endl;
    }

    // Explanation:
    // `break` stops the loop when `k` equals 5, and `continue` skips even numbers.

    // 7. `for` Loop with `auto` Keyword (C++11 and Later)
    /*
        Syntax:
        ```
        for (auto element : container) {
            // Code to execute with each element in the container
        }
        ```

        - The `auto` keyword automatically deduces the type of the elements.
        - Simplifies the code and reduces the risk of type-related errors.
    */

    vector<int> moreNumbers = {60, 70, 80, 90, 100};
    cout << "\nUsing `for` loop with `auto` keyword:\n";
    for (auto num : moreNumbers) {
        cout << "Number: " << num << endl;
    }

    // Explanation:
    // `auto` infers the type of `num` based on the elements in `moreNumbers`.

    return 0;
}