/* ==========================================================================
Lesson 5: Access Specifiers – Protected Members in Inheritance

In this lesson, we demonstrate how the “protected” access specifier works in a simple inheritance hierarchy.
Key points:
	•	Members declared as protected are accessible within the class itself and by derived classes.
	•	However, a derived class’s member function can access the protected members of another instance
only if that instance is of the same type (or derived from it).

We define three classes:
	•	Class A: declares a protected member ‘x’.
	•	Class B (derived from A): declares a protected member ‘x1’.
	•	Class C (derived from B): declares a private member ‘x2’ and a public member function ‘h’
that attempts to access protected and private members from objects of type A, B, and C.

Inside C::h:
	•	Accessing p1->x is not allowed because p1 is of type A* (and may not be part of a C subobject).
	•	Accessing p2->x1 is not allowed for the same reason (p2 is a B*).
	•	Accessing p3->x2 is allowed because p3 is of type C* (private members are accessible within member functions of the same class).
	•	Accessing p4->x is allowed because p4 is of type C* and protected members from A are accessible on C objects.
========================================================================== */
// Lesson5_ProtectedMembers.cpp

#include <iostream>

class A {
protected:
    int x;
};

class B : public A {
protected:
    int x1;
};

class C : public B {
public:
    // Member function 'h' accepts pointers to A, B, and C.
    void h(A* p1, B* p2, C* p3);
private:
    int x2;
};

void C::h(A* p1, B* p2, C* p3) {
    // Create a new object of type C.
    C* p4 = new C;
    
    // The following lines illustrate access control:
    
    // std::cin >> p1->x;
    //  ^-- ERROR: 'x' is a protected member of A.
    //         Although C is derived from A, access to protected members through an A* (or B*)
    //         that does not refer to a C object is not permitted in this context.
    
    // std::cin >> p2->x1;
    //  ^-- ERROR: 'x1' is a protected member of B. Cannot be accessed via a B* pointer here.
    
    // Allowed: p3 is of type C*, so we can access C's private member 'x2' from within a member function of C.
    std::cout << "Enter value for p3->x2 (private in C): ";
    std::cin >> p3->x2;
    
    // Allowed: p4 is of type C* and therefore its inherited protected member 'x' (from A) is accessible.
    std::cout << "Enter value for p4->x (protected in A, accessible via C*): ";
    std::cin >> p4->x;
    
    delete p4; // Clean up allocated memory.
}

int main() {
    C obj;
    A a;
    B b;
    C c;
    // Call the member function 'h' on obj.
    // (The lines that would cause compile errors are commented out in h().)
    obj.h(&a, &b, &c);
    return 0;
}