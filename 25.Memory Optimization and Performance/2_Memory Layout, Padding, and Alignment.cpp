/* ==========================================================================
Lesson 2: Memory Layout, Padding, and Alignment

Theory:
---------
Data structures are laid out in memory according to alignment rules.
- Padding is added between members to satisfy alignment requirements.
- Reordering members can reduce wasted space.

Key Points:
- Use the offsetof macro to inspect offsets.
- Edge Cases: Structures with mixed member types may have unexpected sizes.

Example:
---------
Comparing two struct layouts to see the effect of padding.
========================================================================== */

#include <cstddef>
#include <iostream>
using namespace std;

struct BasicStruct {
    char a;    // 1 byte
    int b;     // 4 bytes; likely 3 bytes of padding after 'a'
    double c;  // 8 bytes; may have additional padding for alignment
};

struct OptimizedStruct {
    double c;  // 8 bytes
    int b;     // 4 bytes
    char a;    // 1 byte; minimal padding at the end to align overall size
};

int main() {
    cout << "Size of BasicStruct: " << sizeof(BasicStruct) << " bytes\n";
    cout << "Offsets in BasicStruct:\n";
    cout << "  a: " << offsetof(BasicStruct, a) << "\n";
    cout << "  b: " << offsetof(BasicStruct, b) << "\n";
    cout << "  c: " << offsetof(BasicStruct, c) << "\n\n";

    cout << "Size of OptimizedStruct: " << sizeof(OptimizedStruct) << " bytes\n";
    cout << "Offsets in OptimizedStruct:\n";
    cout << "  c: " << offsetof(OptimizedStruct, c) << "\n";
    cout << "  b: " << offsetof(OptimizedStruct, b) << "\n";
    cout << "  a: " << offsetof(OptimizedStruct, a) << "\n";

    return 0;
}