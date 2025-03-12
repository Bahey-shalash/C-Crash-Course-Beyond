/*
    LESSON 2: `static` Data Members in Classes

    🔹 In C++, **non-static** data members belong to **each object** of a class.
    🔹 A `static` data member is **shared across all objects** of the class:
        - It is stored in a **single memory location** instead of per-object.
        - All instances **share the same value**.
        - It **exists even if no objects of the class are created**.

    ✅ Key Properties of `static` Data Members:
        1️⃣ Declared inside the class using `static`.
        2️⃣ Defined **outside** the class (without `static`).
        3️⃣ Accessed using `ClassName::member` (without creating an object).
*/

#include <iostream>

// ---------------------------------------------
// 1️⃣ Class with `static` Data Member
// ---------------------------------------------

class Counter {
public:
    // Normal (non-static) variable: Each object has its own `count`
    int count;

    // Static data member: Shared across all objects
    static int totalCount;

    // Constructor
    Counter() {
        count = 0;     // Each object has its own count
        totalCount++;  // Shared among all objects
    }

    // Method to show values
    void showCount() {
        std::cout << "Object count: " << count << "\n";
        std::cout << "Total count (shared): " << totalCount << "\n";
    }
};

// ---------------------------------------------
// 2️⃣ Definition of `static` Data Member (Outside Class)
// ---------------------------------------------

/*
    - A `static` variable **must be defined outside** the class.
    - This tells the compiler to allocate memory for it.
    - Do NOT use `static` in the definition.
*/
int Counter::totalCount = 0;  // Initialization

// ---------------------------------------------
// 3️⃣ Main Function: Creating Objects
// ---------------------------------------------

int main() {
    std::cout << "Creating first object...\n";
    Counter obj1;
    obj1.showCount();

    std::cout << "\nCreating second object...\n";
    Counter obj2;
    obj2.showCount();

    std::cout << "\nAccessing `totalCount` using class name:\n";
    std::cout << "Total Count: " << Counter::totalCount << "\n";
    // ✅ Correct way to access static members

    return 0;
}