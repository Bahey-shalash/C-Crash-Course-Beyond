#include <iostream>
/*
    The `explicit` Keyword in C++
    -----------------------------
    - The `explicit` keyword prevents **implicit type conversion**.
    - Normally, if a constructor takes **a single parameter**, it can be called
      with an **implicit conversion**.
    - Using `explicit` stops the compiler from performing these unintended conversions.

    Example Without `explicit`:
    ----------------------------
    class A {
    public:
        A(int x) { std::cout << "A constructor called with " << x << std::endl; }
    };

    void test() {
        A obj = 10;  // ❌ Implicit conversion from int to A (allowed)
    }

    - Here, `10` is **implicitly converted** into an object of class `A`.

    Example With `explicit`:
    -------------------------
    class A {
    public:
        explicit A(int x) { std::cout << "A constructor called with " << x <<
   std::endl; }
    };

    void test() {
        A obj = 10;  // ❌ ERROR: Implicit conversion not allowed!
        A obj2(10);  // ✅ Allowed: Direct initialization
    }

    - Now, implicit conversions are **not allowed**.
    - `A obj2(10);` works because it is a **direct initialization**.
*/

class Phone {
private:
    std::string brand;
    int battery;

public:
    // Explicit Constructor
    explicit Phone(std::string phoneBrand, int batteryCapacity)
        : brand(phoneBrand), battery(batteryCapacity) {
        std::cout << "Phone object created! Brand: " << brand
                  << ", Battery: " << battery << "mAh" << std::endl;
    }

    void show() {
        std::cout << "Phone: " << brand << ", Battery: " << battery << "mAh"
                  << std::endl;
    }
};

void test_explicit_constructor() {
    Phone phone1("Samsung", 5000);  // ✅ Allowed
   // Phone phone2 = {"Apple", 3200}; //❌ ERROR: Cannot perform implicit conversion
    phone1.show();
}

/*
    Expected Output:
    ----------------
    Phone object created! Brand: Samsung, Battery: 5000mAh

    Explanation:
    - `explicit` prevents implicit conversion.
    - `Phone phone1("Samsung", 5000);` is **allowed** because it is direct
   initialization.
    - `Phone phone2 = {"Apple", 3200};` is **not allowed** because it would require an
   implicit conversion.
*/

int main() {
    test_explicit_constructor();
    return 0;
}