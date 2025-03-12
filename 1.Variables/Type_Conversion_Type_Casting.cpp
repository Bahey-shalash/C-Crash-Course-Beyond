/*
    ### C++ Course: Comprehensive Guide to Type Conversion and Type Casting
    
    In C++, type conversions allow values of one data type to be converted to another. 
    Conversions can be:
    1. **Automatic (Implicit) Conversions** - Automatically handled by the compiler for compatible types.
    2. **Explicit Conversions (Casting)** - Needed when automatic conversion could lead to errors or unexpected behavior.
    3. **Type Casting Operators** - Used for explicit conversions, especially with incompatible types.

    Topics Covered:
    1. Automatic Conversions (Implicit)
    2. Boolean Conversions
    3. Explicit Conversions with Casting Operators
    4. Common Pitfalls and Best Practices
*/

#include <iostream>
using namespace std;

int main() {
    // 1. Automatic (Implicit) Conversions
    /*
        C++ allows implicit (automatic) conversions between compatible types.
        For example, smaller types (like `int`) can be automatically promoted to larger types (like `double`).
        
        However, implicit conversions can also result in data loss or unexpected behavior when converting 
        from larger types to smaller ones.
    */
    
    int intVar = 42;
    double doubleVar = intVar;  // Implicit conversion from `int` to `double`

    cout << "Integer (intVar): " << intVar << endl;
    cout << "Converted to double (doubleVar): " << doubleVar << endl;

    // Potential Pitfall: Data Loss
    double largeValue = 12345.6789;
    int truncatedValue = largeValue;  // Implicit conversion from `double` to `int` (fractional part lost)

    cout << "\nDouble (largeValue): " << largeValue << endl;
    cout << "Converted to int (truncatedValue): " << truncatedValue << " (fractional part lost)\n";

    // 2. Boolean Conversions
    /*
        Conversions to `bool` in C++ follow these rules:
        - Zero values (0, 0.0) and empty characters ('\0') convert to `false`.
        - Non-zero values convert to `true`.
        
        Converting from `bool` to other types results in 1 for `true` and 0 for `false`.
    */

    int zeroInt = 0;
    int nonZeroInt = 123;
    bool boolFromZero = zeroInt;          // `false`
    bool boolFromNonZero = nonZeroInt;     // `true`

    cout << "\nInteger zeroInt (0) converted to bool: " << boolFromZero << endl;
    cout << "Integer nonZeroInt (123) converted to bool: " << boolFromNonZero << endl;

    bool trueBool = true;
    bool falseBool = false;

    int intFromTrueBool = trueBool;        // Results in 1
    int intFromFalseBool = falseBool;      // Results in 0

    cout << "\nBoolean true converted to int: " << intFromTrueBool << endl;
    cout << "Boolean false converted to int: " << intFromFalseBool << endl;

    // Potential Pitfall: `if` Statements with Assignment Instead of Comparison
    int value = 0;
    if (value = 1) {    // Mistakenly assigning `1` to `value`, which makes condition always true
        cout << "\nAssignment instead of comparison in if statement. Condition is true.\n";
    }
    
    // 3. Explicit Conversions (Casting)
    /*
        Explicit conversions, or casting, allow us to control type conversions. 
        C++ provides four casting operators:
        - `static_cast`: Used for safe conversions between compatible types (e.g., `int` to `double`).
        - `reinterpret_cast`: Converts pointers or references to any other pointer type. Used for low-level casts.
        - `const_cast`: Adds or removes `const` qualifier from a variable.
        - `dynamic_cast`: Used for safe downcasting in class hierarchies (requires inheritance).

        Here, we’ll focus on `static_cast` and `reinterpret_cast`, as `dynamic_cast` requires classes.
    */

    double preciseValue = 3.14159;
    int approxValue = static_cast<int>(preciseValue);  // Explicitly truncating `double` to `int`

    cout << "\nOriginal double (preciseValue): " << preciseValue << endl;
    cout << "Explicitly converted to int (approxValue): " << approxValue << endl;

    // Explanation:
    // `static_cast` performs a safe conversion, allowing us to control the outcome precisely.
    // Here, `static_cast` truncates the fractional part of `preciseValue`.

    // `reinterpret_cast`
    /*
        `reinterpret_cast` allows converting any pointer to any other pointer type.
        This is a low-level cast, and should be used with extreme caution as it bypasses type safety.
    */

    int num = 65;
    char* charPtr = reinterpret_cast<char*>(&num);  // Reinterpret `int` as `char*`

    cout << "\nOriginal integer (num): " << num << endl;
    cout << "Reinterpreted as char pointer (charPtr): " << *charPtr << " (ASCII for 65 is 'A')\n";

    // Explanation:
    // `reinterpret_cast` reinterprets the `int` variable's memory as `char*`, printing the ASCII character for 65.
    // This is advanced usage, and can easily lead to undefined behavior if used incorrectly.

    // `const_cast`
    /*
        `const_cast` is used to add or remove the `const` qualifier from variables. 
        This can be useful, but modifying a `const` variable results in undefined behavior.
    */

    const int constValue = 10;
    int* nonConstPtr = const_cast<int*>(&constValue); // Remove constness

    *nonConstPtr = 20; // Dangerous! Undefined behavior as `constValue` was declared `const`

    cout << "\nOriginal const int (constValue): " << constValue << endl;
    cout << "After const_cast and modification (constValue): " << *nonConstPtr << " (Undefined Behavior)\n";

    // Explanation:
    // `const_cast` allows modifying `constValue` indirectly, but this is usually unsafe and undefined behavior.

    // 4. Common Pitfalls and Best Practices
    /*
        - Implicit Conversions: Avoid relying on implicit conversions, as they can lead to unexpected results 
          (e.g., data loss when converting `double` to `int`).
        - Explicit Conversions: Use `static_cast` when a controlled conversion is needed, especially for numeric types.
        - Boolean Conversions: Always verify `if` conditions to avoid accidental assignments.
        - Avoid `const_cast` and `reinterpret_cast` unless absolutely necessary, as they bypass type safety.

        Summary:
        - Automatic conversions are convenient but can lead to loss of precision or data.
        - `static_cast` is the preferred method for type-safe explicit conversions.
        - `const_cast` should be used with caution, as it removes the `const` protection.
        - `reinterpret_cast` is low-level and potentially unsafe; use only when necessary.
    */

    return 0;
}