/* ### Course 3: Reading Strings with `cin` and `getline` ###

   This course demonstrates how to read `std::string` input from the user using
   `cin`, `getline`, and `getline(cin >> ws, ...)` (which skips leading whitespace).
*/

#include <iostream>
#include <string>

int main() {
    std::string name;
    std::string sentence;

    // Reading a single word (stops at whitespace)
    std::cout << "Enter your first name: ";
    std::cin >> name;
    std::cout << "Hello, " << name << "!\n";

    // Clear input buffer and read a full line
    std::cin.ignore(); // Discard leftover characters
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);
    std::cout << "You entered: " << sentence << '\n';

    // Using `getline` with `>> ws` to skip leading whitespace
    std::cout << "Enter another sentence with leading spaces: ";
    std::getline(std::cin >> std::ws, sentence); // Skips leading whitespace
    std::cout << "You entered (whitespace skipped): " << sentence << '\n';

    return 0;
}