/* ==========================================================================
Lesson 3: I/O Performance – endl vs. '\\n' and Buffering

Theory:
---------
- std::endl outputs a newline and flushes the output buffer, which can be slow
  in tight loops.
- Using '\\n' outputs a newline without flushing, often making it faster.
- Stream buffering and disabling sync with C I/O
(std::ios_base::sync_with_stdio(false)) can further improve performance.

Key Points:
- Use '\\n' in performance-critical code where flushing isn’t required.
- Be cautious when mixing C and C++ I/O.
- Edge Cases: In interactive programs, you may want to flush to ensure output appears
immediately.

Example:
---------
Comparing output with std::endl and '\\n'.
========================================================================== */

#include <iostream>
using namespace std;

int main() {
    // Disable synchronization with C I/O for faster C++ stream operations.
    ios_base::sync_with_stdio(false);

    // Using std::endl (flushes each time)
    cout << "Using std::endl:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Line " << i << std::endl;
    }

    // Using '\n' (no flush)
    cout << "Using '\\n':\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Line " << i << "\n";
    }
    // Flush once at the end if needed.
    cout.flush();

    return 0;
}