/*
    Data Layout in Memory: How Elements Are Stored in Structs, Classes, and Data
   Structures on a 64-bit Machine
    ----------------------------------------------------------------------------------------------------------

    Understanding how elements are stored in memory is essential for writing efficient
   C++ programs. This class will focus on how data is laid out in memory on a 64-bit
   architecture, specifically looking at how elements are stored in different data
   structures like structs, classes, arrays, and more.

    Key concepts we will cover:

    1. **Memory Alignment and Padding**:
        On 64-bit machines, memory is aligned according to the word size of the CPU
   (typically 8 bytes). CPUs fetch data from memory more efficiently when data is
   aligned at word boundaries. For example, a 4-byte integer should ideally start at an
   address divisible by 4, and an 8-byte double at an address divisible by 8.

        - **Padding**: When the elements in a struct or class have different sizes, the
   compiler may introduce padding between elements to ensure proper alignment. This can
   result in wasted space, especially if the order of elements is not optimized.

    2. **Element Ordering in Structs and Classes**:
        The order of elements in a struct or class affects how much padding is added.
   By reordering members, you can reduce or eliminate padding, making the struct or
   class more compact and efficient.

    3. **Arrays**:
        Arrays store elements contiguously in memory. The memory layout of an array is
   straightforward: the elements are stored in consecutive memory locations, and each
   element's size depends on the data type of the array.

    4. **Pointer Sizes and Class Layout**:
        On a 64-bit machine, pointers are 8 bytes long, which impacts the memory layout
   of data structures containing pointers. In classes, virtual functions introduce an
   additional pointer to the virtual function table (vtable), which can also affect the
   layout.

    Let's dive into specific examples to understand how these concepts play out in C++
   code.
*/

#include <cstddef>  // For offsetof macro
#include <iostream>

// 1. Basic Struct with Padding Example
struct BasicStruct {
    char a;    // 1 byte
    int b;     // 4 bytes
    double c;  // 8 bytes
};

// 2. Reordered Struct for Better Alignment
struct OptimizedStruct {
    double c;  // 8 bytes
    int b;     // 4 bytes
    char a;    // 1 byte
    // Compiler adds 3 bytes of padding at the end to align to 8-byte boundaries.
};

// 3. Understanding Memory Layout in Classes
class BasicClass {
public:
    char a;    // 1 byte
    double b;  // 8 bytes
    int c;     // 4 bytes
};

// 4. Class with Virtual Function (introduces a vtable pointer)
class VirtualClass {
public:
    char a;    // 1 byte
    double b;  // 8 bytes
    int c;     // 4 bytes

    virtual void print() { std::cout << "Hello from VirtualClass" << std::endl; }
};

// 5. Array Memory Layout
void arrayMemoryLayout() {
    int array[5] = {1, 2, 3, 4, 5};
    std::cout << "Array elements are stored contiguously in memory:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "&array[" << i << "] = " << &array[i] << '\n';
    }
}

int main() {
    // 1. Understanding padding in structs
    std::cout << "Size of BasicStruct (with padding): " << sizeof(BasicStruct)
              << " bytes\n";
    std::cout << "Offsets in BasicStruct:\n";
    std::cout << "  Offset of a: " << offsetof(BasicStruct, a) << " bytes\n";
    std::cout << "  Offset of b: " << offsetof(BasicStruct, b) << " bytes\n";
    std::cout << "  Offset of c: " << offsetof(BasicStruct, c) << " bytes\n\n";

    // 2. Optimizing memory layout by reordering elements
    std::cout << "Size of OptimizedStruct: " << sizeof(OptimizedStruct) << " bytes\n";
    std::cout << "Offsets in OptimizedStruct:\n";
    std::cout << "  Offset of c: " << offsetof(OptimizedStruct, c) << " bytes\n";
    std::cout << "  Offset of b: " << offsetof(OptimizedStruct, b) << " bytes\n";
    std::cout << "  Offset of a: " << offsetof(OptimizedStruct, a) << " bytes\n\n";

    // 3. Memory layout in classes
    std::cout << "Size of BasicClass: " << sizeof(BasicClass) << " bytes\n";
    std::cout << "Offsets in BasicClass:\n";
    std::cout << "  Offset of a: " << offsetof(BasicClass, a) << " bytes\n";
    std::cout << "  Offset of b: " << offsetof(BasicClass, b) << " bytes\n";
    std::cout << "  Offset of c: " << offsetof(BasicClass, c) << " bytes\n\n";

    // 4. Virtual function adds a vtable pointer
    std::cout << "Size of VirtualClass (with vtable): " << sizeof(VirtualClass)
              << " bytes\n";

    // 5. Array memory layout demonstration
    arrayMemoryLayout();

    return 0;
}

/*
    Explanation of Results:
    ----------------------
    1. **BasicStruct Layout and Padding**:
        In `BasicStruct`, the compiler adds padding between members to align them
   properly.
        - `char a` takes 1 byte, and since `int b` requires 4-byte alignment, 3 bytes
   of padding are added after `a`.
        - Then, after `b` (which takes 4 bytes), 4 more bytes of padding are added to
   align `double c` to an 8-byte boundary. This results in a larger-than-expected size
   for `BasicStruct`.

    2. **OptimizedStruct Layout**:
        By reordering the members in `OptimizedStruct` (placing the largest member
   first), we reduce the amount of padding required, making the struct more compact.
   The compiler only adds 3 bytes of padding at the end, aligning the total size to 8
   bytes.

    3. **Class Layout**:
        `BasicClass` behaves similarly to structs in terms of memory layout, but with
   the added benefit of encapsulation and access control. Padding is still inserted
   between elements based on their size.

    4. **VirtualClass and the vtable**:
        When a class has virtual functions, the compiler inserts a pointer to a
   "virtual function table" (vtable) in the class. This pointer allows dynamic dispatch
   of virtual functions, increasing the class size by 8 bytes on a 64-bit system (the
   size of a pointer).

    5. **Array Memory Layout**:
        Arrays in C++ are stored contiguously in memory. Each element is placed
   immediately after the previous one, making array traversal very cache-friendly. The
   addresses printed for each element of the array demonstrate this contiguous layout.

    Memory alignment and padding are important concepts to understand when optimizing
   for memory usage and performance, especially in systems programming, embedded
   systems, and performance-critical applications.
*/