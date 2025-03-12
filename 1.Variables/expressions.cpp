#include <iostream>

using namespace std;

int main() {
    // Assignment and Initialization
    double x = 1.3e3; // Initializing a double variable 'x' with the value 1.3 * 10^3

    // Arithmetic Operators
    double a = 5.0;
    double b = 2.0;

    // Addition
    double sum = a + b; // sum is 7.0

    // Subtraction
    double difference = a - b; // difference is 3.0

    // Multiplication
    double product = a * b; // product is 10.0

    // Division
    double quotient = a / b; // quotient is 2.5

    // Modulus (Remainder) Operator
    int num1 = 10;
    int num2 = 3;
    int remainder = num1 % num2; // remainder is 1

    // Increment and Decrement Operators
    int count = 5;
    count++; // Increment count by 1 (count is now 6)
    count--; // Decrement count by 1 (count is now 5)

    // Compound Assignment Operators
    int total = 10;
    total += 5; // Equivalent to total = total + 5 (total is now 15)
    total -= 3; // Equivalent to total = total - 3 (total is now 12)
    total *= 2; // Equivalent to total = total * 2 (total is now 24)
    total /= 4; // Equivalent to total = total / 4 (total is now 6)

    // Order of Operations
    double result = (a + b) * (a - b); // result is 15.0

    // Output the results
    cout << "x = " << x << endl;
    cout << "sum = " << sum << endl;
    cout << "difference = " << difference << endl;
    cout << "product = " << product << endl;
    cout << "quotient = " << quotient << endl;
    cout << "remainder = " << remainder << endl;
    cout << "result = " << result << endl;




    {
    int a(0);
    a = 2 + 3 / 2; // Quirk: Due to integer division, 3 / 2 = 1, then add 2, so a becomes 3

    double b = 5 / 2; // Quirk: Integer division is performed first, then the result is converted to double, so b becomes 2.0

    int c = 10 % 3; // Quirk: Modulus operator gives the remainder, so c becomes 1

    int d = 1.5; // Quirk: Truncation occurs, so d becomes 1

    double e = 5 / 2 + 0.5; // Quirk: Integer division first, then addition, so e becomes 2.5
    cout<<"block starts here"<<endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "e = " << e << endl;
    }
    return 0;
}
