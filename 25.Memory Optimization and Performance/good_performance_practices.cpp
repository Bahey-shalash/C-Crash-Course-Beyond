/*
    Performance Optimization in C++: Best Practices for Efficient Code
    -------------------------------------------------------------------
    In this class, we will explore key techniques to enhance the performance of
    C++ programs, focusing on memory management, computational efficiency, and
    data structures.

    Below, we break down various techniques:

    1. **Preallocating memory using `std::vector::reserve()` or
   `std::vector::resize()`**: Dynamically resizing a vector can lead to multiple
   reallocations, increasing overhead. Use `reserve()` or `resize()` to allocate
   sufficient memory upfront when the number of elements is known in advance.

    2. **Avoid Unnecessary Copies with Move Semantics**:
        Large object copies can be expensive. Use move semantics to transfer ownership
        without duplicating resources.

    3. **Use `std::unordered_map` instead of `std::map`**:
        If key-value pairs do not require sorting, prefer `std::unordered_map`, which
   has faster average lookup time due to its hash table implementation.

    4. **Minimize Dynamic Memory Allocation**:
        Frequent heap allocations are expensive. Prefer stack memory or use object
   pools for performance-critical code.

    5. **Minimize Expensive Computations Inside Loops**:
        Precompute values outside loops if possible to avoid unnecessary
   recalculations.

    6. **Use `std::move()` to Avoid Copying Large Objects**:
        Use `std::move()` to avoid deep copies of large objects, transferring their
        contents instead.

    7. **Use Range-Based Loops to Improve Code Clarity and Efficiency**:
        Range-based loops simplify iteration and avoid unnecessary calls to `size()` or
        other overhead.

    8. **Object Pooling for Small Object Allocations**:
        Reuse memory for small objects instead of constantly reallocating them on the
   heap.

    9. **Use `const` Wherever Possible**:
        Declaring variables and functions as `const` helps the compiler make
   optimizations and reduces the chance of errors.

    10. **Prefer `emplace_back()` over `push_back()` for In-Place Construction**:
        Construct objects directly within a container using `emplace_back()` to avoid
        temporary object creation and copying.

    11. **Inline Small Functions**:
        Inlining small, frequently-used functions avoids function call overhead, but be
        cautious about overuse, as it may increase binary size.

    12. **Mark Functions as `noexcept`**:
        Use `noexcept` to indicate that a function does not throw exceptions, which
   allows the compiler to optimize further.

    13. **Use `std::array` for Fixed-Size Arrays**:
        `std::array` allocates memory on the stack, making it more efficient than
   `std::vector` for fixed-size collections.

    14. **Use `std::string_view` for Non-Owning String References**:
        If you only need to reference a string, use `std::string_view` to avoid
   unnecessary copies, which reduces memory and CPU usage.

    15. **Use `reserve()` for Hash Tables**:
        Preallocate space in hash tables (`std::unordered_map`) to avoid rehashing
   during multiple insertions.

    16. **Avoid Virtual Functions If Not Needed**:
        Virtual functions introduce runtime overhead. Use static polymorphism with
   templates if compile-time dispatch is sufficient.

    17. **Use `std::pmr` for Custom Memory Resource Management**:
        C++17 introduces `std::pmr` (polymorphic memory resource), which allows
   fine-grained control over memory allocations.

    18. **Prefer Standard Algorithms Over Manual Loops**:
        Use optimized algorithms from the Standard Library (e.g., `std::sort`,
   `std::find`) instead of custom loops to leverage the compiler's optimizations.

    19. **Optimize for Cache Locality**:
        Use contiguous memory containers like `std::vector` to improve cache locality,
        which reduces cache misses and improves performance.

    20. **Use `constexpr` for Compile-Time Evaluation**:
        Use `constexpr` to evaluate values at compile time, reducing runtime
   computation overhead.

    Now, let's illustrate these concepts with detailed C++ examples.
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <memory_resource>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

// Function to demonstrate constexpr
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main() {
    // 1. Preallocating memory with reserve() to avoid multiple reallocations
    std::vector<int> vec;
    vec.reserve(10000);  // Efficient allocation up front
    for (int i = 0; i < 10000; ++i) {
        vec.push_back(i);  // No reallocations needed
    }

    // 2. Avoid unnecessary copies by using move semantics
    std::vector<int> large_vector(5000, 42);
    std::vector<int> moved_vector =
        std::move(large_vector);  // Efficient move, no copying

    // 3. Prefer std::unordered_map over std::map for faster access when sorting is
    // unnecessary
    std::unordered_map<int, std::string> umap;
    umap[1] = "one";
    umap[2] = "two";

    // 4. Avoid dynamic memory allocation by preferring stack memory where possible
    std::array<int, 100>
        stack_array;  // Allocated on the stack, more efficient than heap

    // 5. Minimize expensive computations inside loops
    const int expensive_computation = 100 * 100;
    for (int i = 0; i < 1000000; ++i) {
        int result = i * expensive_computation;  // Precomputed outside the loop
    }

    // 6. Using std::move to avoid copying
    std::string large_string = "This is a large string";
    std::string another_string = std::move(large_string);  // No copy, move instead

    // 7. Use range-based loops with references for better performance
    std::vector<int> data = {1, 2, 3, 4, 5};
    for (const auto& elem : data) {
        std::cout << elem << " ";  // No copying of elements
    }
    std::cout << '\n';

    // 8. Object pooling for small objects (hypothetical example)
    // Boost.Pool or custom allocators can be used to manage object reuse.

    // 9. Use const wherever possible
    const int immutable_value = 42;
    std::cout << "Immutable value: " << immutable_value << '\n';

    // 10. Prefer emplace_back over push_back for in-place construction
    std::vector<std::pair<int, std::string>> pairs;
    pairs.emplace_back(1, "one");  // Directly constructs in-place, no copy

    // 11. Inline small functions (demonstrated with the factorial function above)
    std::cout << "Factorial of 5 (constexpr): " << factorial(5) << '\n';

    // 12. noexcept functions allow for better optimization
    auto noexcept_function = []() noexcept {
        std::cout << "This function won't throw exceptions.\n";
    };
    noexcept_function();

    // 13. Use std::array for fixed-size arrays
    std::array<int, 10> fixed_array = {1, 2, 3, 4, 5};

    // 14. Use std::string_view for non-owning references to strings
    std::string long_string =
        "This is a very large string that we don't want to copy.";
    std::string_view view = long_string;  // No copy, just a view
    std::cout << view << '\n';

    // 15. Use reserve() for hash tables to avoid rehashing
    std::unordered_map<int, std::string> hash_table;
    hash_table.reserve(1000);  // Preallocate space

    // 16. Avoid virtual functions when not needed (example class skipped for brevity)

    // 17. Use std::pmr for efficient memory management (C++17)
    std::pmr::monotonic_buffer_resource resource;
    std::pmr::vector<int> pmr_vector(&resource);
    pmr_vector.reserve(10000);  // Efficient memory allocation with custom resource

    // 18. Prefer standard algorithms over manual loops
    std::vector<int> unsorted_data = {5, 3, 1, 4, 2};
    std::sort(unsorted_data.begin(), unsorted_data.end());  // Optimized sort

    // 19. Optimize for cache locality by accessing contiguous memory
    for (int i = 0; i < 10000; ++i) {
        vec[i] = i;  // Sequential memory access is faster due to better cache locality
    }

    // 20. Use constexpr to compute at compile-time (see factorial above)

    return 0;
}

/*
    Conclusion:
    ----------
    By following these best practices, we can significantly improve the performance of
    C++ programs. These techniques include memory optimizations, minimizing unnecessary
    computations, leveraging modern C++ features like move semantics and `constexpr`,
    and using the most appropriate data structures and algorithms for the task at hand.
    Remember to always profile your code to identify bottlenecks and apply
   optimizations where they will have the most impact.
*/