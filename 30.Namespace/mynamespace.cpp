/*
File: mynamespace.cpp
Description:
  This file provides the implementation of the function declared in mynamespace.h within the 
  MyNamespace namespace. Splitting code in this way improves modularity and organization.
*/

#include <iostream>
#include "mynamespace.h"

namespace MyNamespace {
    void sayHello() {
        std::cout << "Hello from MyNamespace!" << std::endl;
    }
}
