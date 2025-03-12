/* ==========================================================================
Lesson 2: Static vs. Dynamic Binding

In C++:
	•	Static binding (early binding):
Non-virtual functions are resolved at compile-time.
	•	Dynamic binding (late binding):
Virtual functions are resolved at run-time through a base class pointer.

This lesson shows the difference using two parallel class hierarchies.
========================================================================== */
// Lesson2_StaticVsDynamicBinding.cpp

#include <iostream>

// ----- Static Binding Example -----
class BaseStatic {
public:
    // Non-virtual function: resolved at compile-time.
    void show() {
        std::cout << "BaseStatic::show()" << std::endl;
    }
};

class DerivedStatic : public BaseStatic {
public:
    // Redefines show(), but because BaseStatic::show() is not virtual,
    // calls through a BaseStatic pointer will always call BaseStatic::show().
    void show() {
        std::cout << "DerivedStatic::show()" << std::endl;
    }
};

// ----- Dynamic Binding Example -----
class BaseDynamic {
public:
    // Virtual function: resolved at run-time.
    virtual void show() {
        std::cout << "BaseDynamic::show()" << std::endl;
    }
};

class DerivedDynamic : public BaseDynamic {
public:
    // Overrides the virtual function.
    void show() override {//override is optional but recommended for clarity
        std::cout << "DerivedDynamic::show()" << std::endl;
    }
};

int main() {
    std::cout << "Static Binding Example:" << std::endl;
    BaseStatic* staticPtr = new DerivedStatic();
    // Calls BaseStatic::show() because the function is not virtual.
    staticPtr->show();  
    delete staticPtr;
    
    std::cout << "\nDynamic Binding Example:" << std::endl;
    BaseDynamic* dynamicPtr = new DerivedDynamic();
    // Calls DerivedDynamic::show() because show() is virtual.
    dynamicPtr->show();  
    delete dynamicPtr;
    
    return 0;
}