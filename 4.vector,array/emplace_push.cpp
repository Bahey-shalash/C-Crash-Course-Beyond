/* ### Course: Why You Should Prefer `emplace_back` Over `push_back` in C++ ###

   **Overview**
   When working with `std::vector`, `std::deque`, and other C++ Standard Library 
   containers, you’ll often need to add elements to the end of the container. 
   Two commonly used methods for this are:
   - `push_back()`: Adds a copy (or move) of an element to the end.
   - `emplace_back()`: Constructs the element directly in place at the end of the container.

   While both achieve similar outcomes, `emplace_back` is often more efficient 
   and preferable over `push_back`. `emplace_back` can construct elements in place 
   without needing a temporary copy, reducing unnecessary allocations and 
   potentially improving performance.

   **Key Differences Between `push_back` and `emplace_back`:**
   - **`push_back`**: Takes an existing object (by copy or move) and appends it to the container.
   - **`emplace_back`**: Forwards constructor arguments and constructs the object directly at the container's end.

   **When to Use `emplace_back`:**
   - When adding complex objects (such as classes with multiple data members).
   - When constructing an object in place avoids unnecessary copies or moves.
   - Whenever you can construct the object directly with arguments, rather than needing an existing object.

   Let's dive into examples and see how `emplace_back` can be beneficial.
*/

#include <iostream>
#include <vector>
#include <string>

class Example {
public:
    int id;
    std::string name;

    // Constructor
    Example(int id, const std::string& name) : id(id), name(name) {
        std::cout << "Constructed Example(" << id << ", " << name << ")\n";
    }

    // Copy constructor
    Example(const Example& other) : id(other.id), name(other.name) {
        std::cout << "Copy Constructed Example(" << other.id << ", " << other.name << ")\n";
    }

    // Move constructor
    Example(Example&& other) noexcept : id(other.id), name(std::move(other.name)) {
        std::cout << "Move Constructed Example(" << id << ", " << name << ")\n";
    }
};

int main() {
    std::vector<Example> examples;

    // Example with `push_back`
    std::cout << "Using push_back:\n";
    Example ex1(1, "Alice");    // Create object ex1
    examples.push_back(ex1);    // Copy ex1 into the vector

    Example ex2(2, "Bob");
    examples.push_back(std::move(ex2));  // Move ex2 into the vector

    // Clear the vector for the next example
    examples.clear();

    // Example with `emplace_back`
    std::cout << "\nUsing emplace_back:\n";
    examples.emplace_back(3, "Charlie");  // Constructs directly in place
    examples.emplace_back(4, "Daisy");    // Constructs directly in place

    return 0;
}

/*
Explanation:
- In the `push_back` example:
    - `push_back` with `ex1` involves a **copy** of `ex1` into the vector, invoking 
      the copy constructor. This is unnecessary overhead if we can construct 
      the object directly in the vector.
    - `push_back` with `std::move(ex2)` moves `ex2` into the vector, which avoids 
      copying but still requires an intermediate `Example` object before it can be moved.

- In the `emplace_back` example:
    - `emplace_back` directly constructs the objects for "Charlie" and "Daisy" 
      inside the vector without needing any intermediate copy or move. 
    - This eliminates the need for a temporary `Example` object, making `emplace_back` 
      more efficient than `push_back` in this scenario.

Takeaways:
- **Always prefer `emplace_back`** when adding elements to a container if you are
  constructing the element with arguments. This reduces or eliminates unnecessary 
  copy and move operations, making the code more efficient.
- `push_back` can still be useful if you already have an existing object that 
  you want to add to the container, but if you’re constructing objects with 
  arguments, `emplace_back` is the preferred choice.
*/