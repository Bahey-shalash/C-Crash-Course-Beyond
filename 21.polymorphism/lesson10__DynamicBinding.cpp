/* ==========================================================================
Final Lesson B: Dynamic Binding (Virtual Functions)

In this example, the description() method is declared as virtual in the base class.
Thus, when affichageDesc() is given a reference to a Cercle object, the derived
version is invoked, demonstrating dynamic binding.
========================================================================== */
// FinalLessonB_DynamicBinding.cpp

#include <iostream>
using namespace std;

class Forme {
public:
    // Declare description() as virtual for dynamic binding.
    virtual void description() const;
};

void Forme::description() const {
    cout << "Ceci est une forme !" << endl;
}

class Cercle : public Forme {
public:
    // This overrides the virtual method.
    void description() const override;
};

void Cercle::description() const {
    cout << "Ceci est un cercle !" << endl;
}

void affichageDesc(Forme& f) {
    // With virtual functions, the call is resolved at run-time based on the actual type of f.
    f.description();
}

int main() {
    Forme f;
    Cercle c;
    affichageDesc(f);  // Calls Forme::description() → "Ceci est une forme !"
    affichageDesc(c);  // Calls Cercle::description() → "Ceci est un cercle !"
    return 0;
}