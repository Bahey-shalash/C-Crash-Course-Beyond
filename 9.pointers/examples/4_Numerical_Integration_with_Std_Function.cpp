/*
Numerical Integration Using std::function
------------------------------------------
This example demonstrates using `std::function` for numerical integration. Unlike
function pointers, `std::function` supports any callable, including lambdas, functors,
and regular functions.
*/

#include <iostream>
#include <functional>
using namespace std;

// Function to perform Trapezoidal Integration
double trapezoidalIntegration(const function<double(double)>& f, double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        integral += f(a + i * h);
    }
    return integral * h;
}

// Function to perform Simpson's Integration
double simpsonsIntegration(const function<double(double)>& f, double a, double b, int n) {
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

int main() {
    auto f = [](double x) { return x * x; }; // Lambda function f(x) = x^2
    double a = 0.0, b = 1.0;
    int n = 10;

    cout << "Trapezoidal Integration: " << trapezoidalIntegration(f, a, b, n) << endl;
    cout << "Simpson's Integration: " << simpsonsIntegration(f, a, b, n) << endl;

    return 0;
}