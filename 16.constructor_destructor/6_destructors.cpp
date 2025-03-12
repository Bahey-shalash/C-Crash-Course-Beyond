/*
    Lesson 5: Destructors In Depth

    What We Will Cover:
    -------------------
    - What is a **destructor**?
    - The role of destructors in resource management.
    - The default destructor versus a custom destructor.
    - Implementing destructors for classes that manage dynamic memory.
    - The order in which destructors are called.
    - Using virtual destructors in inheritance hierarchies.
    - Real-world examples and test cases.

    Background:
    -----------
    - A **destructor** is a special member function of a class that is executed when an object
      of that class goes out of scope or is explicitly deleted.
    - Its main purpose is to free up resources that were acquired during the lifetime of the object,
      such as dynamic memory, file handles, or network connections.
    - The destructor has the same name as the class, prefixed with a tilde (~), and it does not take any parameters.
*/

/*
    1. Basic Destructors
    --------------------
    - Every C++ class has a destructor, even if you don't explicitly define one.
    - The **default destructor** automatically calls the destructors for member objects.
    - When your class manages resources (like dynamic memory), you need to define a custom destructor.
*/

#include <iostream>
#include <cstring>  // For dynamic memory functions
#include <string>

// Example 1: A simple class that prints messages upon construction and destruction.
class Simple {
public:
    Simple() { 
        std::cout << "Simple object constructed." << std::endl; 
    }
    ~Simple() { 
        std::cout << "Simple object destroyed." << std::endl; 
    }
};

void test_simple_destructor() {
    std::cout << "\nTest: Simple Destructor" << std::endl;
    {
        Simple s;
    } // 's' goes out of scope here, and its destructor is called.
    std::cout << "Exited the scope of test_simple_destructor." << std::endl;
}

/*
    2. Custom Destructor for Dynamic Memory Management
    --------------------------------------------------
    - When a class allocates dynamic memory, a custom destructor must free that memory
      to prevent memory leaks.
*/

class DynamicBuffer {
private:
    char* buffer;
public:
    // Constructor: Allocate dynamic memory and initialize it with the given text.
    DynamicBuffer(const char* text) {
        buffer = new char[strlen(text) + 1];  // Allocate memory for the string (+1 for null terminator)
        strcpy(buffer, text);
        std::cout << "DynamicBuffer constructed with text: " << buffer << std::endl;
    }

    // Destructor: Free the allocated memory.
    ~DynamicBuffer() {
        std::cout << "DynamicBuffer destructor freeing memory for: " << buffer << std::endl;
        delete[] buffer;
    }

    // A method to display the buffer content.
    void show() const {
        std::cout << "Buffer content: " << buffer << std::endl;
    }
};

void test_dynamic_buffer() {
    std::cout << "\nTest: DynamicBuffer Destructor" << std::endl;
    DynamicBuffer db("Hello, Destructors!");
    db.show();
    // When 'db' goes out of scope, its destructor is called, freeing the memory.
}

/*
    3. Order of Destruction
    -----------------------
    - Local objects are destroyed in the reverse order of their creation.
    - This means that if you construct objects A, B, and C in that order, C is destroyed first,
      followed by B, and finally A.
*/

class OrderTest {
private:
    std::string name;
public:
    OrderTest(const std::string& n) : name(n) {
        std::cout << "Constructing " << name << std::endl;
    }
    ~OrderTest() {
        std::cout << "Destructing " << name << std::endl;
    }
};

void test_destruction_order() {
    std::cout << "\nTest: Order of Destruction" << std::endl;
    OrderTest a("A");
    OrderTest b("B");
    OrderTest c("C");
    std::cout << "Exiting scope of test_destruction_order." << std::endl;
    // Destructors are automatically called in the reverse order: C, B, then A.
}

/*
    4. Virtual Destructors in Inheritance
    --------------------------------------
    - When dealing with inheritance, especially if you intend to delete a derived class object
      through a base class pointer, the base class destructor should be declared virtual.
    - This ensures that the destructor of the derived class is called, allowing for proper cleanup.
*/

class Base {
public:
    Base() { 
        std::cout << "Base constructed." << std::endl; 
    }
    // Declare the destructor as virtual to allow derived class destructors to be called.
    virtual ~Base() { 
        std::cout << "Base destroyed." << std::endl; 
    }
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        data = new int[10];  // Allocate some dynamic memory.
        std::cout << "Derived constructed." << std::endl;
    }
    ~Derived() override {
        std::cout << "Derived destructor freeing dynamic memory." << std::endl;
        delete[] data;
        std::cout << "Derived destroyed." << std::endl;
    }
};

void test_virtual_destructor() {
    std::cout << "\nTest: Virtual Destructor in Inheritance" << std::endl;
    Base* obj = new Derived();
    // When deleting through the base pointer, both the Derived and Base destructors are called.
    delete obj;
}

/*
    Recap of Destructors:
    ---------------------
    - **Purpose:** Destructors are used to release resources acquired during an object's lifetime.
    - **Syntax:** A destructor has the same name as the class, prefixed with a tilde (~), and it cannot take parameters or be overloaded.
    - **Automatic Call:** Destructors are automatically called when an object goes out of scope or is explicitly deleted.
    - **Default vs. Custom:** If you do not define a destructor, the compiler provides a default one that calls member destructors.
    - **Virtual Destructors:** In a polymorphic base class, always declare the destructor as virtual to ensure proper cleanup.
*/

/*
    Expected Output (Console):
    ----------------------------
    Test: Simple Destructor
    Simple object constructed.
    Simple object destroyed.
    Exited the scope of test_simple_destructor.

    Test: DynamicBuffer Destructor
    DynamicBuffer constructed with text: Hello, Destructors!
    Buffer content: Hello, Destructors!
    DynamicBuffer destructor freeing memory for: Hello, Destructors!

    Test: Virtual Destructor in Inheritance
    Base constructed.
    Derived constructed.
    Derived destructor freeing dynamic memory.
    Derived destroyed.
    Base destroyed.

    Test: Order of Destruction
    Constructing A
    Constructing B
    Constructing C
    Exiting scope of test_destruction_order.
    Destructing C
    Destructing B
    Destructing A
*/

// Main Function to Run Tests
int main() {
    test_simple_destructor();
    std::cout << "----------------------------" << std::endl;

    test_dynamic_buffer();
    std::cout << "----------------------------" << std::endl;

    test_virtual_destructor();
    std::cout << "----------------------------" << std::endl;

    test_destruction_order();
    std::cout << "----------------------------" << std::endl;

    return 0;
}