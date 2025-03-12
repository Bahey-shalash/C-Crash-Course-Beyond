#include <iostream>
#include <string>

/* The `this` pointer in C++ is a keyword representing a pointer to the object
 * for which a member function is called. It is implicitly passed as a hidden
 * argument to all non-static member function calls, and it is available as a
 * local variable within the body of all non-static functions. */

/* Class Box demonstrates the use of `this` to resolve name conflicts
 * between member variables and method parameters. */
class Box {
public:
    int length;

    // Constructor
    Box(int length) {
        /* `this->length` uses the `this` pointer to distinguish between the member
         * variable `length` and the constructor's parameter `length`. This resolves
         * the name conflict by indicating that `this->length` refers to the object's
         * member variable, not the parameter. */
        this->length = length;  // Resolves name conflict
    }

    void displayLength() const {
        // Using `this` to explicitly access the member variable for clarity
        std::cout << "Length: " << this->length << std::endl;
        /* would also work without the this-> part (this->length is the same as length)
         */
    }
};

/* Class Counter demonstrates `this` and `*this` in operator overloading.
 * It includes both prefix and postfix increment operators. */
class Counter {
private:
    int value;

public:
    Counter() : value(0) {}  // Default constructor initializes value to 0

    // Prefix increment operator
    Counter& operator++() {
        ++value;  // Increment the value
        // Returning `*this` returns the current object itself by reference.
        // `*this` dereferences the `this` pointer, yielding the object itself.
        return *this;
    }

    // Postfix increment operator
    Counter operator++(int) {
        Counter temp = *this;  // Make a copy of the current object
        ++(*this);             // Increment the original object
        return temp;  // Return the copy, following postfix increment semantics
    }

    int getValue() const { return value; }
};

/* Class Builder demonstrates method chaining using `*this`.
 * It allows appending strings together in a fluent interface style. */
class Builder {
private:
    std::string data;

public:
    Builder& append(const std::string& str) {
        data += str;
        // Returning `*this` enables method chaining by returning the current object
        return *this;
    }

    void print() const { std::cout << data << std::endl; }
};

int main() {
    // Demonstrating `this` with Box
    Box box(10);
    box.displayLength();

    // Demonstrating `*this` with Counter
    Counter c;
    ++c;  // Uses prefix increment, which utilizes `*this`
    std::cout << "Counter value (prefix ++): " << c.getValue() << std::endl;
    c++;  // Uses postfix increment, demonstrating `*this` in a different context
    std::cout << "Counter value (postfix ++): " << c.getValue() << std::endl;

    // Demonstrating method chaining with Builder
    Builder b;
    b.append("Hello, ").append("world!").print();  // Each `append` returns `*this`

    return 0;
}
