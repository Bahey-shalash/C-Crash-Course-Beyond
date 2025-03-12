/*
 * Lesson: Basic Data Types in C++
 * --------------------------------
 * 
 * In C++, data types specify the type of data that a variable can hold.
 * Understanding data types is crucial because they determine:
 *  1. The amount of memory allocated for a variable.
 *  2. The range of values a variable can store.
 *  3. The operations that can be performed on the variable.
 * 
 * C++ provides several fundamental (primitive) data types:
 * 
 * 1. Integer Types (Types entiers):
 *    - `short` (16-bit, at least)
 *    - `int` (32-bit, at least)
 *    - `long` (at least 32-bit, often 64-bit)
 *    - `long long` (at least 64-bit)
 * 
 * 2. Floating-Point Types (Types à virgule flottante):
 *    - `float` (single precision, ~6-7 decimal digits)
 *    - `double` (double precision, ~15-16 decimal digits)
 *    - `long double` (extended precision, depends on implementation)
 * 
 * 3. Character Type (Type caractère):
 *    - `char` (typically 1 byte, stores a single character)
 * 
 * 4. Boolean Type (Type booléen):
 *    - `bool` (true or false)
 * 
 * 5. Wide Character Type:
 *    - `wchar_t` (used for larger character sets, e.g., Unicode)
 * 
 * Type Modifiers:
 * -----------------
 * To further modify integer types, we use:
 *   - `signed` (default, allows positive and negative values)
 *   - `unsigned` (only allows positive values, doubles the upper range)
 * 
 * These modifiers can be applied to `short`, `int`, `long`, and `char`.
 * 
 * Practical Example:
 */
 
#include <iostream>  // Include the standard input-output library
#include <limits>    // For numeric limits

int main() {
    // Integer types
    short a = 32767; // Maximum value for a short (typically)
    int b = 2147483647; // Maximum value for an int (typically)
    long c = 9223372036854775807; // Typical maximum value for long
    long long d = 9223372036854775807; // Maximum value for long long
    
    // Floating-point types
    float e = 3.141592f; // 'f' indicates float literal
    double f = 3.141592653589793;
    long double g = 3.141592653589793238L; // 'L' indicates long double
    
    // Character type
    char letter = 'A'; // Stores a single character
    wchar_t wide_letter = L'Ω'; // Wide character (Unicode, needs L prefix)
    
    // Boolean type
    bool is_cpp_fun = true; // Can be true or false

    // Unsigned integer
    unsigned int positive_only = 4294967295; // Maximum for 32-bit unsigned int
    
    // Displaying values
    std::cout << "Integer Types:\n";
    std::cout << "short: " << a << "\n";
    std::cout << "int: " << b << "\n";
    std::cout << "long: " << c << "\n";
    std::cout << "long long: " << d << "\n\n";
    
    std::cout << "Floating-Point Types:\n";
    std::cout << "float: " << e << "\n";
    std::cout << "double: " << f << "\n";
    std::cout << "long double: " << g << "\n\n";
    
    std::cout << "Character Types:\n";
    std::cout << "char: " << letter << "\n";
    std::wcout << L"wchar_t: " << wide_letter << L"\n\n"; // Using wcout for wide char
    
    std::cout << "Boolean Type:\n";
    std::cout << "bool: " << is_cpp_fun << "\n\n";
    
    std::cout << "Unsigned Type:\n";
    std::cout << "unsigned int: " << positive_only << "\n";
    
    return 0;
}

/*
 * Summary:
 * ---------
 * - C++ offers integer, floating-point, character, and boolean types.
 * - Integer types can be modified with `signed` and `unsigned`.
 * - Floating-point types vary in precision.
 * - `char` stores a single character; `wchar_t` is used for wide characters.
 * - `bool` represents true or false.
 * - Always consider memory size and limits when choosing types.
 */