/*
    ### C++ Course: Conditional Instructions in C++

    Conditional instructions allow the program to make decisions and execute different
   code branches based on conditions. This course covers:
    1. `if` Statements and Common Pitfalls
    2. `switch` Statements
    3. The Ternary Operator (`? :`)
    4. Logical Operators (`&&`, `||`, `!`)
    5. Boolean Values and Operator Variants

    We’ll explore each of these with examples and point out common errors to avoid.
*/

#include <iostream>
using namespace std;

int main() {
    // 1. `if` Statements and Common Pitfalls
    /*
        `if` statements execute code only if a specified condition is true.
        Syntax:
            if (condition) {
                 code to execute if condition is true
            }

        C++ treats any non-zero value as true and zero as false.
    */

    int n(22);  // Initialize n to 22

    if (n == 0) {  // Correct usage: Check if n is equal to 0
        cout << "n is zero.\n";
    } else {
        cout << "n is not zero.\n";
    }

    // Common Pitfall: Assignment `=` instead of Comparison `==`
    if (n = 0) {  // Error: This assigns 0 to n, which results in false
        cout << "n is zero after incorrect assignment.\n";
    } else {
        cout << "n is not zero after incorrect assignment.\n";
    }
    // Explanation: `if (n = 0)` assigns 0 to `n`, so the condition is always false.
    // To avoid this, always use `==` for comparison and `=` for assignment.

    // 2. Using `if` with Logical Operators
    /*
        Logical operators combine multiple conditions:
        - `&&` (AND): True if both conditions are true.
        - `||` (OR): True if at least one condition is true.
        - `!` (NOT): Inverts the condition.
    */

    int a = 5, b = 10;

    if (a > 0 && b > 0) {
        cout << "Both a and b are positive.\n";
    }

    if (a > 0 || b < 0) {
        cout << "Either a is positive, or b is negative (or both).\n";
    }

    if (!(a < 0)) {  // Equivalent to checking if a >= 0
        cout << "a is non-negative.\n";
    }

    // 3. `switch` Statements
    /*
        The `switch` statement selects a branch to execute based on the value of an
       integer or character expression. Each case must have a unique value, and `break`
       statements prevent "fall-through" to other cases.

        Syntax:
            switch (variable) {
                case value1:
                     code to execute if variable == value1
                    break;
                case value2:
                     code to execute if variable == value2
                    break;
                default:
                     code to execute if none of the cases match
            }
    */

    int day = 3;  // Example value representing a day of the week

    switch (day) {
        case 1:
            cout << "Monday\n";
            break;
        case 2:
            cout << "Tuesday\n";
            break;
        case 3:
            cout << "Wednesday\n";
            break;
        default:
            cout << "Other day\n";
            break;
    }

    // 4. The Ternary Operator (`? :`)
    /*
        The ternary operator is a shorthand for simple `if-else` statements.
        Syntax: condition ? value_if_true : value_if_false;
    */

    int age = 20;
    string result = (age >= 18) ? "Adult" : "Minor";  // Ternary operator example
    cout << "Age category: " << result << endl;

    // Explanation: If `age >= 18` is true, `result` is set to "Adult"; otherwise, it’s
    // set to "Minor".

    // 5. Boolean Values and Logical Operators (Variations)
    /*
        C++ includes variations of logical operators:
        - `&&` (logical AND) is equivalent to `and`
        - `||` (logical OR) is equivalent to `or`
        - `!` (logical NOT) is equivalent to `not`

        Using `and`, `or`, and `not` can improve code readability, but they are less
       commonly used.
    */

    bool isStudent = true;
    bool hasDiscount = false;

    // Using `and`, `or`, `not`
    if (isStudent and not hasDiscount) {
        cout << "Student without a discount.\n";
    }

    if (isStudent or hasDiscount) {
        cout << "Eligible for benefits.\n";
    }

    // Summary:
    // - Use `if` statements for simple branching and check for common pitfalls like
    // `if (n = 0)`.
    // - Use `switch` statements when you have multiple cases for a single variable.
    // - Use the ternary operator for concise conditional assignments.
    // - Boolean operators (`&&`, `||`, `!`) have readable alternatives (`and`, `or`,
    // `not`), though both are valid.
    // - Always verify conditionals to avoid unexpected results from assignments in
    // conditions.

    return 0;
}