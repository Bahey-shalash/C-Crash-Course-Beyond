/*
Numerical Integration Using Function Pointers
----------------------------------------------
This example demonstrates using function pointers for numerical integration, including:
1. Trapezoidal Rule
2. Simpson's Rule

We use function pointers to dynamically specify the function to integrate, showcasing 
the flexibility of function pointers in numerical computation.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Trapezoidal Rule Function
double trapezoidalIntegration(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        integral += f(a + i * h);
    }
    return integral * h;
}

// Simpson's Rule Function
double simpsonsIntegration(double (*f)(double), double a, double b, int n) {
    if (n % 2 != 0) {
        cerr << "Simpson's rule requires an even number of intervals.\n";
        return NAN;
    }
    double h = (b - a) / n;
    double integral = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        integral += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }
    return integral * (h / 3.0);
}

// Example function to integrate
double exampleFunction(double x) {
    return x * x; // f(x) = x^2
}

int main() {
    double a = 0.0, b = 1.0;
    int n = 10;

    cout << "Trapezoidal Integration: "
         << trapezoidalIntegration(exampleFunction, a, b, n) << endl;

    cout << "Simpson's Integration: "
         << simpsonsIntegration(exampleFunction, a, b, n) << endl;

    return 0;
}