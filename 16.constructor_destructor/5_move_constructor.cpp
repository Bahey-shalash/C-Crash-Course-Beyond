/*
    Lesson 4: Move Constructors from 0 to Hero

    What We Will Cover:
    -------------------
    - What is a **move constructor**?
    - Why are move semantics important?
    - How does a move constructor differ from a copy constructor?
    - Implementing **custom move constructors**.
    - Using **std::move** to enable move semantics.
    - Real-world examples and test cases.

    Background:
    -----------
    - In C++11 and later, move semantics allow you to "steal" resources from temporary
      objects (rvalues) instead of copying them.
    - This is particularly useful for classes that manage resources such as dynamic memory,
      file handles, or network connections, as it avoids expensive deep copies.
    - A move constructor takes an rvalue reference (using `&&`) to another object of the same type.
*/

#include <iostream>
#include <utility>  // For std::move

/*
    1. Understanding Move Constructors
    ----------------------------------
    - A **move constructor** is a special constructor that transfers resources from a source
      object (typically a temporary object) to a new object.
    - Instead of copying the resource, the move constructor "steals" the resource pointer.
    - After the move, the source object is left in a valid but unspecified state (commonly set to nullptr).
*/

// Example: A simple class that manages a dynamically allocated integer.
class MoveExample {
private:
    int* data;  // Pointer to dynamically allocated memory

public:
    // Constructor (Allocates memory and initializes it)
    MoveExample(int value) {
        data = new int(value);
        std::cout << "Constructed with value: " << value << std::endl;
    }

    // Copy Constructor (for comparison purposes)
    MoveExample(const MoveExample& other) {
        data = new int(*other.data);
        std::cout << "Copy constructor called." << std::endl;
    }

    // Move Constructor
    // Note the parameter type is an rvalue reference: MoveExample&&
    MoveExample(MoveExample&& other) noexcept {
        // Steal the resource from 'other'
        data = other.data;
        // Leave 'other' in a safe state (null pointer)
        other.data = nullptr;
        std::cout << "Move constructor called." << std::endl;
    }

    // Destructor to free allocated memory
    ~MoveExample() {
        delete data;
        std::cout << "Destructor called." << std::endl;
    }

    // Function to display the data value
    void show() const {
        if (data)
            std::cout << "Data: " << *data << std::endl;
        else
            std::cout << "Data is null." << std::endl;
    }
};

/*
    2. Using std::move to Enable Move Semantics
    -------------------------------------------
    - `std::move` is a standard library function that converts an lvalue into an rvalue reference.
    - It signals that the object may be "moved from," allowing the move constructor (or move assignment)
      to be used.
*/

void test_move_constructor() {
    std::cout << "\nTest: Move Constructor with std::move" << std::endl;
    MoveExample ex1(100);
    std::cout << "ex1 before moving:" << std::endl;
    ex1.show();

    // Use std::move to convert ex1 into an rvalue reference.
    // This calls the move constructor to create ex2.
    MoveExample ex2 = std::move(ex1);
    std::cout << "ex2 after moving from ex1:" << std::endl;
    ex2.show();

    std::cout << "ex1 after being moved from:" << std::endl;
    ex1.show(); // ex1's data should now be null.
}

/*
    3. Moving from Temporary Objects
    ---------------------------------
    - When functions return temporary objects, the move constructor can be used to efficiently
      transfer resources from the temporary to a new object.
*/

// Function that creates and returns a temporary MoveExample object
MoveExample createMoveExample(int value) {
    MoveExample temp(value);
    return temp;  // Return a temporary object; move semantics avoid an expensive copy.
}

void test_move_with_temporary() {
    std::cout << "\nTest: Moving from a Temporary Object" << std::endl;
    MoveExample ex3 = createMoveExample(200);
    ex3.show();
}

/*
    4. Recap of Move Semantics
    --------------------------
    - **Move Constructor Syntax:** The move constructor has the signature:
         ClassName(ClassName&& other) noexcept;
    - **Purpose:** To transfer (steal) resources from a temporary (rvalue) object.
    - **std::move:** Explicitly casts an object to an rvalue, enabling move semantics.
    - **After Move:** The moved-from object should remain in a valid state (often set to nullptr for pointers).
*/

/*
    Expected Output (Console):
    ----------------------------
    Constructed with value: 100
    ex1 before moving:
    Data: 100
    Move constructor called.
    ex2 after moving from ex1:
    Data: 100
    ex1 after being moved from:
    Data is null.
    Destructor called.    // When ex1 goes out of scope (null pointer deletion is safe)
    ...
    Constructed with value: 200
    Move constructor called.    // May be called when returning from createMoveExample()
    Destructor called.
    Data: 200
    Destructor called.
*/

// Main Function to Run Tests
int main() {
    test_move_constructor();
    std::cout << "----------------------------" << std::endl;

    test_move_with_temporary();
    std::cout << "----------------------------" << std::endl;

    return 0;
}