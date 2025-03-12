/* ==========================================================================
Final Lesson: Heterogeneous Collections Using Polymorphism

This lesson demonstrates how to create a collection of polymorphic objects.
We allocate objects of different derived types (Cercle, Triangle) and store their
addresses in a vector of pointers to the base class (Forme). We then iterate over
the vector to invoke the virtual method dessin(), and finally, we free the allocated memory.

In this example:
    1. The base class Forme defines a virtual function dessin().
    2. Derived classes Cercle and Triangle override dessin() to provide their specific behavior.
    3. In main(), objects are allocated dynamically and stored in a vector.
    4. The vector is iterated, and f->dessin() is called on each object. Because of dynamic
       binding, the correct overridden version is invoked.
    5. Finally, the allocated memory is released by deleting each pointer.
========================================================================== */

#include <iostream>
#include <vector>
using namespace std;

// Base class with a virtual method.
class Forme {
public:
    // Virtual method that will be overridden by derived classes.
    virtual void dessin() const {
        cout << "Dessin de forme générique." << endl;
    }
    
    // Virtual destructor ensures that derived class destructors are called.
    virtual ~Forme() {}
};

// Derived class: Cercle
class Cercle : public Forme {
public:
    // Override the virtual method to provide a specific implementation.
    void dessin() const override {
        cout << "Dessin d'un cercle." << endl;
    }
};

// Derived class: Triangle
class Triangle : public Forme {
public:
    // Override the virtual method to provide a specific implementation.
    void dessin() const override {
        cout << "Dessin d'un triangle." << endl;
    }
};

int main() {
    // Create a vector to hold pointers to Forme.
    vector<Forme*> tab;
    
    // Dynamically allocate derived objects and add their addresses to the vector.
    tab.push_back(new Cercle);    // Adds a Cercle
    tab.push_back(new Triangle);    // Adds a Triangle
    // You can add more derived types if needed.
    
    // Iterate over the vector and call the virtual method dessin() on each object.
    // Due to dynamic binding, the appropriate derived version is invoked.
    for (const auto& f : tab) {
        f->dessin();
    }
    
    // Clean up: iterate over the vector and delete each dynamically allocated object.
    for (auto f : tab) {
        delete f;
    }
    
    return 0;
}

/* Explanation:

In this lesson, we define a base class Forme that declares a virtual function dessin().
Two derived classes (Cercle and Triangle) override this function to provide their own implementations.

In the main() function, we:
    1. Dynamically allocate objects of derived classes (Cercle and Triangle).
    2. Store their addresses in a std::vector<Forme*>.
    3. Iterate over the vector and call the virtual function dessin() on each object.
       Because of dynamic binding, the appropriate overridden function is called
       based on the actual type of the object (Cercle or Triangle).
    4. Finally, we free the allocated memory by deleting each pointer in the vector.

This approach allows you to manage different types of objects using a single collection
while relying on polymorphism for the correct behavior at runtime.
*/