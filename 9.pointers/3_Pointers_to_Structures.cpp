/*
Class 3: Pointers to Structures
-------------------------------
In this class, we will explore:
1. Creating pointers to structures.
2. Accessing structure members using pointers.
3. Dynamic allocation of structures.
4. Practical examples of using pointers with structures.

Key concepts:
- Structures (structs) group related data into a single unit.
- Pointers to structs enable dynamic memory allocation and efficient data manipulation.
- Arrow operator (`->`) is used to access members of a structure through a pointer.

*/

#include <iostream>
#include <cstring> // For strcpy and strlen
using namespace std;

// Step 1: Define a Structure
struct Student {
    int id;
    char name[50];
    float grade;
};

int main() {
    // Step 2: Basic Pointer to Structure
    Student s1 = {1, "Alice", 95.5}; // Initialize a Student structure
    Student* ptr = &s1; // Pointer to the structure

    // Accessing structure members using pointer
    cout << "Accessing members using pointer:" << endl;
    cout << "ID: " << ptr->id << endl;       // Using the arrow operator
    cout << "Name: " << ptr->name << endl;   // Accessing name
    cout << "Grade: " << ptr->grade << endl; // Accessing grade

    // Step 3: Dynamic Allocation of Structure
    Student* s2 = new Student; // Allocate memory dynamically
    s2->id = 2;
    strcpy(s2->name, "Bob"); // Copy string into char array
    s2->grade = 89.4;

    cout << "\nDynamically allocated student:" << endl;
    cout << "ID: " << s2->id << endl;
    cout << "Name: " << s2->name << endl;
    cout << "Grade: " << s2->grade << endl;

    // Step 4: Array of Structures and Pointers
    const int size = 2;
    Student* students = new Student[size]; // Array of structures

    // Assign values dynamically
    students[0].id = 3;
    strcpy(students[0].name, "Charlie");
    students[0].grade = 72.3;

    students[1].id = 4;
    strcpy(students[1].name, "Diana");
    students[1].grade = 85.9;

    cout << "\nArray of dynamically allocated students:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Grade: " << students[i].grade << endl;
    }

    // Step 5: Cleaning Up
    delete s2; // Free single dynamically allocated structure
    delete[] students; // Free dynamically allocated array of structures

    return 0;
}