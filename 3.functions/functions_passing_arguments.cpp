/*
    ### C++ Course: Passing Arguments to Functions
    
    This file demonstrates:
    1. Passing by Value: Creates a copy of the argument, original remains unchanged.
    2. Passing by Reference: Passes a reference to the argument, allowing modifications.
*/

#include <iostream>
using namespace std;

// Function prototypes
void passByValue(int a);
void passByReference(int &b);

int main() {
    int num = 10;
    cout << "Original num: " << num << endl;
    
    passByValue(num);
    cout << "After passByValue, num: " << num << endl;
    
    passByReference(num);
    cout << "After passByReference, num: " << num << endl;

    return 0;
}

void passByValue(int a) {
    a += 5;
    cout << "Inside passByValue, a: " << a << endl;
}

void passByReference(int &b) {
    b += 5;
    cout << "Inside passByReference, b: " << b << endl;
}

/*
    - Passing by Value: Changes to `a` inside `passByValue` don’t affect `num` in `main`.
    - Passing by Reference: Changes to `b` inside `passByReference` modify `num` in `main`.

    Compile and run:
        g++ functions_passing_arguments.cpp -o functions_passing_arguments
        ./functions_passing_arguments
*/