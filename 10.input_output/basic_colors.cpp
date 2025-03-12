/* ### File: basic_colors.cpp ###
   ### Course 1: Basic Terminal Colors in C++ ###

   **Overview**
   Many terminals support colored output using ANSI escape codes. These codes 
   allow you to add colors to text by embedding special sequences of characters 
   in your output.

   **Key Concepts**
   - Using ANSI escape codes for basic colors (red, green, yellow, blue)
   - Resetting color after each output
   - Basic usage in `cout` statements

   **Syntax**
   `"\033[<style>;<color_code>m"` - Changes text color/style
   `"\033[0m"` - Resets color to default
*/

#include <iostream>

int main() {
    // ANSI escape codes for different colors
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string RESET   = "\033[0m"; // Resets to default color

    // Printing text with different colors
    std::cout << RED     << "This is red text." << RESET << std::endl;
    std::cout << GREEN   << "This is green text." << RESET << std::endl;
    std::cout << YELLOW  << "This is yellow text." << RESET << std::endl;
    std::cout << BLUE    << "This is blue text." << RESET << std::endl;

    return 0;
}

/*
Explanation:
1. ANSI Escape Codes:
   - The code "\033[" starts an escape sequence.
   - Color codes like `31` (red), `32` (green), etc., set the text color.

2. Resetting:
   - Always reset colors by appending `"\033[0m"` (stored in `RESET`) to avoid 
     affecting subsequent output.
*/