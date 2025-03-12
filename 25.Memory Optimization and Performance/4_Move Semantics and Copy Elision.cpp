/* ==========================================================================
Lesson 4: Move Semantics and Copy Elision

Theory:
---------
Move semantics allow you to transfer resources from temporary objects,
avoiding costly deep copies. This is crucial for performance when handling large
objects. Copy elision (including Return Value Optimization, RVO) is a compiler
optimization that eliminates unnecessary copying.

Key Points:
- Use std::move to cast an object to an rvalue reference.
- Define move constructors and move assignment operators.
- Edge Cases: After moving, the source object is left in a valid but unspecified state.

Example:
---------
A simple class demonstrating move semantics.
========================================================================== */

#include <iostream>
#include <vector>
using namespace std;

class Buffer {
public:
    Buffer(size_t size) : size(size), data(new int[size]) {
        cout << "Buffer of size " << size << " constructed.\n";
    }
    // Move constructor
    Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {
        other.data = nullptr;
        other.size = 0;
        cout << "Buffer moved.\n";
    }
    // Move assignment operator
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            cout << "Buffer move-assigned.\n";
        }
        return *this;
    }
    // Delete copy constructor and copy assignment to force moves
    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;
    ~Buffer() {
        delete[] data;
        cout << "Buffer destroyed.\n";
    }

private:
    size_t size;
    int* data;
};

int main() {
    Buffer buf1(100);
    Buffer buf2 = std::move(buf1);  // Uses move constructor
    Buffer buf3(50);
    buf3 = std::move(buf2);  // Uses move assignment
    return 0;
}