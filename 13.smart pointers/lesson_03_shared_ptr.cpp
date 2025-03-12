/*  
    ========================================================
    Lesson 3: Deep Dive into `std::shared_ptr`
    ========================================================

    # What is `std::shared_ptr`?
    `std::shared_ptr<T>` is a smart pointer that enables **shared ownership** 
    of a dynamically allocated object. It maintains an internal **reference count** 
    to track how many `shared_ptr` instances point to the same resource.

    ## **Key Features of `shared_ptr`**
    - **Shared Ownership** → Multiple `shared_ptr` instances can manage the same object.
    - **Reference Counting** → Automatically deletes the object when the last `shared_ptr` goes out of scope.
    - **Exception Safety** → Ensures proper cleanup even if exceptions occur.
    - **Supports Custom Deleters** → Useful for handling non-heap resources (e.g., files, sockets).

    # When to Use `shared_ptr`?
    - When multiple parts of your program need access to the same resource.
    - When you need **automatic cleanup** but with **shared ownership**.
    - When managing dynamically allocated **objects** (not arrays, use `std::vector` instead).

    ## **Topics Covered**
    1. Basic `shared_ptr` usage
    2. Reference counting
    3. Avoiding cyclic references using `weak_ptr`
    4. Performance considerations
*/

#include <iostream>
#include <memory>

void basicSharedPtrExample() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
    std::cout << "Value: " << *ptr1 << "\n";
    std::cout << "Reference count: " << ptr1.use_count() << "\n";

    {
        std::shared_ptr<int> ptr2 = ptr1; // Shared ownership
        std::cout << "Reference count inside block: " << ptr1.use_count() << "\n";
    } // ptr2 goes out of scope

    std::cout << "Reference count after ptr2 is destroyed: " << ptr1.use_count() << "\n";
}

void customDeleterExample() {
    std::shared_ptr<int> ptr(new int(42), [](int* p) {
        std::cout << "Custom Deleter Called for: " << *p << "\n";
        delete p;
    });

    std::cout << "Value: " << *ptr << "\n";
}

class Resource {
public:
    Resource(int val) : value(val) { std::cout << "Resource Acquired: " << value << "\n"; }
    ~Resource() { std::cout << "Resource Released: " << value << "\n"; }
    void show() { std::cout << "Resource Value: " << value << "\n"; }
private:
    int value;
};

void sharedPtrWithClass() {
    std::shared_ptr<Resource> res1 = std::make_shared<Resource>(10);
    {
        std::shared_ptr<Resource> res2 = res1;
        res2->show();
        std::cout << "Reference count inside block: " << res1.use_count() << "\n";
    } // res2 goes out of scope

    std::cout << "Reference count after block: " << res1.use_count() << "\n";
}

int main() {
    std::cout << "Demonstrating Basic `shared_ptr`:\n";
    basicSharedPtrExample();

    std::cout << "\nDemonstrating `shared_ptr` with Custom Deleter:\n";
    customDeleterExample();

    std::cout << "\nDemonstrating `shared_ptr` with a Class:\n";
    sharedPtrWithClass();

    return 0;
}