/* ### Course 4: Converting Data to `std::string` ###

   This course explains how to convert other data types into strings using 
   `std::to_string`, which can be useful for creating complex text outputs.
*/

#include <iostream>
#include <string>

int main() {
    int year = 2024;
    double gpa = 3.9;

    // Convert integers and floating points to `std::string`
    std::string yearStr = std::to_string(year);
    std::string gpaStr = std::to_string(gpa);

    // Create a formatted string
    std::string info = "Year: " + yearStr + ", GPA: " + gpaStr;
    std::cout << info << '\n';

    return 0;
}