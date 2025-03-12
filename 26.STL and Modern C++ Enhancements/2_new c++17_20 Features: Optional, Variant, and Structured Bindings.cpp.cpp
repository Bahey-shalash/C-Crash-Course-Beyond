/* ==========================================================================
Lesson 2: New C++17/20 Features: std::optional, std::variant, and Structured Bindings

Theory:
---------
Modern C++ introduces utilities that help write safer and more expressive code.
- std::optional: Represents an object that might or might not have a value.
- std::variant: A type-safe union for holding one of several types.
- Structured Bindings: Allow unpacking tuples, pairs, and structures.

Key Points:
- Useful for error handling, multiple return values, and type-safe unions.
- Edge Cases: Be cautious with std::variant when the wrong type is accessed.

Example:
---------
Demonstrating std::optional and structured bindings.
========================================================================== */

#include <iostream>
#include <optional>
#include <string>
#include <variant>
using namespace std;

optional<int> findValue(bool found) {
    if (found)
        return 42;
    else
        return nullopt;
}

int main() {
    auto result = findValue(true);
    if (result.has_value()) {
        cout << "Found value: " << result.value() << endl;
    } else {
        cout << "No value found." << endl;
    }

    // std::variant example:
    variant<int, string> data;
    data = "Hello, Variant!";
    // Using std::get_if to safely access variant data.
    if (auto pStr = std::get_if<string>(&data)) {
        cout << "Variant holds string: " << *pStr << endl;
    }

    // Structured bindings with pair:
    pair<int, string> myPair = {1, "one"};
    auto [number, word] = myPair;
    cout << "Structured binding: " << number << " -> " << word << endl;

    return 0;
}