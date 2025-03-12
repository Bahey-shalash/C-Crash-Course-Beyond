/*
    Understanding Stack vs Heap Memory Allocation in C++
    
    In C++, memory is typically divided into two regions: the **stack** (la pile) and the **heap** (le tas). 
    These two areas serve different purposes and have distinct behaviors in terms of memory allocation, access speed, and lifetime.

    Let's break down their characteristics using examples that illustrate both stack and heap usage:

    1. **The Stack (La Pile)**:
       - Memory on the stack is managed automatically. 
       - It's a fixed-size block of memory allocated for function calls and local variables.
       - When a function is called, the local variables are pushed onto the stack, and when the function returns, they are popped off.
       - **Fast Access**: Since the stack operates in a Last-In-First-Out (LIFO) manner, accessing stack variables is extremely fast.
       - **Limited Size**: The stack is typically smaller in size and if it exceeds its limit (e.g., due to excessive recursion), a "stack overflow" occurs.
       - **Automatic Memory Management**: Memory on the stack is automatically freed when the function exits.

    2. **The Heap (Le Tas)**:
       - Memory on the heap is managed manually by the programmer.
       - It allows dynamic memory allocation, which is useful when the size of data structures isn't known at compile-time.
       - **Slower Access**: Accessing variables on the heap is slower than the stack because it involves dynamic memory management and pointer dereferencing.
       - **Manual Memory Management**: You need to use `new` to allocate memory and `delete` to free it, or risk memory leaks if `delete` is forgotten.
       - **Large Size**: The heap is much larger compared to the stack, so it is suitable for larger data structures like arrays, linked lists, etc.
*/

#include <iostream>

int main() {
    // Example 1: Stack allocation vs Heap allocation using integers
    
    // Stack allocation (automatic memory management)
    int a = 10; // This integer is allocated on the stack.
    // The variable `a` will be destroyed automatically when the function (main) ends.
    std::cout << "Value of 'a' (stack): " << a << std::endl;
    
    // Heap allocation (manual memory management)
    int* b = new int(20); // This integer is allocated on the heap.
    // The pointer `b` stores the address of the dynamically allocated memory.
    std::cout << "Value of 'b' (heap): " << *b << std::endl;
    
    // We need to free the allocated memory manually.
    delete b; // If we forget this, the memory will not be released, causing a memory leak.
    // To avoid dangling pointer issues, it's good practice to set b to nullptr after deletion.
    b = nullptr;
    
    // Example 2: Stack-based array vs Heap-based array
    
    // Stack-based array (size known at compile time)
    int stackArray[5] = {1, 2, 3, 4, 5}; // Array allocated on the stack.
    // Size of the array must be known at compile time, and it's limited by the stack size.
    
    std::cout << "Stack Array: ";
    for(int i = 0; i < 5; ++i) {
        std::cout << stackArray[i] << " ";
    }
    std::cout << std::endl;

    // Heap-based array (size can be dynamic, decided at runtime)
    int size;
    std::cout << "Enter size of the dynamic array: ";
    std::cin >> size;

    int* heapArray = new int[size]; // Array allocated on the heap.
    
    // We can dynamically allocate an array of any size during runtime.
    for(int i = 0; i < size; ++i) {
        heapArray[i] = i * 2; // Initializing values.
    }

    std::cout << "Heap Array: ";
    for(int i = 0; i < size; ++i) {
        std::cout << heapArray[i] << " ";
    }
    std::cout << std::endl;

    // Freeing the heap memory.
    delete[] heapArray; // Use delete[] for arrays allocated with `new[]`.
    heapArray = nullptr; // Avoid dangling pointers.

    return 0;
}

/*
    Differences in Detail:

    1. **Speed**: 
       - Accessing `a` (stack variable) is faster because it's stored directly in the CPU's cache or registers.
       - Accessing `b` (heap variable) involves dereferencing a pointer, which means fetching the value at an address, adding extra steps and making it slower.

    2. **Memory Lifetime**:
       - `a` is automatically deallocated when the function `main()` ends.
       - `b` must be explicitly deallocated using `delete`, or else the memory stays allocated, leading to a **memory leak** (une fuite de mémoire).

    3. **Memory Size**:
       - Stack memory is limited in size (usually a few MBs), making it unsuitable for large data structures.
       - Heap memory is much larger, allowing you to allocate more memory at runtime (dynamic memory), but it's slower to access and more error-prone (e.g., if you forget to free memory).

    Advantages and Disadvantages:

    **Stack (La Pile)**:
    - **Advantages**:
        1. Very fast memory allocation and deallocation.
        2. Automatic memory management (no risk of memory leaks).
        3. More secure due to managed lifetime.
        
    - **Disadvantages**:
        1. Limited size, making it unsuitable for large data structures.
        2. Variables on the stack have a short lifetime (only exist during the function call).
        3. Stack overflow can occur if too much memory is used (e.g., deep recursion).

    **Heap (Le Tas)**:
    - **Advantages**:
        1. Large and flexible memory size, suitable for big and complex data structures.
        2. You can allocate memory dynamically, based on runtime requirements.
        
    - **Disadvantages**:
        1. Slower memory access due to pointer indirection.
        2. Manual memory management increases the risk of memory leaks if you forget to `delete`.
        3. Fragmentation can occur over time, where memory becomes inefficiently utilized.

    Conclusion:
    - The **stack** is ideal for small, short-lived variables and when speed is critical (e.g., local variables in functions).
    - The **heap** is useful when working with large data structures or when you need to allocate memory dynamically at runtime.
    - Understanding when to use each memory region is crucial for writing efficient C++ programs.
*/