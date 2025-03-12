/*
    ### C++ Course: Prefix (`++i`) vs. Postfix (`i++`) Increment Operators

    In C++, both `++i` (prefix) and `i++` (postfix) operators increment a variable by 1, 
    but they differ in:
    - **Behavior**: The value they return after incrementing.
    - **Performance**: The postfix operator often incurs additional overhead.

    Topics Covered:
    1. How `++i` and `i++` Work
    2. Using `++i` vs. `i++` in Expressions
    3. Why Prefer `++i` Over `i++` in Some Cases
*/

#include <iostream>
using namespace std;

int main() {
    // 1. Basics of `++i` and `i++`
    /*
        Both `++i` and `i++` increment the variable `i` by 1, but they differ in their return values:
        - `++i` (prefix): Increments `i` first, then returns the incremented value.
        - `i++` (postfix): Returns the current value of `i`, then increments it.
    */
    
    int i = 3;
    int prefixResult = ++i;  // Increments `i` to 4, then returns 4
    cout << "Using `++i`: i is " << i << ", prefixResult is " << prefixResult << endl;
    
    i = 3;                   // Reset `i` for the next test
    int postfixResult = i++; // Returns 3, then increments `i` to 4
    cout << "Using `i++`: i is " << i << ", postfixResult is " << postfixResult << endl;

    // Explanation:
    // - `++i` returns the new, incremented value of `i`.
    // - `i++` returns the original value of `i` before incrementing.

    // 2. `++i` and `i++` in Expressions
    /*
        The difference between `++i` and `i++` is most noticeable in expressions.
        For example, when using them in assignments, `++i` and `i++` yield different results.
    */

    int j = 3, k = 0, l = 0;

    k = ++j;  // Prefix increment: `j` becomes 4, `k` is set to 4
    cout << "\nAfter `k = ++j`: j is " << j << ", k is " << k << endl;

    j = 3;    // Reset `j`
    l = j++;  // Postfix increment: `l` is set to 3, then `j` becomes 4
    cout << "After `l = j++`: j is " << j << ", l is " << l << endl;

    // Explanation:
    // - `++j` increments `j` before assignment, so `k` receives the new value of `j` (4).
    // - `j++` assigns the current value of `j` to `l` (3) and increments `j` afterward.

    // 3. Performance Considerations: Why Prefer `++i` Over `i++`
    /*
        For simple types like `int`, `++i` and `i++` perform similarly. 
        However, with complex data types (like objects), `i++` can incur additional overhead.
        
        - Prefix `++i` can directly modify the variable and return it.
        - Postfix `i++` typically creates a copy of the current value before incrementing, leading to extra work.
        
        When overloading operators in custom classes, prefer `++i` over `i++` to avoid unnecessary copies.
    */

    // Summary:
    // - Use `++i` (prefix) where possible for potential performance benefits.
    // - `++i` and `i++` both increment the value, but the return value differs.
    // - Prefer `++i` in complex types to avoid the extra work associated with `i++`.

    return 0;
}

/*
    Compile and run:
        g++ increment_operators.cpp -o increment_operators
        ./increment_operators
*/