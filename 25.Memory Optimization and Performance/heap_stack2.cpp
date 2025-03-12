/*
    Stack vs Heap with Classes and Structs in C++
    
    In C++, both **classes** and **structs** can be used to define complex data types. 
    The main difference between a class and a struct is that **struct** members are public by default, 
    while **class** members are private by default. 
    In terms of memory allocation (stack vs heap), both structs and classes can be allocated on either 
    the stack or the heap.

    Here, we’ll explore how both classes and structs behave on the stack and heap, showing:
    - How they are allocated.
    - Their respective memory management.
    - How constructors, destructors, and dynamic memory work in more complex scenarios.
    
    We'll begin with a simple `Point` struct and evolve to a more complex `Rectangle` class, 
    demonstrating memory allocation and efficiency.
*/

#include <iostream>

struct Point {
    int x, y; // Public by default in a struct.

    // Constructor
    Point(int x_val, int y_val) : x(x_val), y(y_val) {
        std::cout << "Point created at (" << x << ", " << y << ") on the stack or heap.\n";
    }

    // Destructor
    ~Point() {
        std::cout << "Point at (" << x << ", " << y << ") is destroyed.\n";
    }
};

class Rectangle {
private:
    Point topLeft; // Composition of a Point (stack or heap).
    int width, height;

public:
    // Constructor
    Rectangle(Point p, int w, int h) : topLeft(p), width(w), height(h) {
        std::cout << "Rectangle created with top-left corner at (" << topLeft.x << ", " << topLeft.y << ").\n";
    }

    // Area calculation
    int area() const {
        return width * height;
    }

    // Destructor
    ~Rectangle() {
        std::cout << "Rectangle is destroyed.\n";
    }
};

int main() {
    // Example 1: Stack Allocation for Point (Automatic)
    {
        Point stackPoint(5, 10); // Allocated on the stack.
        // No need to manually free memory; it is automatically destroyed when the scope ends.
    } // stackPoint is destroyed here (when the block ends).

    // Example 2: Heap Allocation for Point (Manual)
    Point* heapPoint = new Point(15, 20); // Allocated on the heap.
    // We need to manually delete the object to free the memory.
    delete heapPoint; // heapPoint is destroyed here.

    // Example 3: Stack Allocation for Rectangle (with composition)
    {
        Rectangle stackRectangle(Point(0, 0), 5, 10); // Both the rectangle and its `Point` are on the stack.
        std::cout << "Area of stackRectangle: " << stackRectangle.area() << std::endl;
        // Memory for the rectangle and its components is automatically managed.
    } // stackRectangle and its internal Point are destroyed here.

    // Example 4: Heap Allocation for Rectangle (Manual)
    Rectangle* heapRectangle = new Rectangle(Point(1, 1), 8, 12); // Rectangle and internal Point on the heap.
    std::cout << "Area of heapRectangle: " << heapRectangle->area() << std::endl;

    // We need to manually free the memory.
    delete heapRectangle; // heapRectangle is destroyed here.

    return 0;
}

/*
    Breakdown of Stack vs Heap with Classes/Structs:

    **1. Stack Allocation (Automatic)**:
        - In the first example, `stackPoint` is created on the stack. 
        - Its memory is automatically managed; once the scope ends, the destructor is called, and the memory is freed.
        - In the case of `stackRectangle`, the `Point` object inside the `Rectangle` is also allocated on the stack.
        - Stack allocation is faster and safer because memory is freed automatically when the scope ends.

    **2. Heap Allocation (Manual)**:
        - In the second example, `heapPoint` is allocated on the heap. 
        - We have to explicitly call `delete` to free the memory and prevent memory leaks.
        - Similarly, in the case of `heapRectangle`, the `Rectangle` and its internal `Point` are dynamically allocated.
        - Heap allocation provides more flexibility, but it comes with overhead due to manual memory management.

    **Constructors and Destructors**:
        - Both stack and heap objects call constructors when they are created, and destructors when they are destroyed.
        - On the stack, destruction happens automatically when the scope ends.
        - On the heap, destruction occurs only when `delete` is called.
    
    **Performance**:
        - **Stack**: Faster memory allocation and deallocation, no risk of memory leaks, but limited in size.
        - **Heap**: Slower due to pointer indirection and manual management, but can handle larger and more flexible structures.

    Next, let's explore a more complex scenario where classes involve **dynamic memory allocation** internally. This will show how heap allocation can be managed inside class methods themselves (using `new` and `delete`).
*/

#include <iostream>

class DynamicArray {
private:
    int* data;     // Dynamically allocated array on the heap.
    int size;      // Size of the array.

public:
    // Constructor that dynamically allocates an array of a given size
    DynamicArray(int s) : size(s) {
        data = new int[size]; // Allocate an array on the heap.
        for (int i = 0; i < size; ++i) {
            data[i] = i * 10; // Initialize values.
        }
        std::cout << "Dynamic array of size " << size << " created on the heap.\n";
    }

    // Destructor to free the dynamically allocated memory
    ~DynamicArray() {
        delete[] data; // Free the heap memory.
        std::cout << "Dynamic array destroyed and memory freed.\n";
    }

    // Method to print array elements
    void printArray() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Example 5: Dynamic Memory Management inside a Class
    DynamicArray array(5); // `data` array is on the heap, but `array` itself is on the stack.
    array.printArray();    // Accessing the dynamically allocated array.
    
    // When `array` goes out of scope, its destructor will be called, freeing the heap memory.

    return 0;
}

/*
    Conclusion:
    
    - In **stack allocation**, everything is managed automatically, making it faster and less error-prone.
    - In **heap allocation**, you have more flexibility and can allocate memory dynamically, but this requires explicit management (calling `delete`), and it introduces potential performance overhead.
    - **Classes and structs** behave similarly in terms of stack vs heap memory allocation, but managing more complex structures (like dynamic arrays) requires careful memory management to avoid leaks or other errors.
    
    Choosing between the stack and heap depends on your application's needs:
    - If you know the size of the data at compile time and it’s small, use the stack.
    - If the size is large or dynamic, use the heap but handle memory carefully to avoid issues.
*/