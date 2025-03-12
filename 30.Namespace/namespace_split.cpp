/*
File: namespace_split.cpp
Description:
  This file demonstrates how to use a namespace that has been split across multiple files.
  It includes the header (mynamespace.h) and calls the function defined in mynamespace.cpp.
*/

#include "mynamespace.h"

int main() {
    MyNamespace::sayHello();
    return 0;
}


/* 
g++ -std=c++17 namespace_split.cpp mynamespace.cpp -o namespace_split
./namespace_split
*/