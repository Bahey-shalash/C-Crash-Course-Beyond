/* ### File: arrow_operator_with_structs.cpp ###
   ### Course: Understanding the `->` Operator with Structs in C++

   **Overview**
   In C++, the `->` operator is used to access members of a structure or class 
   through a pointer. It is a shortcut for dereferencing a pointer and accessing 
   a member variable or function.

   **Key Concepts**
   - Difference between `.` (dot) and `->` (arrow) operators
   - Using `->` to access struct members through pointers
   - Practical examples of `->` in functions and dynamic memory allocation
*/

#include <iostream>
#include <string>

// Define a struct to represent a Book
struct Book {
    std::string title;
    std::string author;
    int year;

    // A member function to display book info
    void display() const {
        std::cout << "Title: " << title << '\n';
        std::cout << "Author: " << author << '\n';
        std::cout << "Year: " << year << '\n';
    }
};

int main() {
    // Creating an instance of `Book`
    Book myBook = {"1984", "George Orwell", 1949};

    // Accessing members using the dot operator (.)
    std::cout << "Using dot operator:\n";
    std::cout << "Title: " << myBook.title << '\n';
    std::cout << "Author: " << myBook.author << '\n';

    // Creating a pointer to `Book`
    Book* bookPtr = &myBook;

    // Accessing members using the arrow operator (->) through the pointer
    std::cout << "\nUsing arrow operator:\n";
    std::cout << "Title: " << bookPtr->title << '\n';
    std::cout << "Author: " << bookPtr->author << '\n';

    // Calling a member function using the arrow operator
    std::cout << "\nDisplaying book info using display() method:\n";
    bookPtr->display();

    // Dynamic allocation of a `Book` struct
    Book* dynamicBook = new Book{"The Catcher in the Rye", "J.D. Salinger", 1951};

    // Accessing members of the dynamically allocated struct
    std::cout << "\nDynamically allocated book info:\n";
    dynamicBook->display();

    // Freeing dynamically allocated memory
    delete dynamicBook;

    return 0;
}

/*
Expected Output:
Using dot operator:
Title: 1984
Author: George Orwell

Using arrow operator:
Title: 1984
Author: George Orwell

Displaying book info using display() method:
Title: 1984
Author: George Orwell
Year: 1949

Dynamically allocated book info:
Title: The Catcher in the Rye
Author: J.D. Salinger
Year: 1951
*/