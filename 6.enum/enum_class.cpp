/* ### File: enum_class.cpp ###
   ### Course 2: `enum class` in Modern C++ ###
   should probably move this course to the OOP folder

   C++11 introduced `enum class`, also known as "scoped enumeration". This 
   provides stricter type safety and avoids name clashes by requiring 
   qualification with the enum type name.

   **Key Concepts**
   - Declaring an `enum class` with a specified type
   - Using `enum class` values with strong typing
   - Specifying an underlying integer type (optional)
*/

#include <iostream>

enum class Color : int {  // Scoped and strongly typed `enum class`
    RED,        // 0 by default
    GREEN,      // 1
    BLUE = 10,  // Custom value: 10
    YELLOW      // 11
};

int main() {
    Color favoriteColor = Color::GREEN;

    // Using `enum class` values with explicit type qualification
    if (favoriteColor == Color::GREEN) {
        std::cout << "Favorite color is green!\n";
    }

    // Accessing specific values of `enum class`
    std::cout << "Enum class value for BLUE: " << static_cast<int>(Color::BLUE) << '\n';
    std::cout << "Enum class value for YELLOW: " << static_cast<int>(Color::YELLOW) << '\n';

    return 0;
}

/*
   Expected Output:
   Favorite color is green!
   Enum class value for BLUE: 10
   Enum class value for YELLOW: 11
*/