/*
    ==========================================================
    MODULE 2: PRACTICAL USE OF COMMAND-LINE ARGUMENTS
    ==========================================================
    In this module, we explore real-world use cases:

    1. Validating the number of arguments.
    2. Using arguments as input (e.g., file names, options).
    3. Handling errors gracefully.

    Example:
    A program that requires two numbers as arguments, performs
    addition, and displays the result.

    Command:
    ./practical_command_line 5 10
*/

#include <cstdlib>  // For `atoi` (convert string to integer)
#include <iostream>
#include <string>  // For 'std::string' and 'std::stoi'

int main1(int argc, char** argv) {

    // Validate the number of arguments
    if (argc != 3) {  // Expecting program name + 2 numbers
        std::cerr << "Usage: " << argv[0] << " <number1> <number2>" << std::endl;
        return 1;  // Exit with an error code
    }

    // Convert arguments to integers
    int num1 = atoi(argv[1]);  // Convert the first argument to int
    int num2 = atoi(argv[2]);  // Convert the second argument to int
    /* static_cast cannot directly parse text strings into integers. */

    // Safer alternative to atoi
    int num3 = std::stoi(argv[1]);
    int num4 = std::stoi(argv[2]);

    // Perform addition and display the result
    std::cout << "Number 1: " << num1 << std::endl;
    std::cout << "Number 2: " << num2 << std::endl;
    std::cout << "Sum: " << num1 + num2 << std::endl;

    std::cout << "=====================================" << std::endl;
    std::cout << "Number 3: " << num3 << std::endl;
    std::cout << "Number 4: " << num4 << std::endl;
    std::cout << "Sum: " << num3 + num4 << std::endl;

    return 0;  // Successful execution
}
