/* ==========================================================================
Lesson 1: Introduction to Polymorphism

Polymorphism means “many forms.” In C++ it allows us to treat objects of
different derived classes uniformly through a base class pointer or reference.
This lesson introduces the idea of polymorphism with a very simple example.
========================================================================== */

#include <iostream>

// Base class with a simple method.
class Shape {
public:
    // This method is not virtual—so calls to it are bound statically.
    void draw() { std::cout << "Drawing a generic shape." << std::endl; }
};

class Circle : public Shape {
public:
    // Redefining draw() in the derived class.
    // Because Shape::draw() is not virtual, this function does not override it
    // in a polymorphic sense.
    void draw() { std::cout << "Drawing a circle." << std::endl; }
};

int main() {
    Shape shape1;
    shape1.draw();  // Calls Shape::draw().

    std::cout << "==========================" << std::endl;

    Circle circle1;
    circle1.draw();  // Calls Circle::draw().

    std::cout << "==========================" << std::endl;
    circle1.Shape::draw();  // Calls Shape::draw().

    std::cout << "==========================" << std::endl;

    // Even though 'c' is a Circle, if we call draw() via a Shape pointer,
    // the non-virtual function in Shape will be called.
    Shape* shapePtr = new Circle();
    // Static binding: calls Shape::draw() because draw() is not virtual.
    shapePtr->draw();

    delete shapePtr;

    return 0;
}

/*
output:

Drawing a generic shape.
==========================
Drawing a circle.
==========================
Drawing a generic shape.
==========================
Drawing a generic shape.
 */
