/* ==========================================================================
Lesson 8: Static Binding vs. Dynamic Binding with Function Resolution

This lesson shows how the resolution of member function calls differs
depending on whether a function is declared as virtual.

1. **Static Binding (Early Binding):**
   - Occurs when a function is not declared as virtual.
   - The function call is resolved at compile-time based on the declared type.
   - Example: Even if a derived object is passed to a function expecting a base class reference,
     the base class function is called.

2. **Dynamic Binding (Late Binding):**
   - Occurs when a function is declared as virtual.
   - The function call is resolved at run-time (using the virtual table) based on the actual object type.
   - Example: When a derived object is passed via a base class reference, the derived function is called.

Below are two sets of classes that illustrate these concepts.

Part A demonstrates static binding (non-virtual functions):
   - Even if a `Cercle` object is passed, the base class (`Forme`) version of `description()`
     is called.

Part B demonstrates dynamic binding (virtual functions):
   - With `virtual` in the base class, when a `Cercle` object is passed, the derived class version
     of `description()` is invoked.

========================================================================== */

#include <iostream>
using namespace std;

// ====================
// Part A: Static Binding
// (No virtual keyword)
// ====================

// Base class without virtual function.
class Forme_Static {
public:
    // Non-virtual member function.
    void description() const;
};

void Forme_Static::description() const {
    cout << "Ceci est une forme !" << endl;
}

// Derived class that redefines description().
// This does NOT override Forme_Static::description() in a polymorphic way,
// it simply hides it.
class Cercle_Static : public Forme_Static {
public:
    void description() const;  // Hides the base class function.
};

void Cercle_Static::description() const {
    cout << "Ceci est un cercle !" << endl;
}

// Function that takes a reference to Forme_Static.
void affichageDesc_Static(Forme_Static& f) {
    // Since description() is non-virtual, the call is resolved at compile-time
    // based on the static type of f (which is Forme_Static), even if f actually
    // refers to a Cercle_Static object.
    f.description();
}

// ====================
// Part B: Dynamic Binding
// (Using virtual functions)
// ====================

// Base class with a virtual function.
class Forme_Virtual {
public:
    // Virtual member function for dynamic binding.
    virtual void description() const;
};

void Forme_Virtual::description() const {
    cout << "Ceci est une forme !" << endl;
}

// Derived class overriding the virtual function.
class Cercle_Virtual : public Forme_Virtual {
public:
    // Override the virtual function. The 'override' keyword is optional but recommended.
    void description() const override;
};

void Cercle_Virtual::description() const {
    cout << "Ceci est un cercle !" << endl;
}

// Function that takes a reference to Forme_Virtual.
void affichageDesc_Virtual(Forme_Virtual& f) {
    // With virtual functions, this call is resolved at run-time based on the actual object type.
    f.description();
}

int main() {
    // ----- Part A: Static Binding -----
    cout << "Static Binding Example (without virtual):" << endl;
    
    // Create a Cercle_Static object.
    Cercle_Static cs;
    
    // Even though cs is actually a Cercle_Static, when passed as a Forme_Static reference,
    // the call to description() is resolved statically to Forme_Static::description().
    affichageDesc_Static(cs);  // Expected output: "Ceci est une forme !"
    
    // ----- Part B: Dynamic Binding -----
    cout << "\nDynamic Binding Example (with virtual):" << endl;
    
    // Create a Cercle_Virtual object.
    Cercle_Virtual cv;
    
    // When passed as a Forme_Virtual reference, the call to description() is resolved
    // at run-time to the actual object's function: Cercle_Virtual::description().
    affichageDesc_Virtual(cv);  // Expected output: "Ceci est un cercle !"
    
    return 0;
}