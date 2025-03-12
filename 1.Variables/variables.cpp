#include <iostream>
using namespace std;

int main() {
    // Variable Declaration and Initialization
    int age = 25; // Initializing an integer variable 'age' with the value 25
    double pi = 3.14159; // Initializing a double variable 'pi' with the value 3.14159
    char grade = 'A'; // Initializing a character variable 'grade' with the character 'A'
    bool isStudent = true; // Initializing a boolean variable 'isStudent' with the value 'true'

    // Multiple Variables Initialization
    int num1 = 10, num2 = 20; // Initializing two integers, 'num1' and 'num2'
    double salary = 45000.50, taxRate = 0.18; // Initializing double variables 'salary' and 'taxRate'

    // Variable Declaration and Initialization using "type nom(valeur);"
    unsigned int positiveValue(100); // Initializing an unsigned integer variable 'positiveValue' with the value 100
    // Explanation: An unsigned int can only store non-negative integers (zero and positive values). 
    // Explanation: This syntax combines both declaration and initialization in a single step.

    // Variable Declaration without Initialization
    string name; // Declaring a string variable 'name' without initialization
    int quantity; // Declaring an integer variable 'quantity' without initialization

    // Variable Assignment
    age = 30; // Assigning a new value (30) to the 'age' variable
    grade = 'B'; // Assigning a new character ('B') to the 'grade' variable

    // Output
    cout << "Age: " << age << endl;
    cout << "Pi: " << pi << endl;
    cout << "Grade: " << grade << endl;
    cout << "Is a Student: " << isStudent << endl;

    // Input
    cout << "Enter your name: ";
    cin >> name; // Reading input and storing it in the 'name' variable
    cout << "Hello, " << name << "!" << endl;

    // Performing Operations
    int sum = num1 + num2; // Adding two integers and storing the result in 'sum'
    double totalPrice = quantity * taxRate; // Multiplying two variables and storing the result in 'totalPrice'

    // Output the results of operations
    cout << "Sum: " << sum << endl;
    cout << "Total Price: " << totalPrice << endl;

    /*
    const int age = 25; // Declaring a constant integer variable 'age' with the value 25
    age = 30; // This will result in a compilation error because you can't change a const variable's value.
    */

    return 0;
}
/*List of invalid variable names

int café = 5;          // Contains 'é'
double pi_π = 3.14159; // Contains 'π' (Greek letter)
char ☺_face = 'A';     // Contains '☺' (smiley face)
float 1234€ = 99.99;   // Starts with a digit and contains '€' (Euro symbol)
bool #error = true;    // Contains '#' (pound/hash symbol)
int 1element = 42;   // Starts with a digit
double n-carre = 9.0; // Contains a hyphen
float α = 2.0;        // Uses a Greek letter 'α'
int 😃 = 100;         // Uses an emoji
char mIxEdCaSe = 'A'; // Uses a non-standard mix of uppercase and lowercase letters
float my variable = 3.14; // Contains a space
int $count = 5;        // Uses a dollar sign
double __value__ = 7.5; // Excessive underscores
int while = 10;        // Uses a reserved keyword
bool @valid = true;    // Contains '@'

*/