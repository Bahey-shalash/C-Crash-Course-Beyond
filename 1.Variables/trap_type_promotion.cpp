/* ### File: trap_type_promotion.cpp ###
   ### Trap 3: Unexpected Type Promotion ###

   **Problem**:
   When dividing an integer by a floating-point value (like `10 / 2.0`), the 
   result type may not be what you expect due to implicit type promotion.

   **Example**:
   Using `decltype(10 / 2.)` can lead to surprising results when determining 
   the type of the expression.

   **Solution**:
   Be explicit with types or use `auto` to ensure clarity.
*/

#include <iostream>
#include <typeinfo>

int main() {
    // Type promotion example
    auto result = 10 / 2.0;

    // Output the type of the result
    std::cout << "Type of (10 / 2.0) is: " << typeid(result).name() << std::endl;

    return 0;
}

/*
Explanation:
- `10 / 2.0` promotes `10` to `double`, resulting in a `double` result type.
- Using `auto` helps manage type automatically, but always double-check your types 
  with mixed operations to avoid surprises.
*/