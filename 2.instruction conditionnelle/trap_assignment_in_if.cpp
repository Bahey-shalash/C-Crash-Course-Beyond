/* ### File: trap_assignment_in_if.cpp ###
   ### Trap 4: Assignment in an `if` Condition ###

   **Problem**:
   Accidentally using `=` instead of `==` in an `if` condition can cause 
   unintended behavior, as the `=` operator returns the assigned value.

   **Example**:
   Writing `if(n = 0)` will assign `0` to `n`, making the condition always `false`.

   **Solution**:
   Use `==` for comparisons, and enable compiler warnings to catch this mistake.
*/

#include <iostream>
using namespace std;

int main() {
    int n(22);

    // Mistake: Assignment (`=`) instead of comparison (`==`)
    if(n = 0) {
        cout << "n est nul = " << n << endl;
    } else {
        cout << "n n'est pas nul = " << n << endl;
    }

    // Corrected version
    n = 22;  // Reset value
    if(n == 0) {
        cout << "n est nul = " << n << endl;
    } else {
        cout << "n n'est pas nul = " << n << endl;
    }

    return 0;
}

/*
Explanation:
- `if(n = 0)` assigns `0` to `n` and returns `0`, making the condition false.
- Always use `==` for comparisons, and enable compiler warnings to help catch 
  unintended assignments in conditions.
*/