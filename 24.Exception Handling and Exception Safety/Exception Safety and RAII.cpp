/* ==========================================================================
Lesson 3: Exception Safety and RAII

Theory:
---------
RAII (Resource Acquisition Is Initialization) ties resource management to object
lifetime. This technique ensures that resources (memory, file handles, etc.) are
released automatically when objects go out of scope, even if an exception is thrown.

Key Points:
- Use smart pointers (std::unique_ptr, std::shared_ptr) to manage dynamic memory.
- Write classes so that their destructors free all resources.
- Use noexcept where appropriate.
- Edge Cases: Ensure that your classes are exception-safe (basic, strong, or no-throw
guarantees).

Example:
---------
A simple class that uses a smart pointer to manage dynamic memory safely.
========================================================================== */

#include <iostream>
#include <memory>
using namespace std;

class Resource {
public:
    Resource() { cout << "Resource acquired." << endl; }
    ~Resource() { cout << "Resource released." << endl; }
};

void processResource() {
    // Using std::unique_ptr ensures that the resource is automatically freed.
    unique_ptr<Resource> resPtr = make_unique<Resource>();
    // Do some processing here.
    // If an exception is thrown, the unique_ptr destructor will release the resource.
    // throw std::runtime_error("Error during processing!"); // Uncomment to test
    // exception safety.
}

int main() {
    try {
        processResource();
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }
    return 0;
}