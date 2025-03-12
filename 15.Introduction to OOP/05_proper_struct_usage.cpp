/*
======================================
  COURSE 5: STRUCT VS. CLASS – KEY DIFFERENCES
======================================

📌 **What is a `struct`?**
   - A `struct` is a simple data structure.
   - By default, its members are `public`.
   - Used for **plain data storage** without behavior.

📌 **What is a `class`?**
   - A `class` is an advanced structure that supports **encapsulation**.
   - By default, its members are `private`.
   - Used for **data + behavior** (methods, logic).

📌 **Key Differences Between `struct` and `class`**
   - `struct` defaults to `public`, while `class` defaults to `private`.
   - `struct` is typically used for **simple data containers**.
   - `class` is used when **data protection and behavior** are needed.

📌 **When to Use `struct` vs. `class`**
   - Use `struct` for **lightweight data structures** (e.g., points, colors, vectors).
   - Use `class` for **objects with behavior** (e.g., bank accounts, sensors).
*/

#include <iostream>

// Struct for a simple data container
struct Point {
    double x;  // Public by default
    double y;
};

// Class for an encapsulated data type
class SecurePoint {
private:
    double x;  // Private by default
    double y;

public:
    // Getter methods
    double getX() const { return x; }
    double getY() const { return y; }

    // Setter method with validation
    void setX(double xVal) { x = xVal; }
    void setY(double y) {
        // remember the keyword this both are equivalent, i prefer
        // not to use the this keyword unless necessary
        this->y = y;
    }
};

int main() {
    // Using struct (direct access)
    Point p1 = {10.5, 20.3};
    std::cout << "Struct Point: (" << p1.x << ", " << p1.y << ")\n";

    // Using class (controlled access)
    SecurePoint p2;  // we will later use constructor to initialize the values
    p2.setX(15.5);
    p2.setY(25.3);
    std::cout << "Class Point: (" << p2.getX() << ", " << p2.getY() << ")\n";

    // Attempt to modify values
    p1.x = -5;  // Allowed (struct is public)
    std::cout << "Modified Struct Point: (" << p1.x << ", " << p1.y << ")\n";

    p2.setX(-10);  // Not allowed (class enforces rules)
    std::cout << "Attempted modification on class: (" << p2.getX() << ", " << p2.getY()
              << ")\n";

    return 0;
}