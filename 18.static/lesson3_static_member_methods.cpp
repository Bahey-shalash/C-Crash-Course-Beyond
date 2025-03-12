/*
    LESSON 3: `static` Member Functions in Classes
    
    🔹 Normally, class methods operate on **instance-specific** data.
    🔹 A `static` function **belongs to the class itself**, not to individual objects.
    
    ✅ Key Properties of `static` Member Functions:
        1️⃣ Declared with `static` inside the class.
        2️⃣ Can **only access static members** (cannot use `this` pointer).
        3️⃣ Can be called using `ClassName::FunctionName()` (without an object).
*/

#include <iostream>

// ---------------------------------------------
// 1️⃣ Class with `static` Function
// ---------------------------------------------

class MathUtils {
public:
    // Static data member (shared across all objects)
    static int counter;

    // Static function
    static void showCounter() {
        std::cout << "Static counter value: " << counter << "\n";
    }

    // Regular (non-static) function - modifies static variable
    void incrementCounter() {
        counter++; // ✅ Static variables can be modified inside regular functions
    }
};

// ---------------------------------------------
// 2️⃣ Definition of `static` Data Member
// ---------------------------------------------

int MathUtils::counter = 0;  // Memory allocation for static variable

// ---------------------------------------------
// 3️⃣ Main Function: Calling Static Functions( static methods)
// ---------------------------------------------

int main() {
    // Calling static function without creating an object
    std::cout << "Accessing static function directly:\n";
    MathUtils::showCounter(); // ✅ Correct way to call a static function

    // Creating two objects
    MathUtils obj1, obj2;
    obj1.incrementCounter();
    obj2.incrementCounter();

    std::cout << "\nAfter incrementing using two objects:\n";
    MathUtils::showCounter(); // ✅ Shows the updated shared value

    return 0;
}