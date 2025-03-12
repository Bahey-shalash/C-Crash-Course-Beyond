# C++ Crash Course & Beyond - The Goated Collection

Welcome to **C++ Crash Course & Beyond - The Goated Collection**.  
I, **Bahey Shalash**, created this repository as a personal project to consolidate my learning and to provide a resource for future students who wish to learn C++.

This collection is based on the courses I took as an EPFL student during the first year of my bachelor's program:
- [Programmation Orientée Projet - COM-112-A](https://edu.epfl.ch/studyplan/fr/propedeutique/genie-electrique-et-electronique/coursebook/programmation-orientee-projet-COM-112-A)
- [Information, Calcul, Communication - CS-119-C](https://edu.epfl.ch/studyplan/fr/propedeutique/genie-electrique-et-electronique/coursebook/information-calcul-communication-CS-119-C)

After these courses, I decided to expand on what I learned by adding extra topics and examples beyond the classroom material. This repository is designed for me—and for any future student—who wants to delve deep into C++.

---

## Table of Contents

- [Introduction](#introduction)
- [Repository Structure](#repository-structure)
- [Getting Started](#getting-started)
- [Usage & Examples](#usage--examples)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

---

## Introduction

C++ is a powerful programming language with a rich set of features and best practices. This repository is a curated collection of code examples, notes, and insights covering everything from the fundamentals (variables, control structures, functions, pointers) to advanced topics (exception handling, smart pointers, modern C++ enhancements, and more).

Whether you're just starting out or looking to polish your skills, you'll find valuable resources here to guide you through your C++ journey.

---

## Repository Structure

The repository is organized by topic for easy navigation. Here is an overview of the folder structure:

```
Cplusplus-Learning-Collection/
├── 0. Resources/                  # References and non-copyrighted materials
├── 1.Variables/                  # Basic data types and initialization techniques
├── 2.instruction conditionnelle/ # Control structures and loops
├── 3.functions/                  # Function basics, recursion, lambdas, etc.
├── 4.vector_array/               # Arrays, vectors, and container usage
├── 5.strings/                    # Working with strings
├── 6.enum/                       # Enumerations and enum classes
├── 7.typedef/                    # Typedefs and type aliases
├── 8.structs/                    # Structures and memory alignment
├── 9.pointers/                   # Pointers, dynamic memory, and examples
├── 10.input_output/              # File I/O, console I/O, command-line arguments
├── 11.Exceptions/                # Exception handling and RAII
├── 12.performance/               # Performance optimization and best practices
├── 13.smart pointers/            # Smart pointers: unique, shared, and more
├── 14.modular decomposition/     # Build systems, Makefiles, and CMake
├── 15.Introduction to OOP/       # OOP basics and advanced concepts
├── 16.constructor_destructor/    # Constructors, destructors, and move semantics
├── 17.Preprocessor/              # Preprocessor directives and macros
├── 18.static/                    # Static members and usage scenarios
├── 19.overload/                  # Function and operator overloading
├── 20.Inheritance/               # Inheritance fundamentals
├── 21.polymorphism/              # Polymorphism and virtual functions
├── 22.multiple_inheritance/      # Multiple inheritance examples
├── 23.Templates and Generic Programming/  # Templates and modern generic programming
├── 24.Exception Handling and Exception Safety/  # Advanced exception handling topics
├── 25.Memory Optimization and Performance/  # Memory layout and performance tips
├── 26.STL and Modern C++ Enhancements/  # STL containers, algorithms, and new features
├── 27.Concurrency and Multithreading/ (Optional)  # Multithreading and async programming
├── 28.Compiler and Low-Level Optimizations/  # Inlining, constexpr, and profiling
├── 29.other_data_structures/     # Maps, sets, tuples, and more
├── 30.Namespace/                 # Namespace usage and best practices
└── 31.SOLID/                    # SOLID principles in C++ design
```

Each folder contains standalone, well-commented code examples that you can compile and run individually.

---

## Getting Started

To begin using this repository, follow these steps:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/Bahey-shalash/Cpp-Crash-Course-Beyond.git
   cd Cplusplus-Learning-Collection
   ```

2. **Compile an Example:**

   You can use **any standard C++ compiler** (such as `g++` or `clang++`) to compile the examples.  
   If a minimum C++ version is required for a specific example, it will be mentioned in the code comments.

   For instance, to compile the introduction to exceptions example:

   ```bash
   clang++ -std=c++23 11/1_IntroductionToExceptions.cpp -o intro_exceptions
   ./intro_exceptions
   ```
   
   If you're using g++, you can run:

   ```bash
   g++ -std=c++23 11/1_IntroductionToExceptions.cpp -o intro_exceptions
   ./intro_exceptions
   ```
---

## Usage & Examples

Each file is self-contained with detailed comments to help you understand the concepts and best practices. Feel free to:

- **Run the examples:** Experiment with the code to see how changes affect the outcome.
- **Learn from the comments:** The in-code documentation explains the techniques and principles behind the code.
- **Expand on the examples:** Modify the code or add your own examples to further explore C++.

---

## Contributing

Contributions are welcome! If you have new examples, improvements, or bug fixes, please open a pull request. For significant changes, consider opening an issue first to discuss your ideas.

---

## License

This repository is licensed under the MIT License. See the LICENSE file for details.

---

## Acknowledgements

**EPFL Courses:**  
This collection is heavily inspired by the courses I took at EPFL in my first year:
- [Programmation Orientée Projet - COM-112-A](https://edu.epfl.ch/studyplan/fr/propedeutique/genie-electrique-et-electronique/coursebook/programmation-orientee-projet-COM-112-A)
- [Information, Calcul, Communication - CS-119-C](https://edu.epfl.ch/studyplan/fr/propedeutique/genie-electrique-et-electronique/coursebook/information-calcul-communication-CS-119-C)

**Inspiration:**  
Thanks to the many C++ resources and the vibrant programming community that have helped shape my understanding over the years.

**For Future Students:**  
I created this repository for myself and for any future student who wishes to learn C++. I hope it serves as a helpful guide and inspires you to explore the depths of C++ programming.

---

Happy coding and learning,  
**Bahey Shalash**
