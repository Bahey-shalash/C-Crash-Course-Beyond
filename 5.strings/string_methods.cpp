/* ### Course 2: Useful `std::string` Methods ###

   This course explores some common `std::string` methods in C++, which can
   help you manipulate text data more easily.

   **Methods Covered:**
   - `size()` and `length()`: Get the number of characters in the string.
   - `empty()`: Check if the string is empty.
   - `substr()`: Extract a substring from the string.
   - `find()`: Find the position of a substring.
*/

#include <iostream>
#include <string>

int main() {
    std::string text = "Welcome to EPFL";

    // 1. Length and size
    std::cout << "Length of text: " << text.size() << '\n';

    // 2. Check if the string is empty
    if (text.empty()) {
        std::cout << "The text is empty.\n";
    } else {
        std::cout << "The text is not empty.\n";
    }

    // 3. Substring
    std::string epfl = text.substr(11, 4); // Extracts "EPFL"
    std::cout << "Extracted substring: " << epfl << '\n';

    // 4. Find a substring
    size_t position = text.find("EPFL");
    if (position != std::string::npos) {
        std::cout << "\"EPFL\" found at position: " << position << '\n';
    } else {
        std::cout << "\"EPFL\" not found.\n";
    }

    return 0;
}