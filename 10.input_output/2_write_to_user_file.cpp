/*
    ==========================================================
    EXERCISE: WRITING TO A USER-SPECIFIED FILE
    ==========================================================
    Goal: Modify the program to prompt the user for a filename 
          and write data to the specified file.

    Key Features:
    - Use `std::cin` to take the filename from the user.
    - Write user-specified content to the file.
    - Handle file opening errors gracefully.

    Practical Application:
    - Customizable file storage for user data.
    - Useful for tools requiring user-defined filenames.

    New Concepts:
    - Combining `std::cin` with file handling.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename; // Variable to store the filename

    // Prompt the user for a filename
    cout << "Enter the name of the file to create or write to: ";
    getline(cin, filename); // Read the filename from the user

    // ==========================================================
    // 1. Opening the User-Specified File for Writing
    // ==========================================================
    /*
        Open the file using `std::ofstream`. If the file does not exist, 
        it will be created. If it exists, its contents will be overwritten.
    */
    ofstream userFile(filename);
    if (!userFile) {
        cerr << "Error: Could not open the file '" << filename << "' for writing." << endl;
        return 1; // Exit the program if the file could not be opened
    }

    // Prompt the user for content to write to the file
    cout << "Enter the content to write to '" << filename << "':" << endl;
    string content;
    getline(cin, content); // Read the content from the user

    // Write the content to the file
    userFile << content << endl;

    // Close the file
    userFile.close();
    cout << "Data written to '" << filename << "' successfully." << endl;

    // ==========================================================
    // 2. Reading the File to Verify Contents
    // ==========================================================
    /*
        Re-open the file in `std::ifstream` mode to verify 
        that the content was written correctly.
    */
    ifstream verifyFile(filename);
    if (!verifyFile) {
        cerr << "Error: Could not open the file '" << filename << "' for reading." << endl;
        return 1;
    }

    cout << "Contents of '" << filename << "':" << endl;
    string line;
    while (getline(verifyFile, line)) {
        cout << line << endl; // Print each line of the file
    }

    // Close the file after reading
    verifyFile.close();

    return 0; // End of the program
}