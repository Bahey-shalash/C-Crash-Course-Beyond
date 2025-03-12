/* ### Course 5: Introduction to C-Style Strings (Char Arrays) ###

   This course introduces C-style strings, which are represented as character
   arrays ending with a null terminator (`'\0'`).
*/

#include <iostream>

int main() {
    // C-style string with explicit null terminator
    char cstring[] = "ABC"; //{ 'A', 'B', 'C', '\0' }

    // Print each character until null terminator is encountered
    int i = 0;
    while (cstring[i]) { // The loop stops when it encounters '\0' (null terminator)
        std::cout << cstring[i++] << ' ';
    }
    std::cout << '\n';

    return 0;
}