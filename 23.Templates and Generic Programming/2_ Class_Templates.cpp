/* ==========================================================================
Lesson 2: Class Templates

Theory:
---------
Class templates enable you to create classes that work with any data type.
They are the foundation of generic containers (like std::vector).

Key Points:
- You can define member functions inside or outside the class template.
- Default template parameters can be provided.
- Edge Cases: Incomplete template specializations may lead to linker errors.

Example:
---------
A simple Pair class that stores two values.
========================================================================== */

#include <iostream>
using namespace std;

template <typename T>
class Pair {
public:
    Pair(T first, T second) : first(first), second(second) {}
    T getFirst() const { return first; }
    T getSecond() const { return second; }

private:
    T first, second;
};

int main() {
    Pair<int> intPair(1, 2);
    cout << "Pair: (" << intPair.getFirst() << ", " << intPair.getSecond() << ")"
         << endl;

    Pair<double> doublePair(3.14, 2.718);
    cout << "Pair: (" << doublePair.getFirst() << ", " << doublePair.getSecond() << ")"
         << endl;
    return 0;
}