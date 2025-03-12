/*
 File: lesson2_ocp.cpp

 Lesson 2: Open/Closed Principle (OCP)

 Explanation:
 The Open/Closed Principle states that software entities should be open for extension but closed for modification.
 This means you can add new functionality without altering existing code.

 In this example:
  - The "Bad Example" uses a type-check (via an enum) in the Shape class's draw() method,
    forcing you to modify the method when adding new shapes.
  - The "Good Example" uses polymorphism. The base class Shape declares a virtual draw() method,
    and each derived class (e.g., Circle, Square) implements its own draw() method.
    New shapes can be added without modifying the existing code.

 To compile this file:
    g++ -std=c++17 lesson2_ocp.cpp -o lesson2_ocp
*/

#include <iostream>
#include <memory>
#include <vector>

// ====================================================
// BAD EXAMPLE: OCP Violation using type checking.
// ====================================================
namespace BadExample {
    class Shape {
    public:
        enum Type { CIRCLE, SQUARE };
        Type type;
        
        // Draw function that must be modified if new shapes are added.
        void draw() {
            if (type == CIRCLE) {
                std::cout << "Drawing Circle" << std::endl;
            } else if (type == SQUARE) {
                std::cout << "Drawing Square" << std::endl;
            }
        }
    };

    void run() {
        std::cout << "Running Bad Example (OCP Violation)" << std::endl;
        Shape circle;
        circle.type = Shape::CIRCLE;
        circle.draw();
        std::cout << std::endl;
    }
}

// ====================================================
// GOOD EXAMPLE: Adheres to OCP using polymorphism.
// ====================================================
namespace GoodExample {
    class Shape {
    public:
        virtual ~Shape() = default;
        virtual void draw() const = 0;
    };

    class Circle : public Shape {
    public:
        void draw() const override {
            std::cout << "Drawing Circle" << std::endl;
        }
    };

    class Square : public Shape {
    public:
        void draw() const override {
            std::cout << "Drawing Square" << std::endl;
        }
    };

    void run() {
        std::cout << "Running Good Example (Adheres to OCP)" << std::endl;
        std::vector<std::shared_ptr<Shape>> shapes;
        shapes.push_back(std::make_shared<Circle>());
        shapes.push_back(std::make_shared<Square>());
        for (const auto& shape : shapes) {
            shape->draw();
        }
        std::cout << std::endl;
    }
}

int main() {
    // Uncomment one or both examples to run them:
    
    // Bad Example (violates OCP)
    BadExample::run();
    
    // Good Example (adheres to OCP)
    GoodExample::run();
    
    return 0;
}
