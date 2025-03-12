/* ### Course 2: Array Indexing and Memory Safety in C++ ###

   Arrays in C++ are low-level data structures, providing direct memory access
   with minimal overhead. This allows for efficient operations, but it also means
   there is no built-in boundary checking. If you access an index out of the
   bounds of the array, the behavior is undefined. You may encounter:
   - A segmentation fault (if accessing memory outside the program’s range)
   - Overwriting unrelated memory, potentially causing difficult-to-trace bugs

   In this course, we explore how array indexing works in C++ and why
   out-of-bounds access is dangerous. We also compare the behavior of C-style arrays
   (raw arrays) with `std::vector` (a safer, dynamic array class in C++).

   Key Concepts:
   - Arrays start at index 0 and end at index `size - 1`.
   - Accessing out-of-bounds indices can lead to undefined behavior.

   Let's look at examples.
*/

#include <iostream>
#include <vector>

int main() {
    // C-style array example
    int arr[3] = {1, 2, 3};  // Array with fixed size

    // Proper indexing
    std::cout << "Array element at index 0: " << arr[0] << '\n';
    std::cout << "Array element at index 2: " << arr[2] << '\n';

    // Out-of-bounds access: Undefined behavior
    // Accessing `arr[3]` is beyond the allocated memory for this array.
    // This may cause a segmentation fault or overwrite other data in memory.
    // Uncomment the line below to see the undefined behavior in action.
    // std::cout << "Out-of-bounds access at index 3: " << arr[3] << '\n';

    // Example: Overwriting another variable (by chance)
    int overflow_test = 100;
    arr[3] = 42;  // This may overwrite memory, possibly `overflow_test`
    std::cout << "Potentially corrupted variable overflow_test: " << overflow_test
              << '\n';

    // Safer alternative: `std::vector`
    std::vector<int> vec = {10, 20, 30};

    // Accessing `std::vector` with at() method for safety
    try {
        std::cout << "Vector element at index 2: " << vec.at(2) << '\n';
        std::cout << "Out-of-bounds access with at(): ";
        std::cout << vec.at(3) << '\n';  // Throws an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught out-of-range exception: " << e.what() << '\n';
    }

    return 0;
}

/*
Explanation:
- `arr[3]` is an out-of-bounds access, which is undefined behavior in C++.
  Depending on the compiler and runtime, it may not immediately cause a crash,
  but it can corrupt other variables in memory, leading to bugs that are hard to
detect.

- In the `std::vector` example, using `at()` provides a bounds-checked access method,
  throwing an exception if we attempt to access an out-of-range index. This makes
  `std::vector` a safer choice in applications where dynamic size and memory safety
  are important.

Takeaway:
- Use `std::vector` over raw arrays when you need safe, dynamic-sized arrays. (its
msafer but slower, heap allocation vs stack allocation) 
- When working with raw arrays, always ensure indices are within bounds to avoid
  undefined behavior.
*/