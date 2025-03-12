#include <iostream>

using namespace std;

int main() {
    int i = 5;  // Initialize an integer variable 'i' with the value 5

    // Pre-increment (++i)
    // - Increments 'i' by 1 before its current value is used
    // - Returns the updated value of 'i'
    int preIncrementResult = ++i;  // i is incremented to 6, preIncrementResult is 6

    // Pre-decrement (--i)
    // - Decrements 'i' by 1 before its current value is used
    // - Returns the updated value of 'i'
    int preDecrementResult = --i;  // i is decremented to 5, preDecrementResult is 5

    // Post-increment (i++)
    // - Returns the current value of 'i' and then increments 'i' by 1
    int postIncrementResult = i++;  // postIncrementResult is 5, i is incremented to 6

    // Post-decrement (i--)
    // - Returns the current value of 'i' and then decrements 'i' by 1
    int postDecrementResult = i--;  // postDecrementResult is 6, i is decremented to 5

    // Output the results
    cout << "Initial i: " << i << endl;
    cout << "Pre-increment Result: " << preIncrementResult << endl;
    cout << "Pre-decrement Result: " << preDecrementResult << endl;
    cout << "Post-increment Result: " << postIncrementResult << endl;
    cout << "Post-decrement Result: " << postDecrementResult << endl;

    return 0;
}

/*
The primary difference between the "before" and "after" versions of the increment and
decrement operators (`++i`, `--i`, `i++`, and `i--`) lies in the timing of when the
variable is modified and when its current value is used.

1. **Pre-increment (`++i`) and Pre-decrement (`--i`):**
   - In pre-increment (`++i`), the variable is incremented (or decremented) by 1 before
its current value is used in an expression.
   - In pre-decrement (`--i`), the variable is decremented (or incremented) by 1 before
its current value is used.
   - These operators return the updated value of the variable.
   - Use cases: When you want to use the updated value immediately and perform an
operation with it.

2. **Post-increment (`i++`) and Post-decrement (`i--`):**
   - In post-increment (`i++`), the current value of the variable is used in an
expression, and then the variable is incremented (or decremented) by 1.
   - In post-decrement (`i--`), the current value of the variable is used, and then the
variable is decremented (or incremented) by 1.
   - These operators return the current value of the variable before the update.
   - Use cases: When you need to use the current value before incrementing or
decrementing the variable.

Here's a practical example to illustrate the difference:

{
 int i = 5;

int preIncrementResult = ++i; // Pre-increment: i is incremented first, then assigned
to preIncrementResult int postIncrementResult = i++; // Post-increment: i's current
value (6) is assigned to postIncrementResult, then i is incremented

cout << "Pre-increment Result: " << preIncrementResult << endl; // Outputs 6
cout << "Post-increment Result: " << postIncrementResult << endl; // Outputs 6


In the pre-increment case, `preIncrementResult` gets the value 6 because `i`
is incremented before assigning it. In the post-increment case,
`postIncrementResult` gets the current value of `i` (6) before the increment operation
takes place.
*/
