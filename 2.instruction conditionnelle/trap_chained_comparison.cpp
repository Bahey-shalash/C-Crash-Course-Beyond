/* ### File: trap_chained_comparison.cpp ###
   ### Trap 1: Chained Comparison Confusion in C++ ###

   **Problem**:
   Expressions like `c < b < a++` can be misleading, as C++ does not support 
   chained comparisons like some other languages (e.g., Python).

   **Example**:
   In the following code, `(c < b < a++)` is parsed as `(c < b) < a++`, which 
   may yield unexpected results.

   **Solution**:
   Perform comparisons individually to avoid unexpected behavior.
*/

#include <iostream>
using namespace std;

int main() {
    int a(10);
    int b(10);
    int c(2);

    // Misleading comparison: This is evaluated as `(c < b) < a++`
    cout << (c < b < a++) << endl;  // Output may not be as expected

    // Clearer comparison
    cout << ((c < b) && (b < a)) << endl; // Perform comparisons separately

    return 0;
}

/*
Explanation:
- `(c < b < a++)` is evaluated as `(c < b) < a++`, resulting in `(1) < 11`,
  which is `true < 11` in C++, yielding `1` (true).
- To avoid this, perform comparisons separately or use `&&` for chained logic.
*/