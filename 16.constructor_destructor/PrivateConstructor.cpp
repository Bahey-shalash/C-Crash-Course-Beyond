/* ==========================================================================
Crash Course: Controlling Object Creation with Private Constructors

Theory:
---------
In C++, constructors determine how objects are created. By declaring a constructor
as private, you restrict external code from instantiating the class directly.
This technique is used to control object creation for various design reasons.

When to make a constructor private:
-------------------------------------
1. **Singleton Pattern:**
   - Only one instance of the class should exist.
   - The constructor is private, and a public static method (e.g., getInstance())
     returns the sole instance.

      +------------------------+
      | Singleton Class        |
      | ---------------------- |
      | - Constructor: private |
      | - getInstance()        |  <-- Returns the single instance.
      +------------------------+

2. **Factory Methods:**
   - Objects are created only through static factory functions.
   - The constructor is private to enforce controlled instantiation.

3. **Utility (Static-Only) Classes:**
   - The class is meant to provide only static functions.
   - Making the constructor private (or deleting it) prevents instantiation.

      +------------------------+
      | MathUtils              |
      | ---------------------- |
      | - Constructor: private/deleted |
      | - Static functions     |
      +------------------------+

4. **Prevent Direct Instantiation for Inheritance:**
   - If you wish to prevent direct instantiation of a base class while still
     allowing derived classes to call the constructor, you may use a protected
     constructor. (For private, only friend classes or member functions can create
instances.)

Edge Cases:
-----------
- A class with a private constructor cannot be instantiated outside its class (or
friend).
- To allow controlled instantiation, provide a public static method or friend class.
- Remember: If you also delete the copy constructor and assignment operator, you
prevent copying of the single instance.

Examples:
---------
1. Singleton Pattern
   - Private constructor prevents external instantiation.
   - A static method (getInstance()) returns the sole instance.

2. Utility Class (Non-Instantiable)
   - All members are static.
   - The constructor is deleted to prevent instantiation.
========================================================================== */

#include <iostream>
using namespace std;

// Example 1: Singleton Pattern
class Singleton {
private:
    // Private constructor prevents direct instantiation.
    Singleton() { cout << "Singleton instance created." << endl; }

    // Delete copy constructor and assignment operator to prevent copies.
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Public static method to provide access to the single instance.
    static Singleton& getInstance() {
        // The instance is created once and reused.
        static Singleton instance;
        return instance;
    }

    void doSomething() { cout << "Singleton is doing something!" << endl; }
};

// Example 2: Utility Class (Non-Instantiable)
class MathUtils {
private:
    // Private (deleted) constructor prevents instantiation.
    MathUtils() = delete;

public:
    static int add(int a, int b) { return a + b; }

    static int multiply(int a, int b) { return a * b; }
};

int main() {
    // ----- Singleton Example -----
    // Cannot create a new instance directly: Singleton s; // Error!

    // Access the single instance via the static method.
    Singleton& s1 = Singleton::getInstance();
    s1.doSomething();

    // Any subsequent call returns the same instance.
    Singleton& s2 = Singleton::getInstance();
    s2.doSomething();

    // ----- Utility Class Example -----
    // Cannot instantiate MathUtils because the constructor is deleted.
    // MathUtils mu; // Error!

    // Use static functions directly.
    int sum = MathUtils::add(3, 4);
    int product = MathUtils::multiply(5, 6);
    cout << "MathUtils::add(3, 4) = " << sum << endl;
    cout << "MathUtils::multiply(5, 6) = " << product << endl;

    return 0;
}

/*
Explanation:

1. Singleton Pattern:
- The constructor of the Singleton class is declared private so that no external
     code can create an instance.
- The static method getInstance() returns a reference to a single, static instance.
- The copy constructor and assignment operator are deleted to prevent copying the
instance.
- This ensures that only one instance exists throughout the program.
- Memory Diagram (Conceptual):

         +------------------------+
         | Singleton (single inst.)|
         |------------------------|
         | - Private constructor  |
         | - Static instance      |
         | - getInstance()        |  <-- Always returns the same object.
         +------------------------+

2. Utility Class:
   - MathUtils is designed to provide only static functions.
   - By deleting the constructor, you prevent any instantiation of MathUtils.
   - This is useful for classes that serve as a namespace for related functions.
   - Memory Diagram (Conceptual):

         +------------------------+
         | MathUtils (static only)|
         |------------------------|
         | - No instance can exist|
         | - Contains only static functions  |
         +------------------------+

When to use private constructors:
- Use them when you want to restrict or control object creation.
- Commonly seen in design patterns (Singleton, Factory) and utility classes.
- Consider using protected if you want to allow instantiation by derived classes only.
*/