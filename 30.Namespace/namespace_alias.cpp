/*
File: namespace_alias.cpp
Description:
  This file shows how to create a namespace alias to shorten long or deeply nested namespace names.
  We define a namespace with a long name and then create an alias 'LNN' to refer to it.

When to use namespace aliases:
  - When your namespace names are lengthy or nested deeply, which can make the code harder to read.
  - To improve code clarity and reduce typing without losing the benefits of namespacing.
*/

#include <iostream>

namespace LongNamespaceName {
    void doSomething() {
        std::cout << "Doing something in a long namespace name." << std::endl;
    }
}

// Create an alias for the long namespace.
namespace LNN = LongNamespaceName;

int main() {
    LNN::doSomething();
    return 0;
}
