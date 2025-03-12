/* ### File: struct_type_order_padding.cpp ###
   ### Course 2: Exploring Memory Alignment and Padding by Type Order ###

   **Overview**
   The order in which members are declared in a `struct` can significantly impact 
   memory alignment and padding. Misaligned declarations can result in wasted 
   memory due to padding bytes. Reordering members can minimize padding, 
   leading to more efficient memory usage.

   **Key Concepts**
   - Understanding memory alignment and padding.
   - Exploring how declaration order affects memory layout.
   - Optimizing struct declarations to minimize padding.
*/

#include <iostream>

// Struct with inefficient member order
struct InefficientStruct {
    char a;      // 1 byte
    int b;       // 4 bytes
    char c;      // 1 byte
    double d;    // 8 bytes
};
/*
Memory layout (on a 64-bit system):
| a (1 byte) | padding (3 bytes) | b (4 bytes) | c (1 byte) | padding (7 bytes) | d (8 bytes) |
Total size: 24 bytes
*/

// Struct with optimized member order
struct EfficientStruct {
    double d;    // 8 bytes
    int b;       // 4 bytes
    char a;      // 1 byte
    char c;      // 1 byte
    // Padding (2 bytes) to align the size of the struct to 8 bytes
};
/*
Memory layout:
| d (8 bytes) | b (4 bytes) | a (1 byte) | c (1 byte) | padding (2 bytes) |
Total size: 16 bytes
*/

int main() {
    // Demonstrating sizes of structs
    InefficientStruct inefficient = {'A', 42, 'B', 3.14};
    EfficientStruct efficient = {3.14, 42, 'A', 'B'};

    std::cout << "Size of InefficientStruct: " << sizeof(inefficient) << " bytes\n";
    std::cout << "Size of EfficientStruct: " << sizeof(efficient) << " bytes\n";

    return 0;
}

/*
**Explanation**
1. **Alignment Requirements**:
   - Each member type has an alignment requirement:
       - `char`: 1-byte alignment
       - `int`: 4-byte alignment
       - `double`: 8-byte alignment
   - The alignment of the struct itself is determined by the largest alignment requirement among its members.

2. **InefficientStruct**:
   - `char a` (1 byte) is followed by padding (3 bytes) to align `int b` on a 4-byte boundary.
   - `char c` (1 byte) is followed by padding (7 bytes) to align `double d` on an 8-byte boundary.
   - Total size: 24 bytes (wasted 10 bytes due to padding).

3. **EfficientStruct**:
   - Members are ordered to minimize padding:
       - `double d` comes first (8 bytes, no padding needed before it).
       - `int b` follows (4 bytes, no padding needed).
       - `char a` and `char c` are grouped together (no padding between them, but 2 bytes added after them for alignment).
   - Total size: 16 bytes (only 2 bytes of padding).

**Takeaways**:
- **Member ordering matters**: Place members with the largest alignment requirements first.
- **Alignment boundaries**: Ensure alignment requirements are satisfied while minimizing padding.

By reordering members, memory usage can be optimized for performance-critical or memory-constrained applications.
*/