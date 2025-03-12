/*
    ==========================================================
    MENU-DRIVEN FILE OPERATIONS
    ==========================================================
    Goal: Create a program that offers the user a menu to:
          1. Overwrite a file.
          2. Append data to an existing file.
          3. Read and display the contents of a file.

    Key Features:
    - Menu-driven interface using a loop and user input.
    - Flexible handling of file operations.
    - Reusability of code for different operations.

    Practical Application:
    - Interactive tools for managing text files.
    - Enhances user experience by offering multiple options.

    New Concepts:
    - Menu-driven logic using loops and `switch` statements.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
void overwriteFile(const string& filename);
void appendToFile(const string& filename);
void readFile(const string& filename);

int main() {
    string filename; // Variable to store the filename
    int choice;      // User's menu choice

    // Prompt the user for a filename
    cout << "Enter the name of the file to work with: ";
    getline(cin, filename); // Read the filename from the user

    do {
        // Display the menu
        cout << "\nMenu:" << endl;
        cout << "1. Overwrite the file" << endl;
        cout << "2. Append data to the file" << endl;
        cout << "3. Read the file contents" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore any leftover newline characters

        // Handle the user's choice
        switch (choice) {
            case 1:
                overwriteFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFile(filename);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0; // End of the program
}

// ==========================================================
// Function to Overwrite a File
// ==========================================================
void overwriteFile(const string& filename) {
    ofstream file(filename); // Open in overwrite mode
    if (!file) {
        cerr << "Error: Could not open the file '" << filename << "' for writing." << endl;
        return;
    }

    cout << "Enter the content to write to '" << filename << "':" << endl;
    string content;
    cin.ignore(); // Clear any leftover input
    getline(cin, content);

    file << content << endl; // Write to the file
    file.close();
    cout << "File '" << filename << "' overwritten successfully." << endl;
}

// ==========================================================
// Function to Append Data to a File
// ==========================================================
void appendToFile(const string& filename) {
    ofstream file(filename, ios::app); // Open in append mode
    if (!file) {
        cerr << "Error: Could not open the file '" << filename << "' for appending." << endl;
        return;
    }

    cout << "Enter the content to append to '" << filename << "':" << endl;
    string content;
    cin.ignore(); // Clear any leftover input
    getline(cin, content);

    file << content << endl; // Append to the file
    file.close();
    cout << "Data appended to '" << filename << "' successfully." << endl;
}

// ==========================================================
// Function to Read a File
// ==========================================================
void readFile(const string& filename) {
    ifstream file(filename); // Open in read mode
    if (!file) {
        cerr << "Error: Could not open the file '" << filename << "' for reading." << endl;
        return;
    }

    cout << "Contents of '" << filename << "':" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl; // Display each line
    }

    file.close();
}