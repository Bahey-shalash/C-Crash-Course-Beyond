/*
Smart Pointers in C++
----------------------
Smart pointers automate memory management, reducing the risk of leaks and errors.
This file demonstrates:
1. `unique_ptr`: For exclusive ownership.
2. `shared_ptr`: For shared ownership.
3. `weak_ptr`: For non-owning references.

Key Benefits:
- Automatic cleanup when pointers go out of scope.
- Safer and more efficient than raw pointers.
*/

#include <iostream>
#include <memory>
using namespace std;

int main() {
    // `unique_ptr` Example
    unique_ptr<int> uPtr = make_unique<int>(42);
    cout << "unique_ptr value: " << *uPtr << endl;

    // `shared_ptr` Example
    shared_ptr<int> sPtr1 = make_shared<int>(100);
    shared_ptr<int> sPtr2 = sPtr1; // Shared ownership
    cout << "shared_ptr value (shared by two): " << *sPtr1 << endl;

    // `weak_ptr` Example
    weak_ptr<int> wPtr = sPtr1; // Non-owning reference
    if (!wPtr.expired()) {
        cout << "weak_ptr value: " << *wPtr.lock() << endl;
    }

    return 0;
}