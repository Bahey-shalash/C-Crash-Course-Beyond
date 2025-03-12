/* ### Course 1: Understanding the `size_t` Type in C++ ###

   `size_t` is an unsigned integer type specifically designed for representing
   sizes and counts in C++. It is guaranteed to be large enough to represent 
   the size of the largest object on a given platform, making it the standard 
   choice for memory size and indexing operations in C and C++.

   `size_t` is commonly used for:
   - Array indexing and loop counters
   - Representing memory sizes (e.g., size of an object in bytes)
   - Standard library functions, where it is used to ensure cross-platform compatibility

   Since `size_t` is unsigned, it avoids negative values that would not make sense
   in the context of size and memory calculations. However, this also means you 
   need to be cautious with expressions that could result in negative values.

   Let's explore its usage through examples.
*/

#include <iostream>

int main() {
    // Example 1: Basic `size_t` usage in an array
    const size_t array_size = 5; // `size_t` to represent array size
    int arr[array_size] = {10, 20, 30, 40, 50};

    // Use `size_t` for loop index to avoid issues with signed-unsigned comparison
    for (size_t i = 0; i < array_size; ++i) {
        std::cout << "Element at index " << i << " is: " << arr[i] << '\n';
    }

    // Example 2: Avoiding signed-unsigned mismatch warnings
    int index = -1; // Negative index (for demonstration purposes)
    if (index < 0 || static_cast<size_t>(index) >= array_size) {
        std::cout << "Index out of bounds.\n";
    }

    // Example 3: Why `size_t` matters in standard library functions
    // Functions like `std::vector::size()` return `size_t` because they 
    // represent sizes or counts, which should not be negative.

    return 0;
}