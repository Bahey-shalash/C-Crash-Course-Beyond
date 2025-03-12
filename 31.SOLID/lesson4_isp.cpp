/*
 File: lesson4_isp.cpp

 Lesson 4: Interface Segregation Principle (ISP)

 Explanation:
 The Interface Segregation Principle (ISP) states that clients should not be forced to depend on methods they do not use.
 Rather than having one large "fat" interface, it's better to have multiple, smaller interfaces that are specific to client needs.

 In this example:
  - The "Bad Example" defines an IWorker interface with both work() and eat() methods. The Robot class is forced to implement eat(),
    even though robots do not need that behavior.
  - The "Good Example" segregates the interfaces: IWorker for work-related functionality and IFeedable for eating.
    The Human class implements both, while the Robot class implements only IWorker.

 To compile this file:
    g++ -std=c++17 lesson4_isp.cpp -o lesson4_isp
*/

#include <iostream>

// ====================================================
// BAD EXAMPLE: Violation of ISP by forcing classes to implement unnecessary methods.
// ====================================================
namespace BadExample {
    class IWorker {
    public:
        virtual ~IWorker() = default;
        virtual void work() = 0;
        virtual void eat() = 0;
    };

    class Human : public IWorker {
    public:
        void work() override {
            std::cout << "Human working" << std::endl;
        }
        void eat() override {
            std::cout << "Human eating" << std::endl;
        }
    };

    class Robot : public IWorker {
    public:
        void work() override {
            std::cout << "Robot working" << std::endl;
        }
        void eat() override {
            // Robot doesn't need to eat, but must implement this method.
            std::cout << "Robot does not eat" << std::endl;
        }
    };

    void run() {
        std::cout << "Running Bad Example (ISP Violation)" << std::endl;
        Human human;
        Robot robot;
        human.work();
        human.eat();
        robot.work();
        robot.eat();
        std::cout << std::endl;
    }
}

// ====================================================
// GOOD EXAMPLE: Adheres to ISP by segregating interfaces.
// ====================================================
namespace GoodExample {
    class IWorker {
    public:
        virtual ~IWorker() = default;
        virtual void work() = 0;
    };

    class IFeedable {
    public:
        virtual ~IFeedable() = default;
        virtual void eat() = 0;
    };

    class Human : public IWorker, public IFeedable {
    public:
        void work() override {
            std::cout << "Human working" << std::endl;
        }
        void eat() override {
            std::cout << "Human eating" << std::endl;
        }
    };

    class Robot : public IWorker {
    public:
        void work() override {
            std::cout << "Robot working" << std::endl;
        }
    };

    void run() {
        std::cout << "Running Good Example (Adheres to ISP)" << std::endl;
        Human human;
        Robot robot;
        human.work();
        human.eat();
        robot.work();
        std::cout << std::endl;
    }
}

int main() {
    // Uncomment one or both examples to run them:
    
    // Bad Example (violates ISP)
    BadExample::run();
    
    // Good Example (adheres to ISP)
    GoodExample::run();
    
    return 0;
}
