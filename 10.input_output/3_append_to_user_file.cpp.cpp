/*
    ==========================================================
    EXERCISE: APPENDING DATA TO A USER-SPECIFIED FILE
    ==========================================================
    Goal: Modify the program to allow appending data to an 
          existing file instead of overwriting it.

    Key Features:
    - Use `std::ofstream` with the `std::ios::app` flag.
    - Append user-provided data to the end of the file.
    - Handle file opening errors gracefully.

    Practical Application:
    - Extending logs or records without losing existing data.
    - Allowing incremental updates to a file.

    New Concepts:
    - `std::ios::app` (append mode): Ensures that data is added
      to the end of the file without erasing existing contents.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename; // Variable to store the filename

    // Prompt the user for a filename
    cout << "Enter the name of the file to append data to: ";
    getline(cin, filename); // Read the filename from the user

    // ==========================================================
    // 1. Opening the File in Append Mode
    // ==========================================================
    /*
        To append data, we use the `std::ios::app` flag with `std::ofstream`.
        This ensures that data is added to the end of the file 
        without overwriting its existing content.
    */
    ofstream userFile(filename, ios::app); // Open in append mode
    if (!userFile) {
        cerr << "Error: Could not open the file '" << filename << "' for appending." << endl;
        return 1; // Exit the program if the file could not be opened
    }

    // Prompt the user for content to append
    cout << "Enter the content to append to '" << filename << "':" << endl;
    string content;
    getline(cin, content); // Read the content from the user

    // Write the content to the file
    userFile << content << endl;

    // Close the file
    userFile.close();
    cout << "Data appended to '" << filename << "' successfully." << endl;

    // ==========================================================
    // 2. Reading the File to Verify Contents
    // ==========================================================
    /*
        Re-open the file in `std::ifstream` mode to verify 
        that the new content has been appended correctly.
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