/*
    ==========================================================
    MODULE 1: INTRODUCTION TO COMMAND-LINE ARGUMENTS
    ==========================================================
    Command-line arguments allow users to provide input to a
    program when it is executed from the terminal. They are
    passed to the `main` function as parameters.

    1. `int argc`:
       - Stands for "argument count".
       - Represents the number of command-line arguments passed,
         including the program name.

    2. `char** argv` (or `char* argv[]`):
       - Stands for "argument vector".
       - An array of C-style strings representing the arguments.
       - `argv[0]`: The name of the program.
       - `argv[1]`: The first argument, if provided.

    Practical Application:
    - Writing programs that accept input like file names, options,
      or configurations directly from the terminal.

    Let's explore a basic example.
*/

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    cout << "Number of arguments (argc): " << argc << endl;

    // Display all arguments
    cout << "Arguments (argv):" << endl;
    for (int i = 0; i < argc; ++i) {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }

    return 0;
}
/*
1.	Arguments:
        •When you run the program with:

./intro_command_line arg1 arg2 arg3

        •	argc = 4 (program name + 3 arguments).
        •	argv contains:
        •	argv[0] = "./intro_command_line"
        •	argv[1] = "arg1"
        •	argv[2] = "arg2"
        •	argv[3] = "arg3"

2.	Iterating Through Arguments:
        •Use a loop to print or process all arguments.

*/