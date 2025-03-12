/* ### File: basic_input_output_with_redirection.cpp ###
   ### Course: Basic User Input and Output in C++ with Terminal Redirection ###

   This program demonstrates basic user input and output in C++. It also
   includes instructions on using terminal redirection to read input from a
   file and write output to a file, which is useful for testing and automation.

   **Terminal Redirection Syntax**
   In the terminal, you can redirect input and output to/from files:
    ./basic_input_output_with_redirection < input.txt > output.txt
    •	< input.txt redirects the contents of input.txt as input to the program.
	•	> output.txt redirects the program’s output to output.txt.
*/

#include <iostream>
#include <string>

int main() {
    // Declare variables to store user input
    int age;
    double salary;
    std::string name;

    // Prompt the user for their age
    std::cout << "Enter your age: ";
    std::cin >> age;

    // Check if the age input was valid
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid integer for age." << std::endl;
        std::cin.clear();              // Clear the error state
        std::cin.ignore(100, '\n');     // Ignore remaining characters in the input buffer
    } else {
        std::cout << "You entered: " << age << " years old." << std::endl;
    }

    // Clear the input buffer and prompt for the user's name
    std::cout << "Enter your name: ";
    std::cin.ignore();                  // Consume any leftover newline character
    std::getline(std::cin, name);       // Read an entire line of text

    std::cout << "Hello, " << name << "!" << std::endl;

    // Prompt the user for their salary
    std::cout << "Enter your salary: ";
    std::cin >> salary;

    // Check if the salary input was valid
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid number for salary." << std::endl;
        std::cin.clear();               // Clear the error state
        std::cin.ignore(100, '\n');     // Ignore remaining characters in the input buffer
    } else {
        std::cout << "Your salary is: $" << salary << std::endl;
    }

    return 0;
}

/*
Example of Running the Program with Input and Output Redirection:
----------------------------------------------------------------
1. Create an input file (input.txt) with the following contents:
   25
   Alice Johnson
   50000

2. Run the program with redirection:
   ./basic_input_output_with_redirection < input.txt > output.txt

3. The program will take input from input.txt and write output to output.txt.

Expected Contents of output.txt:
--------------------------------
Enter your age: You entered: 25 years old.
Enter your name: Hello, Alice Johnson!
Enter your salary: Your salary is: $50000
*/