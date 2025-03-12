/*
    ### C++ Course: Lazy Evaluation (Short-Circuit Evaluation)

    Lazy evaluation, also known as short-circuit evaluation, is a feature in C++ that
   optimizes conditional expressions. In expressions with `&&` (AND) or `||` (OR), only
   the necessary conditions are evaluated. This prevents potential runtime errors, such
   as division by zero, and can improve performance.

    Topics Covered:
    1. Basics of Lazy Evaluation with `&&` and `||`
    2. Practical Examples and Benefits
    3. Common Pitfalls and Best Practices
*/

#include <iostream>
using namespace std;

bool testFunction();  // For latter example

int main() {
    // 1. Basics of Lazy Evaluation in C++
    /*
        In C++, lazy evaluation means that:
        - For `&&` (AND) conditions: The evaluation stops at the first `false`
       condition.
        - For `||` (OR) conditions: The evaluation stops at the first `true` condition.

        This allows us to safely structure conditions where certain parts of the
       expression could otherwise cause errors, such as dividing by zero.
    */

    int i = 0;
    bool result;

    // Example with `&&` (AND) Operator
    result =
        (i != 0) &&
        (25 / i > 12);  // `25 / i > 12` is not evaluated because `i != 0` is false
    cout << "Using `&&` with i = 0, result is: " << result << endl;

    // Explanation:
    // Since `i != 0` is false, the overall expression is determined to be false
    // without evaluating `25 / i > 12`. This prevents a division-by-zero error,
    // demonstrating the safety benefits of lazy evaluation.

    // Example with `||` (OR) Operator
    result = (i == 0) ||
             (25 / i < 12);  // `25 / i < 12` is not evaluated because `i == 0` is true
    cout << "Using `||` with i = 0, result is: " << result << endl;

    // Explanation:
    // Since `i == 0` is true, the expression short-circuits to true, and `25 / i < 12`
    // is never evaluated.

    // 2. Practical Benefits of Lazy Evaluation
    /*
        Lazy evaluation provides several advantages:
        - **Error Prevention**: Prevents runtime errors (e.g., division by zero) when
       certain conditions are not met.
        - **Performance Optimization**: Stops evaluating once the result is determined,
       saving computation time.
    */

    int a = 10, b = 0;

    // Example: Avoiding Division by Zero
    if (b != 0 && (a / b > 1)) {
        cout << "Safe division: (a / b) > 1" << endl;
    } else {
        cout << "Division by zero avoided with lazy evaluation." << endl;
    }

    // Explanation:
    // Since `b != 0` is false, `(a / b > 1)` is not evaluated, preventing a division
    // by zero error.

    // 3. Common Pitfalls and Best Practices
    /*
        Pitfall: Lazy evaluation may cause unexpected behavior if you rely on all
       expressions being evaluated.
        - Example: If a function call is embedded in a lazy-evaluated expression, it
       may not run as expected.
    */

    if (false && testFunction()) {  // `testFunction` is never called because the first
                                    // condition is false
        cout << "This won't print because testFunction() isn't called." << endl;
    }

    // Explanation:
    // Since the first condition is false, `testFunction()` is not called due to lazy
    // evaluation. Be cautious when embedding function calls in expressions that might
    // short-circuit.

    return 0;
}
bool testFunction() {
    cout << "testFunction is called!" << endl;
    return true;
}

/*
    Compile and run:
        g++ lazy_evaluation.cpp -o lazy_evaluation
        ./lazy_evaluation
*/