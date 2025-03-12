/* ### File: trap_ternary_operator.cpp ###
   ### Trap 2: Unintended Use of `++` in a Ternary Operation ###

   **Problem**:
   The ternary operator can lead to unexpected results if `++` is used 
   within the condition. Here, the value of `a` changes before it's used.

   **Example**:
   The expression `b++ >= a ? "Z" : "X"` modifies `b` before comparison, 
   which can cause confusion.

   **Solution**:
   Avoid `++` within a ternary expression condition if it could be misleading.
*/

#include <iostream>
using namespace std;

int main() {
    int a(10);
    int b(10);

    // Using post-increment in a ternary operation
    cout << (b++ >= a ? "Z" : "X") << endl; // Potentially confusing

    // Clearer code
    bool result = (b >= a);
    cout << (result ? "Z" : "X") << endl;

    return 0;
}

/*
Explanation:
- `b++ >= a` increments `b` after the comparison, but this can be confusing.
- To avoid this, evaluate `b >= a` first, then increment `b` if needed.
*/