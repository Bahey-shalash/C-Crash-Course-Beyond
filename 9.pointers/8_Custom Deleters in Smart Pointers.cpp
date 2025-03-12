/*
Advanced Topic: Custom Deleters in Smart Pointers
-------------------------------------------------
In this advanced section, we will explore:
1. Custom deleters with `unique_ptr` and `shared_ptr`.
2. Practical use cases for custom deleters.
3. Examples of using smart pointers for managing resources beyond memory.

Key concepts:
- Smart pointers allow custom deleters to handle non-standard cleanup logic.
- This is useful for resources like file handles, sockets, or other non-memory objects.
- Custom deleters are provided as a callable object (function pointer, lambda, or functor).

*/

#include <iostream>
#include <memory> // For smart pointers
#include <cstdio> // For file handling
using namespace std;

// Step 1: Custom Deleter for Unique Pointers
void uniquePointerCustomDeleter() {
    cout << "\nUsing custom deleter with unique_ptr:" << endl;

    // Open a file
    FILE* file = fopen("example.txt", "w");
    if (!file) {
        cerr << "Failed to open file!" << endl;
        return;
    }

    // Create a unique_ptr with a custom deleter
    unique_ptr<FILE, decltype(&fclose)> filePtr(file, fclose);

    // Write to the file
    fprintf(filePtr.get(), "Hello, World!\n");

    // The file will be automatically closed when filePtr goes out of scope
}

// Step 2: Custom Deleter for Shared Pointers
void sharedPointerCustomDeleter() {
    cout << "\nUsing custom deleter with shared_ptr:" << endl;

    // Dynamically allocate an integer
    shared_ptr<int> sptr(new int(42), [](int* p) {
        cout << "Custom deleter called for shared_ptr!" << endl;
        delete p; // Free the memory
    });

    // Use the shared_ptr
    cout << "Value in shared_ptr: " << *sptr << endl;

    // Custom deleter will be called automatically when the shared_ptr is destroyed
}

// Step 3: Practical Use Case: Managing Non-Memory Resources
void resourceManagementExample() {
    cout << "\nManaging non-memory resources with smart pointers:" << endl;

    // Simulate acquiring a resource (e.g., socket or file descriptor)
    int resource = 100; // Placeholder for a hypothetical resource ID

    // Create a shared_ptr with a custom deleter
    shared_ptr<int> resourcePtr(&resource, [](int* res) {
        cout << "Releasing resource ID: " << *res << endl;
        // Simulate releasing the resource
    });

    // Use the resource
    cout << "Using resource ID: " << *resourcePtr << endl;

    // Resource will be released automatically when resourcePtr goes out of scope
}

int main() {
    // Step 1: Custom Deleter with Unique Pointer
    uniquePointerCustomDeleter();

    // Step 2: Custom Deleter with Shared Pointer
    sharedPointerCustomDeleter();

    // Step 3: Managing Non-Memory Resources
    resourceManagementExample();

    return 0;
}