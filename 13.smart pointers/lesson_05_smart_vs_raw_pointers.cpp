/*  
    ========================================================
    Lesson 5: Smart Pointers vs. Raw Pointers
    ========================================================

    # When to Use Smart Pointers?
    - **Use `unique_ptr`** when a resource has a single owner.
    - **Use `shared_ptr`** when multiple objects share ownership.
    - **Use `weak_ptr`** to break cyclic references.

    # When to Use Raw Pointers?
    - **For non-owning references** (e.g., function parameters).
    - **When performance is critical** and manual memory management is controlled.

    # Performance Comparison
    - `unique_ptr` is lightweight and efficient.
    - `shared_ptr` adds **reference counting overhead**.
    - `weak_ptr` avoids memory leaks in cyclic graphs.

    # Example: Comparing Ownership
*/

#include <iostream>
#include <memory>

void rawPointerExample() {
    int* ptr = new int(50);
    std::cout << "Raw Pointer Value: " << *ptr << "\n";
    delete ptr; // Manual deletion required!
}

void smartPointerExample() {
    std::unique_ptr<int> ptr = std::make_unique<int>(50);
    std::cout << "Smart Pointer Value: " << *ptr << "\n";
} // Automatic cleanup

int main() {
    std::cout << "Using Raw Pointer:\n";
    rawPointerExample();

    std::cout << "\nUsing Smart Pointer:\n";
    smartPointerExample();

    return 0;
}