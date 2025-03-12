/*
 * Advanced Lesson: In-Depth Analysis of C++ Fundamental Data Types
 * -----------------------------------------------------------------
 * In this lesson, we go beyond the basics and explore:
 *
 * 1. Memory size and limits of data types.
 * 2. Precision and pitfalls in floating-point arithmetic.
 * 3. Character encodings and `char` vs `wchar_t` vs `char16_t` vs `char32_t`.
 * 4. The true/false representation in memory.
 * 5. When to use `signed` vs `unsigned` types.
 * 6. Type conversions, promotions, and pitfalls.
 *
 * Let's dive deep into these topics with practical examples.
 */

#include <iomanip>  // For setting precision
#include <iostream>
#include <limits>  // For querying type properties

int main() {
    // 1. Checking the Memory Size and Value Ranges of Data Types
    std::cout << "Data Type Properties:\n";
    std::cout << "----------------------\n";

    std::cout << "Size of short: " << sizeof(short) << " bytes\n";
    std::cout << "Size of int: " << sizeof(int) << " bytes\n";
    std::cout << "Size of long: " << sizeof(long) << " bytes\n";
    std::cout << "Size of long long: " << sizeof(long long) << " bytes\n\n";

    std::cout << "Size of float: " << sizeof(float) << " bytes\n";
    std::cout << "Size of double: " << sizeof(double) << " bytes\n";
    std::cout << "Size of long double: " << sizeof(long double) << " bytes\n\n";

    std::cout << "Size of char: " << sizeof(char) << " byte\n";
    std::cout << "Size of wchar_t: " << sizeof(wchar_t) << " bytes\n";
    std::cout << "Size of char16_t: " << sizeof(char16_t) << " bytes\n";
    std::cout << "Size of char32_t: " << sizeof(char32_t) << " bytes\n\n";

    std::cout << "Boolean size: " << sizeof(bool) << " byte\n\n";

    // 2. Numeric Limits
    std::cout << "Numeric Limits:\n";
    std::cout << "---------------\n";
    std::cout << "Max int: " << std::numeric_limits<int>::max() << "\n";
    std::cout << "Min int: " << std::numeric_limits<int>::min() << "\n";
    std::cout << "Max double: " << std::numeric_limits<double>::max() << "\n";
    std::cout << "Min double: " << std::numeric_limits<double>::lowest() << "\n\n";

    // 3. Floating-Point Precision & Pitfalls
    std::cout << "Floating-Point Precision:\n";
    std::cout << "-------------------------\n";
    double x = 0.1;
    double y = 0.2;
    double z = x + y;

    std::cout << std::setprecision(17);  // Show full double precision
    std::cout << "0.1 + 0.2 = " << z
              << "\n";  // Expected 0.3, but may print 0.30000000000000004
    std::cout << "Is (0.1 + 0.2 == 0.3)? " << (z == 0.3 ? "Yes" : "No") << "\n\n";

    /*
     * The issue above arises due to floating-point representation in binary.
     * Always use `std::abs(a - b) < epsilon` to compare floating-point numbers.
     */

    // 4. Character Encoding (ASCII, Unicode, UTF-8)
    std::cout << "Character Encodings:\n";
    std::cout << "--------------------\n";
    char ascii_char = 'A';
    wchar_t wide_char = L'Ω';
    char16_t utf16_char = u'Ω';
    char32_t utf32_char = U'Ω';

    std::cout << "ASCII Char: " << ascii_char << "\n";
    std::wcout << L"Wide Char (Unicode): " << wide_char << L"\n";
    std::cout << "UTF-16 Char (Unicode): " << static_cast<int>(utf16_char) << "\n";
    std::cout << "UTF-32 Char (Unicode): " << static_cast<int>(utf32_char) << "\n";

    /*
    why did we need to do a static cast to int?

    Because there is no direct operator<< for char16_t/char32_t in the standard
    library, casting them to int or converting them to a string is required to output
    them.
     */

    /*
     * `char` is 8-bit and mostly used for ASCII.
     * `wchar_t` can store wider characters but is platform-dependent.
     * `char16_t` and `char32_t` are explicitly defined for UTF-16 and UTF-32.
     */

    // 5. Boolean Representation in Memory
    std::cout << "Boolean Representation:\n";
    std::cout << "------------------------\n";
    bool flag1 = true;
    bool flag2 = false;
    std::cout << "True stored as: " << flag1 << "\n";
    std::cout << "False stored as: " << flag2 << "\n\n";

    /*
     * In memory, `bool` is stored as 1 byte (although it needs only 1 bit).
     * `true` is stored as `1`, and `false` is stored as `0`.
     */

    // 6. Signed vs Unsigned Pitfalls
    std::cout << "Signed vs Unsigned Pitfalls:\n";
    std::cout << "----------------------------\n";
    unsigned int unsigned_val = 0;
    signed int signed_val = -1;

    std::cout << "Unsigned 0 - 1 = " << (unsigned_val - 1) << "\n";  // Wraps around
    std::cout << "Signed -1: " << signed_val << "\n\n";

    /*
     * Be careful when mixing signed and unsigned types.
     * If an unsigned integer goes below zero, it wraps to the max positive value.
     */

    // 7. Type Conversions & Promotions
    std::cout << "Type Conversions:\n";
    std::cout << "-----------------\n";
    int int_val = 5;
    double double_val = 2.7;
    double result = int_val + double_val;  // Implicit conversion of int to double

    std::cout << "5 + 2.7 = " << result << "\n";  // Result is double
    std::cout << "Explicit cast: (int)2.7 = " << static_cast<int>(double_val)
              << "\n\n";

    /*
     * Type conversion follows a hierarchy:
     * - Integer types are promoted to `int` if smaller.
     * - `float` gets converted to `double` in mixed expressions.
     * - Use `static_cast<type>(value)` for explicit conversions.
     */

    return 0;
}

/*
 * Summary of Advanced Topics:
 * ----------------------------
 * 1. Use `sizeof(type)` and `std::numeric_limits<type>` to explore data sizes.
 * 2. Floating-point numbers have precision errors; compare with tolerance.
 * 3. `char` is for ASCII, `wchar_t`, `char16_t`, and `char32_t` handle Unicode.
 * 4. Boolean values are stored as `1` (true) and `0` (false).
 * 5. Be cautious with signed vs unsigned arithmetic to avoid overflow.
 * 6. Implicit and explicit type conversions affect calculations.
 */