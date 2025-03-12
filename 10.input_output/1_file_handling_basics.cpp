/*
    ==========================================================
    MODULE 1: BASICS OF FILE HANDLING
    ==========================================================
    File handling is a crucial part of many software systems. 
    It allows programs to persist data between runs by reading 
    from and writing to external files on disk.

    In C++, file handling is facilitated by the `<fstream>` library. 
    This module covers:
    1. Introduction to file streams
    2. Opening and closing files
    3. Error handling in file operations

    Key Concepts:
    - `std::ifstream` (input file stream): Used for reading from files.
    - `std::ofstream` (output file stream): Used for writing to files.
    - `std::fstream` (file stream): Used for both reading and writing.

    Practical Applications:
    - Managing user data (e.g., saving user preferences).
    - Reading configuration files for system settings.
    - Storing logs for debugging and auditing purposes.

    Let's get started with basic operations in file handling.
*/

#include <iostream>
#include <fstream> // Required for file handling
#include <string>  // Required for using strings
using namespace std;

int main() {
    // ==========================================================
    // 1. Opening a File for Writing
    // ==========================================================
    /*
        To write data to a file, we use `std::ofstream`.
        If the file does not exist, it will be created. 
        If it exists, its contents will be overwritten.
    */

    ofstream outputFile("example.txt"); // Open a file for writing
    if (!outputFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1; // Exit the program if file opening fails
    }

    // Writing some data to the file
    outputFile << "Hello, World!" << endl;
    outputFile << "This is an example of file writing in C++." << endl;

    // Always close the file after use
    outputFile.close();
    cout << "Data written to 'example.txt' successfully." << endl;

    // ==========================================================
    // 2. Opening a File for Reading
    // ==========================================================
    /*
        To read data from a file, we use `std::ifstream`.
        If the file does not exist, it cannot be opened, 
        and we need to handle this case.
    */

    ifstream inputFile("example.txt"); // Open the file for reading
    if (!inputFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    // Reading data line by line
    string line;
    cout << "Contents of 'example.txt':" << endl;
    while (getline(inputFile, line)) { // `getline` reads one line at a time
        cout << line << endl; // Print each line to the console
    }

    // Close the file after use
    inputFile.close();

    // ==========================================================
    // 3. Error Handling in File Operations
    // ==========================================================
    /*
        It is important to check if a file operation was successful.
        In addition to checking whether the file stream was opened, 
        we can also check the state of the stream during operations.
    */

    ifstream nonexistentFile("nonexistent.txt");
    if (!nonexistentFile) {
        cerr << "Error: File 'nonexistent.txt' does not exist." << endl;
        // Stream remains in a failed state until cleared
        nonexistentFile.clear(); 
    }

    return 0; // End of the program
}