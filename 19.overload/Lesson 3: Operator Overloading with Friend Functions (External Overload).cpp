/* ==========================================================================
Lesson 3: Operator Overloading with Friend Functions (External Overload)

In this lesson, we create a Complex number class and overload operators as
friend functions.

Operators overloaded in this lesson:
- operator+ for adding two Complex numbers.
- operator<< for output streaming.
- operator>> for input streaming.

Note:
- operator+ is implemented as an external function (declared friend) so that
  "c1 + c2" calls operator+(c1, c2).
- operator<< and operator>> must be non-member functions because their left-hand
  operands are std::ostream and std::istream respectively.
========================================================================== */

// Lesson3_ComplexOperatorOverload.cpp

#include <iostream>

class Complex {
private:
    double real, imag;
public:
    // Constructor: initialize real and imaginary parts.
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Friend declaration for operator+.
    friend Complex operator+(const Complex &c1, const Complex &c2);

    // Friend declarations for stream insertion and extraction operators.
    friend std::ostream& operator<<(std::ostream &out, const Complex &c);
    friend std::istream& operator>>(std::istream &in, Complex &c);
};

// External overload for operator+.
Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

// External overload for operator<<.
std::ostream& operator<<(std::ostream &out, const Complex &c) {
    out << c.real;
    if (c.imag >= 0)
        out << " + " << c.imag << "i";
    else
        out << " - " << -c.imag << "i";
    return out;
}

// External overload for operator>>.
std::istream& operator>>(std::istream &in, Complex &c) {
    // Input expects two numbers: real and imaginary parts.
    in >> c.real >> c.imag;
    return in;
}

int main() {
    Complex c1, c2;
    std::cout << "Enter real and imaginary parts for complex number c1: ";
    std::cin >> c1; // Uses operator>>

    std::cout << "Enter real and imaginary parts for complex number c2: ";
    std::cin >> c2; // Uses operator>>

    // Adding two Complex numbers.
    Complex sum = c1 + c2; // Calls operator+(c1, c2)

    // Output the sum using operator<<.
    std::cout << "Sum of c1 and c2: " << sum << std::endl;

    return 0;
}