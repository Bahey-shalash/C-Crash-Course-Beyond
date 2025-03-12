/*  
    ========================================================
    Lesson 4: Understanding `std::weak_ptr`
    ========================================================

    # What is `std::weak_ptr`?
    `weak_ptr<T>` is a **non-owning** smart pointer that references a `shared_ptr`
    without increasing its reference count. It is used to break cyclic dependencies.

    ## **Why Use `weak_ptr`?**
    - **Prevents memory leaks** caused by cyclic references in `shared_ptr`.
    - **Checks if resource is still valid** using `.expired()` before accessing it.

    ## **Topics Covered**
    1. Avoiding Circular References
    2. Checking Resource Validity
    3. `weak_ptr` with `shared_ptr`
*/

#include <iostream>
#include <memory>

struct Node {
    std::shared_ptr<Node> next; // BAD: Circular reference (Memory Leak!)
    ~Node() { std::cout << "Node destroyed\n"; }
};

struct SafeNode {
    std::weak_ptr<SafeNode> next; // FIX: Using weak_ptr breaks the cycle
    ~SafeNode() { std::cout << "SafeNode destroyed\n"; }
};

void cyclicReferenceProblem() {
    std::shared_ptr<Node> n1 = std::make_shared<Node>();
    std::shared_ptr<Node> n2 = std::make_shared<Node>();

    n1->next = n2;
    n2->next = n1; // Creates a circular reference -> MEMORY LEAK!
}

void weakPtrFix() {
    std::shared_ptr<SafeNode> n1 = std::make_shared<SafeNode>();
    std::shared_ptr<SafeNode> n2 = std::make_shared<SafeNode>();

    n1->next = n2; // Uses weak_ptr, preventing cycles
    n2->next = n1;
}

int main() {
    std::cout << "Demonstrating Circular Reference Problem:\n";
    cyclicReferenceProblem();

    std::cout << "\nDemonstrating Circular Reference Fix using weak_ptr:\n";
    weakPtrFix();

    return 0;
}