/*
 File: lesson1_srp.cpp

 Lesson 1: Single Responsibility Principle (SRP)

 Explanation:
 The Single Responsibility Principle (SRP) states that a class should have only one reason to change,
 meaning it should have a single responsibility. In the example below:

  - The "Bad Example" has an Employee class that handles business logic (calculating pay),
    presentation (printing employee details), and persistence (saving to a file).
  - The "Good Example" splits these responsibilities into separate classes:
      * Employee: Handles business logic.
      * EmployeePrinter: Handles presentation.
      * EmployeePersistence: Handles persistence.

 To compile this file:
     g++ -std=c++17 lesson1_srp.cpp -o lesson1_srp
*/

#include <iostream>
#include <fstream>
#include <string>

// ====================================================
// BAD EXAMPLE: Violation of Single Responsibility Principle
// ====================================================
namespace BadExample {
    class Employee {
    public:
        std::string name;
        int id;
        
        // Business logic: calculate pay (dummy implementation)
        void calculatePay() {
            // Imagine some complex salary calculation here.
        }
        
        // Presentation logic: printing the employee details
        void printEmployee() {
            std::cout << "Name: " << name << ", ID: " << id << std::endl;
        }
        
        // Persistence logic: saving employee details to a file
        void saveToFile() {
            std::ofstream file("employee_bad.txt");
            if (file.is_open()) {
                file << "Name: " << name << ", ID: " << id;
                file.close();
                std::cout << "Saved to employee_bad.txt" << std::endl;
            } else {
                std::cerr << "Unable to open file!" << std::endl;
            }
        }
    };

    void run() {
        std::cout << "Running Bad Example (SRP Violation)" << std::endl;
        Employee emp;
        emp.name = "John Doe";
        emp.id = 101;
        emp.calculatePay();
        emp.printEmployee();
        emp.saveToFile();
        std::cout << std::endl;
    }
}

// ====================================================
// GOOD EXAMPLE: Adherence to Single Responsibility Principle
// ====================================================
namespace GoodExample {
    class Employee {
    public:
        std::string name;
        int id;
        
        // Business logic: calculate pay (dummy implementation)
        void calculatePay() {
            // Imagine some complex salary calculation here.
        }
    };

    class EmployeePrinter {
    public:
        static void print(const Employee& emp) {
            std::cout << "Name: " << emp.name << ", ID: " << emp.id << std::endl;
        }
    };

    class EmployeePersistence {
    public:
        static void saveToFile(const Employee& emp, const std::string& filename) {
            std::ofstream file(filename);
            if (file.is_open()) {
                file << "Name: " << emp.name << ", ID: " << emp.id;
                file.close();
                std::cout << "Saved to " << filename << std::endl;
            } else {
                std::cerr << "Unable to open file: " << filename << std::endl;
            }
        }
    };

    void run() {
        std::cout << "Running Good Example (Adheres to SRP)" << std::endl;
        Employee emp;
        emp.name = "Jane Smith";
        emp.id = 202;
        emp.calculatePay();
        EmployeePrinter::print(emp);
        EmployeePersistence::saveToFile(emp, "employee_good.txt");
        std::cout << std::endl;
    }
}

int main() {
    // Uncomment one or both examples to run them:
    
    // Bad Example (violates SRP)
    BadExample::run();
    
    // Good Example (adheres to SRP)
    GoodExample::run();
    
    return 0;
}
