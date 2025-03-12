/*  
    ========================================================
    Lesson 2: Deep Dive into `std::unique_ptr`
    ========================================================

    # Overview:
    `std::unique_ptr<T>` is a smart pointer that ensures exclusive ownership
    of a dynamically allocated object. When the `unique_ptr` goes out of 
    scope, the resource is automatically deallocated.

    # Features of `unique_ptr`:
    - Exclusive ownership: Only one `unique_ptr` can own an object.
    - Move semantics: Ownership can be transferred using `std::move()`.
    - Automatic cleanup: No need for `delete`.
    - Supports custom deleters.
    - Lightweight and efficient.

    # When to Use:
    - When dynamic memory is needed but **ownership should not be shared**.
    - When working with **RAII (Resource Acquisition Is Initialization)**.

    # Topics Covered:
    1. Basic usage of `unique_ptr`
    2. Move semantics with `std::move`
    3. Custom deleters
    4. Using `unique_ptr` with arrays
    5. Performance benefits and best practices
*/

#include <iostream>
#include <memory> // Required for smart pointers

// Example of a custom deleter
struct CustomDeleter {
    void operator()(int* ptr) {
        std::cout << "Custom deleting pointer: " << *ptr << "\n";
        delete ptr;
    }
};

int main() {
    std::cout << "Creating a unique_ptr...\n";

    // Creating a unique_ptr using std::make_unique (Best practice)
    std::unique_ptr<int> ptr1 = std::make_unique<int>(42);
    std::cout << "Value inside unique_ptr: " << *ptr1 << "\n";

    // Transferring ownership using std::move (ptr1 loses ownership)
    std::unique_ptr<int> ptr2 = std::move(ptr1);
    if (!ptr1) {
        std::cout << "ptr1 is now empty after move.\n";
    }
    std::cout << "Value in ptr2: " << *ptr2 << "\n";

    // Demonstrating a custom deleter
    std::unique_ptr<int, CustomDeleter> ptr3(new int(99));

    // Working with arrays using `unique_ptr<T[]>`
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0; // Memory automatically cleaned up
}