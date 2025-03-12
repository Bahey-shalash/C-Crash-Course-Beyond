/*
    LESSON 4: Practical Use Cases of `static` in OOP

    🔹 `static` attributes and methods are commonly used in:
    
    1️⃣ **Utility classes** (e.g., Math functions)
    2️⃣ **Global counters** (e.g., tracking how many objects are created)
    3️⃣ **The Singleton Pattern** (ensuring only one instance of a class)
*/

#include <iostream>

// ---------------------------------------------
// 1️⃣ Utility Class (Math Functions)
// ---------------------------------------------

class MathUtils {
public:
    // Static method: No need to create an instance to use it
    static int add(int a, int b) {
        return a + b;
    }

    static int multiply(int a, int b) {
        return a * b;
    }
};

// ---------------------------------------------
// 2️⃣ Global Counter (Tracking Object Creation)
// ---------------------------------------------

class InstanceTracker {
private:
    static int objectCount; // Shared counter across all instances

public:
    InstanceTracker() {
        objectCount++; // Increment counter when an object is created
    }

    static void showObjectCount() {
        std::cout << "Total objects created: " << objectCount << "\n";
    }
};

// Define static variable outside the class
int InstanceTracker::objectCount = 0;

// ---------------------------------------------
// 3️⃣ Singleton Pattern (Ensuring One Instance)
// ---------------------------------------------

class Singleton {
private:
    static Singleton* instance; // Pointer to the single instance

    // Private constructor to prevent direct instantiation
    Singleton() {
        std::cout << "Singleton instance created.\n";
    }

public:
    // Static method to get the single instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Define static pointer outside the class
Singleton* Singleton::instance = nullptr;

// ---------------------------------------------
// 4️⃣ Main Function: Using Static Methods and Attributes
// ---------------------------------------------

int main() {
    std::cout << "Using static utility methods:\n";
    std::cout << "Addition: " << MathUtils::add(5, 3) << "\n";
    std::cout << "Multiplication: " << MathUtils::multiply(4, 7) << "\n";

    std::cout << "\nTracking object count:\n";
    InstanceTracker obj1, obj2, obj3;
    InstanceTracker::showObjectCount(); // ✅ Calls static method without an object

    std::cout << "\nEnsuring only one instance (Singleton):\n";
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    
    // Both pointers should point to the same instance
    if (s1 == s2) {
        std::cout << "Both are the same instance.\n";
    }

    return 0;
}