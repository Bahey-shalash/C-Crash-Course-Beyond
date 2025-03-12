/*
    ==========================================================
    INTRODUCTION TO BINARY FILE HANDLING
    ==========================================================
    Binary files store data in a compact, non-human-readable format.
    They are useful for applications requiring efficient storage
    and fast read/write operations, such as saving raw data or
    serialized objects.

    This program demonstrates:
    1. Writing binary data to a file.
    2. Reading binary data from a file.
    3. Using `std::ios::binary` mode for binary operations.

    Practical Applications:
    - Saving object states for later retrieval.
    - Storing large amounts of numerical data efficiently.
    - Creating custom file formats for your applications.

    Key Concepts:
    - Binary mode (`std::ios::binary`).
    - Writing and reading raw memory using `write` and `read`.
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    string filename = "students.bin";  // Name of the binary file

    // ==========================================================
    // 1. Writing Binary Data to a File
    // ==========================================================
    /*
        Binary data is written using `write`, which writes raw
        bytes from memory to the file.
    */
    ofstream outputFile(filename, ios::binary);
    if (!outputFile) {
        cerr << "Error: Could not open the file '" << filename << "' for writing."
             << endl;
        return 1;
    }

    // Create a sample Student object
    Student s1 = {"Alice", 20, 3.8};

    // Write the Student object to the file
    outputFile.write(reinterpret_cast<char*>(&s1), sizeof(Student));
    cout << "Binary data written to '" << filename << "' successfully." << endl;

    outputFile.close();  // Close the file after writing

    // ==========================================================
    // 2. Reading Binary Data from a File
    // ==========================================================
    /*
        Binary data is read using `read`, which loads raw bytes
        from the file into memory.
    */
    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Error: Could not open the file '" << filename << "' for reading."
             << endl;
        return 1;
    }

    // Create an empty Student object to store the data
    Student s2;

    // Read the Student object from the file
    inputFile.read(reinterpret_cast<char*>(&s2), sizeof(Student));
    if (inputFile) {
        cout << "\nBinary data read successfully:\n";
        cout << "Name: " << s2.name << endl;
        cout << "Age: " << s2.age << endl;
        cout << "GPA: " << s2.gpa << endl;
    } else {
        cerr << "Error: Could not read data from the file." << endl;
    }

    inputFile.close();  // Close the file after reading

    return 0;  // End of the program
}