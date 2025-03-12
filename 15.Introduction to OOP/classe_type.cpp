// File Name: NomClasse.hpp
// Description: Example of a typical C++ class structure (translated & improved)

#ifndef __NOMCLASSE_HPP__  
#define __NOMCLASSE_HPP__

/*
  Naming Convention for Include Guards:
  -------------------------------------
  1. Use a unique identifier in uppercase.
  2. Many choose a pattern like: PROJECTNAME_FILENAME_HPP
  3. The double underscores (__NOMCLASSE_HPP__) ensure uniqueness,
     but note that names with double underscores are technically
     reserved for the compiler implementation in the C++ standard.
     Despite that, it's still common to see them used in practice.
  4. Just be consistent throughout your codebase.
*/

#include <iostream>

//============================
// Declaration of the Class
//============================
class NomClasse
{
    //=== Declaration of "friends": classes, methods, and functions
    friend std::ostream& operator<<(std::ostream& out, const NomClasse& arg);
    friend std::istream& operator>>(std::istream& in, NomClasse& arg);
    // Other "friends" can go here
    // ...

    //=== Data Members / Class Attributes
private:
    // Private attributes/data members (inaccessible from outside,
    // but accessible to friends)
    int* data_; // Example pointer attribute (heap allocation)

protected:
    // Protected attributes/data members (accessible to derived classes & friends)

public:
    // Public attributes/data members (accessible to everyone)

    //=== Member Functions / Methods
private:
    // Private methods

protected:
    // Protected methods

public:
    //=== Constructors
    // Used to initialize the Object
    NomClasse();                           // Default Constructor
    NomClasse(int initialValue);           // Parameterized Constructor
    NomClasse(const NomClasse& arg);       // Copy Constructor

    //=== Destructor (only one)
    // Marked 'virtual' in case of inheritance
    virtual ~NomClasse();

    // Overload of the "=" operator
    // (especially if data members are pointers)
    NomClasse& operator=(const NomClasse& arg);

    // Other public methods
    void setData(int value);
    int getData() const;

    // Example of a polymorphic method
    virtual void doSomething();
};

//============================
// Constructors
// Used to initialize the Object
//============================

// Default Constructor
NomClasse::NomClasse()
    : data_(nullptr)  // Initialize pointer to null
{
    // Default constructor body
}

// Parameterized Constructor
NomClasse::NomClasse(int initialValue)
    : data_(new int(initialValue))  // Allocate an int on the heap
{
    // Constructor body
}

// Copy Constructor (deep copy)
NomClasse::NomClasse(const NomClasse& arg)
    : data_(nullptr)
{
    if (arg.data_ != nullptr)
    {
        data_ = new int(*(arg.data_));
    }
}

//============================
// Destructor
// Used to clean up the object
//============================
NomClasse::~NomClasse()
{
    delete data_;   // Release allocated memory
    data_ = nullptr;
}

//=========================================
// Overload "=" Operator (Assignment)
// Important if you have pointer members
//=========================================
NomClasse& NomClasse::operator=(const NomClasse& arg)
{
    // Guard against self-assignment
    if (this != &arg)
    {
        // Release existing resource
        delete data_;
        data_ = nullptr;

        // Allocate and copy
        if (arg.data_ != nullptr)
        {
            data_ = new int(*(arg.data_));
        }
    }
    return *this;
}

//============================
// Other Public Methods
//============================
void NomClasse::setData(int value)
{
    if (data_ == nullptr)
    {
        data_ = new int(value);
    }
    else
    {
        *data_ = value;
    }
}

int NomClasse::getData() const
{
    // Return the stored value (0 if data_ is null)
    return (data_ ? *data_ : 0);
}

void NomClasse::doSomething()
{
    // Example of a virtual method that could be overridden in derived classes
    // Implementation here...
}

//============================
// Friend Operator Overloads
//============================
std::ostream& operator<<(std::ostream& out, const NomClasse& arg)
{
    if (arg.data_)
    {
        out << "NomClasse data: " << *(arg.data_);
    }
    else
    {
        out << "NomClasse data is null.";
    }
    return out;
}

std::istream& operator>>(std::istream& in, NomClasse& arg)
{
    int temp;
    in >> temp;
    arg.setData(temp);
    return in;
}

#endif // __NOMCLASSE_HPP__