/* ==========================================================================
Final Lesson A: Static Binding (Non-Virtual Functions)

In this example, the description() method is not virtual. The function
affichageDesc() calls f.description() on a Forme&. Because binding is static,
both calls (even for a Cercle object) resolve to Forme::description().
========================================================================== */
// FinalLessonA_StaticBinding.cpp

#include <iostream>
using namespace std;

class Forme {
public:
    // Here, description() is public so that affichageDesc() can call it.
    void description() const;
};

void Forme::description() const {
    cout << "Ceci est une forme !" << endl;
}

class Cercle : public Forme {
public:
    // This method hides Forme::description() rather than overriding it polymorphically.
    void description() const;
};

void Cercle::description() const {
    cout << "Ceci est un cercle !" << endl;
}

void affichageDesc(Forme& f) {
    // Since description() is non-virtual, the call is resolved based on the static type.
    f.description();
}

int main() {
    Forme f;
    Cercle c;
    affichageDesc(f);  // Calls Forme::description() → "Ceci est une forme !"
    affichageDesc(c);  // Even though c is a Cercle, static binding calls Forme::description()
    return 0;
}
/* 
output:
Ceci est une forme !
Ceci est une forme !
 */