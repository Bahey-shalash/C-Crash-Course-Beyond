/* ==========================================================================
Lesson 2: Custom Exception Classes

Theory:
---------
Custom exceptions allow you to create more descriptive error types.
Typically, you derive from std::exception and override the what() function.

Key Points:
- Inherit from std::exception.
- Provide a constructor to set an error message.
- Override what() to return a descriptive string.
- Edge Cases: Ensure noexcept specification for what().

Example:
---------
A custom exception class for a specific error condition.
========================================================================== */

#include <exception>
#include <iostream>
using namespace std;

class MyException : public std::exception {
public:
    MyException(const char* message) : msg(message) {}
    // Override what() and mark it noexcept.
    const char* what() const noexcept override { return msg; }

private:
    const char* msg;
};

void doSomethingRisky() {
    // Some condition occurs:
    throw MyException("Something went wrong in doSomethingRisky!");
}

int main() {
    try {
        doSomethingRisky();
    } catch (const MyException& e) {
        cerr << "Caught MyException: " << e.what() << endl;
    } catch (const std::exception& e) {
        cerr << "Caught std::exception: " << e.what() << endl;
    }
    return 0;
}