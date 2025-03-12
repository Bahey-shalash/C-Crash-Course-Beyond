/*
    Topic: Move Semantics and Move Constructors in C++

    Move semantics in C++ is one of the most important concepts introduced with C++11.
    It allows efficient transfer of resources (like dynamically allocated memory) from 
    one object to another without expensive deep copying. This improves performance, 
    especially when working with resource-heavy objects, such as large containers 
    (e.g., std::vector, std::string) or objects managing external resources (e.g., file handles, 
    sockets, dynamic memory).

    We will cover the following key aspects:
    1. Copy Semantics vs. Move Semantics.
    2. Rvalue references: The core enabler of move semantics.
    3. The Move Constructor and Move Assignment Operator.
    4. std::move() and when to use it.
    5. Move semantics with standard containers like std::vector.

    Let’s begin by understanding why move semantics are necessary.
    
    Copying large objects (using copy constructors or copy assignment operators) can be expensive 
    because it involves deep copying of resources. For example, if you have a large `std::vector`, 
    copying it would mean allocating new memory and copying every element from the original vector. 
    Move semantics eliminate this overhead by simply "moving" the resources (like memory pointers) 
    from one object to another, leaving the original object in a valid but empty (or null) state.

    Before diving into move constructors, we need to understand Rvalue references (introduced in C++11).
    
    In C++, there are two categories of expressions:
    
    - Lvalue: An object that has a name and persists beyond a single expression. 
              Example: `int a = 5;` — `a` is an lvalue.
    - Rvalue: A temporary object that does not persist beyond a single expression.
              Example: `int b = a + 1;` — `a + 1` is an rvalue.

    Move semantics are enabled by Rvalue references, denoted by `T&&`, which allows you to 
    distinguish between temporaries (rvalues) and persistent objects (lvalues). By using rvalue 
    references, C++ can detect when an object is about to be destroyed and can "steal" its resources 
    instead of copying them.

    Now let’s take a closer look at how this works with move constructors and move assignment operators.
*/
#include <iostream>
#include <vector>
#include <utility>  // for std::move

class MyClass {
private:
    int* data;

public:
    // Default constructor
    MyClass(int value = 0) {
        data = new int(value); // dynamically allocate memory
        std::cout << "Constructed resource with value: " << *data << std::endl;
    }

    // Copy constructor (deep copy)
    MyClass(const MyClass& other) {
        data = new int(*other.data);
        std::cout << "Copied resource with value: " << *data << std::endl;
    }

    // Move constructor
    MyClass(MyClass&& other) noexcept {
        data = other.data;      // Steal the resource
        other.data = nullptr;   // Leave the moved-from object in a valid state
        std::cout << "Moved resource, original left with nullptr" << std::endl;
    }

    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete data;          // Clean up the current resource
            data = other.data;    // Steal the resource
            other.data = nullptr; // Leave the moved-from object in a valid state
            std::cout << "Move assigned resource" << std::endl;
        }
        return *this;
    }

    // Destructor
    ~MyClass() {
        if (data) {
            std::cout << "Destroying resource with value: " << *data << std::endl;
        } else {
            std::cout << "Destroying null resource" << std::endl;
        }
        delete data; // Clean up the dynamically allocated memory
    }

    // Utility function for displaying the value
    void display() const {
        if (data) {
            std::cout << "Value: " << *data << std::endl;
        } else {
            std::cout << "No data to display" << std::endl;
        }
    }
};

// Demonstration of move semantics
int main() {
    MyClass obj1(42);      // Constructed
    MyClass obj2 = std::move(obj1); // Move constructor is called

    obj2.display();        // Display obj2's data
    obj1.display();        // obj1 has been "moved from", so no data

    MyClass obj3;
    obj3 = std::move(obj2); // Move assignment operator is called

    obj3.display();        // obj3 now owns the data
    obj2.display();        // obj2 is empty after the move

    return 0;
}

/*
    Key Points to Note:

    1. **Move Constructor**: The move constructor allows us to transfer ownership of resources from 
       one object to another without deep copying. The resource (pointer to memory) is transferred 
       from the `other` object to `this` object, and the `other` object is left in a valid but empty 
       state by nullifying its pointer.
       
    2. **Move Assignment Operator**: Similar to the move constructor, but for assignment. It handles 
       the transfer of resources during assignment, ensuring any previously held resource is properly 
       cleaned up before the move.

    3. **noexcept**: The `noexcept` specifier tells the compiler that the move operation will not throw 
       exceptions. This is important because if a move constructor or assignment operator can throw an 
       exception, many standard library optimizations (like those in `std::vector`) might not happen.
       
    4. **std::move**: The function `std::move()` is used to cast an lvalue to an rvalue reference. 
       It does not actually move anything but tells the compiler that this object can be "moved from". 
       It is up to the move constructor or move assignment operator to actually implement the move.

    Let’s now look at how move semantics are leveraged in standard containers like `std::vector`.

    In C++11 and beyond, when a vector resizes, instead of copying each element, the vector 
    can "move" the elements if a move constructor is available, which is much faster.
*/

void vectorMoveExample() {
    std::vector<MyClass> vec;
    vec.reserve(2); // Pre-allocate space for 2 elements
    vec.emplace_back(10);  // Move constructor not called (emplace constructs in-place)
    vec.emplace_back(20);  // Same here

    std::cout << "Resizing the vector, causing moves:" << std::endl;
    
    vec.reserve(4); // This might trigger moves if the vector needs to resize
    // Move constructors will be used to transfer the resources of elements
}

int main() {
    vectorMoveExample(); // Demonstrate moves within std::vector

    return 0;
}

/*
    Final thoughts on move semantics with standard containers like `std::vector`:
    
    - When a vector grows beyond its current capacity, new memory is allocated, and the 
      existing elements need to be transferred to the new memory block. If the elements 
      of the vector are movable (i.e., they have a move constructor and move assignment operator), 
      the vector can move them to the new memory block, instead of copying them, resulting in 
      a performance boost.
    
    - Similarly, when you pass a large vector to a function by value, the move constructor 
      will be invoked if you use `std::move()` to signal that the vector's resources can be 
      transferred, avoiding expensive deep copies.

    In practice, move semantics make C++ a much more efficient language, particularly when dealing 
    with dynamic resources or large objects. Understanding move constructors and move assignment 
    operators is crucial when designing classes that manage their own resources. It allows your 
    classes to participate in the optimizations provided by modern C++ features.
*/