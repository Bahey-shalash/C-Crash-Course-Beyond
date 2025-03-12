/*
File: namespace_nested.cpp
Description:
  This file illustrates nested namespaces. Here, we have an outer namespace called Company and 
  a nested namespace called Department. The function printDepartment() resides in the nested namespace,
  and main() calls it using the fully qualified name.

When to use nested namespaces:
  - When you need to further organize your code hierarchically (e.g., a company with multiple departments).
*/

#include <iostream>

namespace Company {
    namespace Department {
        void printDepartment() {
            std::cout << "Department: Research and Development" << std::endl;
        }
    }
}

int main() {
    // Access the nested namespace function using the full qualified name.
    Company::Department::printDepartment();
    return 0;
}
