/*
    ==========================================================
    MODULE 2: READING FROM A FILE
    ==========================================================
    Reading data from a file is essential for processing 
    stored information in a program. This module covers:
    
    1. Using `std::ifstream` to read files.
    2. Reading line-by-line using `getline`.
    3. Reading specific formats (e.g., numbers, words).
    4. Handling file reading errors.

    Practical Applications:
    - Reading configuration files.
    - Processing large datasets line by line.
    - Extracting structured data for computation.

    Key Concepts:
    - `std::getline`: Reads a full line from a file.
    - `std::ifstream::eof()`: Checks if the end of the file is reached.
    - Token-based reading using `>>`.

    Let's implement these techniques step by step.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // For string streams
using namespace std;

int main() {
    string filename = "sample_data.txt"; // Name of the file to read

    // ==========================================================
    // 1. Reading a File Line by Line
    // ==========================================================
    /*
        Using `std::getline`, we can read each line of the file. 
        This method is particularly useful when working with files 
        that store data in a line-oriented format.
    */
    ifstream inputFile(filename); // Open the file for reading
    if (!inputFile) {
        cerr << "Error: Could not open the file '" << filename << "' for reading." << endl;
        return 1;
    }

    cout << "Contents of the file (line by line):" << endl;
    string line;
    while (getline(inputFile, line)) { // Read line by line
        cout << line << endl; // Display the line
    }

    inputFile.close(); // Close the file
    cout << endl;

    // ==========================================================
    // 2. Reading Data Word by Word
    // ==========================================================
    /*
        Token-based reading using `>>` allows us to extract words 
        or values from a file, separated by whitespace.
    */
    inputFile.open(filename); // Re-open the file for reading
    if (!inputFile) {
        cerr << "Error: Could not open the file '" << filename << "' for reading." << endl;
        return 1;
    }

    cout << "Reading data word by word:" << endl;
    string word;
    while (inputFile >> word) { // Extract words from the file
        cout << word << " "; // Print each word
    }
    cout << endl;

    inputFile.close(); // Close the file
    cout << endl;

    // ==========================================================
    // 3. Reading and Parsing Numbers
    // ==========================================================
    /*
        Structured data often contains numbers that need to 
        be processed. Using `std::istringstream`, we can parse 
        lines containing multiple numbers.
    */
    inputFile.open(filename); // Re-open the file for reading
    if (!inputFile) {
        cerr << "Error: Could not open the file '" << filename << "' for reading." << endl;
        return 1;
    }

    cout << "Extracting numbers from the file:" << endl;
    while (getline(inputFile, line)) { // Read each line
        istringstream iss(line); // Create a string stream
        int number;
        while (iss >> number) { // Extract numbers from the line
            cout << number << " "; // Print each number
        }
    }
    cout << endl;

    inputFile.close(); // Close the file
    cout << endl;

    // ==========================================================
    // 4. Handling Errors While Reading
    // ==========================================================
    /*
        Always check the state of the file stream while reading 
        to detect and handle any errors.
    */
    inputFile.open("nonexistent.txt"); // Attempt to open a nonexistent file
    if (!inputFile) {
        cerr << "Error: Could not open the file 'nonexistent.txt'." << endl;
    } else {
        // If the file opens successfully (unexpectedly in this case)
        cout << "File 'nonexistent.txt' opened unexpectedly." << endl;
        inputFile.close();
    }

    return 0; // End of the program
}