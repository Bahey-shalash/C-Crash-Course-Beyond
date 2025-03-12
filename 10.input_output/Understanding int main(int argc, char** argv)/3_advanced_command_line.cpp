/*
    ==========================================================
    MODULE 3: ADVANCED COMMAND-LINE ARGUMENTS
    ==========================================================
    This program demonstrates advanced techniques:
    1. Parsing options and flags.
    2. Using libraries like `getopt` for structured argument parsing.
    3. Handling key-value arguments.

    Example:
    A program that accepts options for mode and verbosity:
    ./advanced_command_line --mode=fast --verbose
*/

#include <iostream>
#include <string>
#include <cstring> // For `strcmp`
using namespace std;

int main(int argc, char** argv) {
    string mode = "default"; // Default mode
    bool verbose = false;    // Verbosity flag

    // Parse arguments
    for (int i = 1; i < argc; ++i) {
        if (strncmp(argv[i], "--mode=", 7) == 0) {
            mode = argv[i] + 7; // Extract the mode value
        } else if (strcmp(argv[i], "--verbose") == 0) {
            verbose = true; // Enable verbose mode
        } else {
            cerr << "Unknown argument: " << argv[i] << endl;
        }
    }

    // Display the parsed options
    cout << "Mode: " << mode << endl;
    if (verbose) {
        cout << "Verbose mode enabled." << endl;
    }

    return 0;
}