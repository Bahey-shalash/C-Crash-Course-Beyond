/*
File: namespace_using.cpp
Description:
  This file demonstrates two ways to avoid repeatedly writing fully qualified names:
    1. Using a "using declaration" to bring a specific name into the current scope.
    2. (Commented out) Using a "using directive" to bring all names from a namespace into the scope.
  
Important Note:
  - Using declarations (e.g., using Utils::greet;) are safer than using directives because they
    limit the imported names and reduce the chance of naming conflicts.

When to use:
  - Use using declarations sparingly in source files (avoid them in header files).
  - Avoid using directives at the global scope in headers to prevent polluting the global namespace.
*/

#include <iostream>

namespace Utils {
    void greet() {
        std::cout << "Hello from Utils!" << std::endl;
    }
}

int main() {
    // Option 1: Use the fully qualified name.
    Utils::greet();
    
    // Option 2: Bring in one specific function (safer approach).
    using Utils::greet;
    greet();
    
    // Option 3 (use with caution): Bring in everything from Utils.
    // using namespace Utils;
    // greet();  // This would work but might pollute the global namespace.
    
    return 0;
}
