/* ==========================================================================
Lesson 4: Overloading Assignment and Comparison Operators

In this lesson, we implement a simple MyString class that wraps a C-style
string and overloads several operators:

- operator= (assignment) to perform deep copying.
- operator== (equality) to compare two MyString objects.
- operator!= (inequality) implemented using operator==.
- operator<< for stream output (declared as a friend function).

Additional members:
- A copy constructor to ensure proper copying.
- A destructor to release dynamically allocated memory.

Note:
- Always check for self-assignment in the assignment operator.
========================================================================== */

// Lesson4_MyStringOperatorOverload.cpp

#include <iostream>
#include <cstring>  // For strlen, strcpy, strcmp

class MyString {
private:
    char *data;
public:
    // Constructor: allocate memory and copy the given string.
    MyString(const char* str = "") {
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
    }

    // Copy constructor: perform a deep copy.
    MyString(const MyString &other) {
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
    }

    // Assignment operator overload.
    MyString& operator=(const MyString &other) {
        if (this != &other) {  // Check for self-assignment.
            delete[] data;  // Free old memory.
            data = new char[std::strlen(other.data) + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    // Equality operator overload.
    bool operator==(const MyString &other) const {
        return std::strcmp(data, other.data) == 0;
    }

    // Inequality operator overload using operator==.
    bool operator!=(const MyString &other) const {
        return !(*this == other);
    }

    // Friend function to overload operator<< for stream output.
    friend std::ostream& operator<<(std::ostream &out, const MyString &str);

    // Destructor: free allocated memory.
    ~MyString() {
        delete[] data;
    }
};

// External overload for operator<<.
std::ostream& operator<<(std::ostream &out, const MyString &str) {
    out << str.data;
    return out;
}

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3;

    // Use the assignment operator to copy s1 into s3.
    s3 = s1;
    std::cout << "s3: " << s3 << std::endl;

    // Compare s1 and s3 using operator==.
    if (s1 == s3)
        std::cout << "s1 is equal to s3" << std::endl;
    else
        std::cout << "s1 is not equal to s3" << std::endl;

    // Compare s1 and s2 using operator!=.
    if (s1 != s2)
        std::cout << "s1 is not equal to s2" << std::endl;
    else
        std::cout << "s1 is equal to s2" << std::endl;

    return 0;
}