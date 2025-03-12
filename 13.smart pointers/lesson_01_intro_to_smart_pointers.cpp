/*  
    ========================================================
    Lesson 2: Deep Dive into `std::unique_ptr`
    ========================================================

    # What is `std::unique_ptr`?
    - A smart pointer that **exclusively owns** a dynamically allocated object.
    - Automatically deallocates memory when it goes out of scope.
    - **Move-only**: Cannot be copied, only moved.

    # Features:
    - Prevents memory leaks by handling `delete` automatically.
    - Transfers ownership via `std::move()`.
    - Can use **custom deleters**.
    - Can be used with dynamically allocated **single objects or arrays**.

    # Lesson Topics:
    1. Creating and Using `unique_ptr`
    2. Move Semantics and Ownership Transfer
    3. Using Custom Deleters
    4. Managing Dynamic Arrays with `unique_ptr`
*/

#include <iostream>
#include <memory> // Required for smart pointers

// Example of a class that uses unique_ptr
class Resource {
public:
    Resource(int val) : value(val) { std::cout << "Resource Acquired: " << value << "\n"; }
    ~Resource() { std::cout << "Resource Released: " << value << "\n"; }
    void show() { std::cout << "Resource Value: " << value << "\n"; }
private:
    int value;
};

void ownershipTransfer() {
    std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>(100);
    
    // Transfer ownership
    std::unique_ptr<Resource> ptr2 = std::move(ptr1);
    
    if (!ptr1) {
        std::cout << "ptr1 is now empty after ownership transfer.\n";
    }
    ptr2->show();
}

void customDeleterExample() {
    std::unique_ptr<int, void(*)(int*)> ptr(new int(42), [](int* p) {
        std::cout << "Custom Deleter Called for: " << *p << "\n";
        delete p;
    });

    std::cout << "Value: " << *ptr << "\n";
}

void uniquePtrArrayExample() {
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Demonstrating Unique Pointer:\n";
    std::unique_ptr<Resource> ptr = std::make_unique<Resource>(10);
    ptr->show();

    std::cout << "\nDemonstrating Ownership Transfer:\n";
    ownershipTransfer();

    std::cout << "\nDemonstrating Custom Deleter:\n";
    customDeleterExample();

    std::cout << "\nDemonstrating Unique Pointer with Arrays:\n";
    uniquePtrArrayExample();

    return 0;
}