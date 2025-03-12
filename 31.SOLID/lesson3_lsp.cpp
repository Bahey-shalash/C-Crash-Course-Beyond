/*
 File: lesson3_lsp.cpp

 Lesson 3: Liskov Substitution Principle (LSP)

 Explanation:
 The Liskov Substitution Principle states that objects of a superclass should be replaceable with objects of a subclass
 without affecting the correctness of the program. That is, subclasses must honor the contract of the base class.

 In this example:
  - The "Bad Example" defines a Bird class with a fly() method, and an Ostrich subclass that throws an error in fly()
    because ostriches cannot fly. This violates LSP because substituting an Ostrich where a Bird is expected causes problems.
  - The "Good Example" refines the hierarchy by introducing a FlyingBird class. Only birds that can actually fly (e.g., Sparrow)
    derive from FlyingBird, so non-flying birds (e.g., Ostrich) do not implement a fly() method.

 To compile this file:
    g++ -std=c++17 lesson3_lsp.cpp -o lesson3_lsp
*/

#include <iostream>
#include <stdexcept>

// ====================================================
// BAD EXAMPLE: Violation of LSP.
// ====================================================
namespace BadExample {
    class Bird {
    public:
        virtual void fly() {
            std::cout << "Bird flying" << std::endl;
        }
        virtual ~Bird() = default;
    };

    class Ostrich : public Bird {
    public:
        void fly() override {
            // Ostriches cannot fly!
            throw std::runtime_error("Ostrich cannot fly");
        }
    };

    void letBirdFly(Bird& bird) {
        bird.fly();
    }

    void run() {
        std::cout << "Running Bad Example (LSP Violation)" << std::endl;
        Ostrich ostrich;
        try {
            letBirdFly(ostrich);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
}

// ====================================================
// GOOD EXAMPLE: Adheres to LSP by segregating flying behavior.
// ====================================================
namespace GoodExample {
    class Bird {
    public:
        virtual ~Bird() = default;
    };

    class FlyingBird : public Bird {
    public:
        virtual void fly() = 0;
    };

    class Sparrow : public FlyingBird {
    public:
        void fly() override {
            std::cout << "Sparrow flying" << std::endl;
        }
    };

    // Ostrich does not derive from FlyingBird since it cannot fly.
    class Ostrich : public Bird {
    };

    void letFlyingBirdFly(FlyingBird& bird) {
        bird.fly();
    }

    void run() {
        std::cout << "Running Good Example (Adheres to LSP)" << std::endl;
        Sparrow sparrow;
        letFlyingBirdFly(sparrow);
        // Ostrich is not passed to letFlyingBirdFly, so LSP is maintained.
        std::cout << std::endl;
    }
}

int main() {
    // Uncomment one or both examples to run them:
    
    // Bad Example (violates LSP)
    BadExample::run();
    
    // Good Example (adheres to LSP)
    GoodExample::run();
    
    return 0;
}
