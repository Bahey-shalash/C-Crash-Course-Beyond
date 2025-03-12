/*
 File: lesson5_dip.cpp

 Lesson 5: Dependency Inversion Principle (DIP)

 Explanation:
 The Dependency Inversion Principle (DIP) states that high-level modules should not depend on low-level modules;
 both should depend on abstractions. This decoupling makes the code more flexible and easier to extend or test.

 In this example:
  - The "Bad Example" has a Switch class that directly depends on a concrete Light class.
  - The "Good Example" introduces an abstraction (IDevice) so that the Switch class depends on an abstract interface,
    allowing different devices to be used interchangeably without modifying the Switch class.

 To compile this file:
    g++ -std=c++17 lesson5_dip.cpp -o lesson5_dip
*/

#include <iostream>
#include <memory>

// ====================================================
// BAD EXAMPLE: Violation of DIP where Switch depends directly on the concrete Light class.
// ====================================================
namespace BadExample {
    class Light {
    public:
        void turnOn() {
            std::cout << "Light turned on" << std::endl;
        }
    };

    class Switch {
    public:
        Light* light;
        
        Switch(Light* l) : light(l) {}
        
        void operate() {
            light->turnOn();
        }
    };

    void run() {
        std::cout << "Running Bad Example (DIP Violation)" << std::endl;
        Light light;
        Switch sw(&light);
        sw.operate();
        std::cout << std::endl;
    }
}

// ====================================================
// GOOD EXAMPLE: Adheres to DIP by depending on an abstraction (IDevice).
// ====================================================
namespace GoodExample {
    class IDevice {
    public:
        virtual ~IDevice() = default;
        virtual void turnOn() = 0;
    };

    class Light : public IDevice {
    public:
        void turnOn() override {
            std::cout << "Light turned on" << std::endl;
        }
    };

    class Switch {
    public:
        std::shared_ptr<IDevice> device;
        
        Switch(const std::shared_ptr<IDevice>& d) : device(d) {}
        
        void operate() {
            device->turnOn();
        }
    };

    void run() {
        std::cout << "Running Good Example (Adheres to DIP)" << std::endl;
        std::shared_ptr<IDevice> light = std::make_shared<Light>();
        Switch sw(light);
        sw.operate();
        std::cout << std::endl;
    }
}

int main() {
    // Uncomment one or both examples to run them:
    
    // Bad Example (violates DIP)
    BadExample::run();
    
    // Good Example (adheres to DIP)
    GoodExample::run();
    
    return 0;
}
