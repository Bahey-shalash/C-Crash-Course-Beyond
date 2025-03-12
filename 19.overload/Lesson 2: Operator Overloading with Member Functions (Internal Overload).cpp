/* ==========================================================================
Lesson 2: Operator Overloading with Member Functions (Internal Overload)

This lesson demonstrates overloading operators as member functions.

In this example, we define a simple Point class that overloads:
- operator+ to add two Point objects.
- operator+= to add another Point to the current one.
- operator== to compare two Point objects.
- operator<< as an external friend function to output a Point.

Note:
- When you write "p1 + p2", it is equivalent to calling "p1.operator+(p2)".
- Similarly, "p1 += p2" calls "p1.operator+=(p2)".
========================================================================== */

// Lesson2_PointOperatorOverload.cpp

#include <iostream>

class Point {
public:
    int x, y;

    // Constructor: initialize x and y.
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload operator+ to add two Points.
    Point operator+(const Point &other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overload operator+= to add another Point to this one.
    Point& operator+=(const Point &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // Overload operator== to compare two Points.
    bool operator==(const Point &other) const {
        return (x == other.x) && (y == other.y);
    }

    // Declare operator<< as a friend function for stream output.
    friend std::ostream& operator<<(std::ostream &out, const Point &p);
};

// External overload for operator<< to output a Point.
std::ostream& operator<<(std::ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    Point p1(2, 3);
    Point p2(4, 5);

    // Using operator+ (internally calls p1.operator+(p2))
    Point p3 = p1 + p2;
    std::cout << "p1 + p2 = " << p3 << std::endl;

    // Using operator+= (internally calls p1.operator+=(p2))
    p1 += p2;
    std::cout << "After p1 += p2, p1 = " << p1 << std::endl;

    // Compare points using operator==
    if (p1 == p3)
        std::cout << "p1 is equal to p3" << std::endl;
    else
        std::cout << "p1 is not equal to p3" << std::endl;

    return 0;
}