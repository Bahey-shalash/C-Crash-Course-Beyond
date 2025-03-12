/* ### File: bitwise_operations.cpp ###
   ### Course: Understanding Bitwise Operations in C++ ###

   **Overview**
   Bitwise operations manipulate data at the bit level, which can be very 
   efficient for certain tasks, such as low-level programming, optimization, 
   and working with flags or bitfields. In this course, we’ll cover the 
   primary bitwise operators in C++ and provide examples for each.

   **Bitwise Operators**
   - `&`  (AND): Sets each bit to 1 if both bits are 1.
   - `|`  (OR): Sets each bit to 1 if at least one of the bits is 1.
   - `^`  (XOR): Sets each bit to 1 if only one of the bits is 1.
   - `~`  (NOT): Inverts all bits (one’s complement).
   - `<<` (Left Shift): Shifts bits to the left, filling with 0s from the right.
   - `>>` (Right Shift): Shifts bits to the right, discarding bits from the right.
*/

#include <iostream>
#include <bitset>  // For displaying binary format

int main() {
    // Example integers to demonstrate bitwise operations
    int a = 29;    // Binary: 0001 1101
    int b = 15;    // Binary: 0000 1111

    // Display original numbers in binary format
    std::cout << "Initial values:\n";
    std::cout << "a = " << a << " (" << std::bitset<8>(a) << ")\n";
    std::cout << "b = " << b << " (" << std::bitset<8>(b) << ")\n\n";

    // Bitwise AND (&)
    int result_and = a & b;
    std::cout << "a & b = " << result_and << " (" << std::bitset<8>(result_and) << ")\n";
    // Explanation: 0001 1101 & 0000 1111 = 0000 1101 (13)

    // Bitwise OR (|)
    int result_or = a | b;
    std::cout << "a | b = " << result_or << " (" << std::bitset<8>(result_or) << ")\n";
    // Explanation: 0001 1101 | 0000 1111 = 0001 1111 (31)

    // Bitwise XOR (^)
    int result_xor = a ^ b;
    std::cout << "a ^ b = " << result_xor << " (" << std::bitset<8>(result_xor) << ")\n";
    // Explanation: 0001 1101 ^ 0000 1111 = 0001 0010 (18)

    // Bitwise NOT (~) on `a`
    int result_not = ~a;
    std::cout << "~a = " << result_not << " (" << std::bitset<8>(result_not) << ")\n";
    // Explanation: ~0001 1101 = 1110 0010 (2's complement: -30)

    // Left Shift (<<)
    int result_left_shift = a << 1;
    std::cout << "a << 1 = " << result_left_shift << " (" << std::bitset<8>(result_left_shift) << ")\n";
    // Explanation: 0001 1101 << 1 = 0011 1010 (58)

    // Right Shift (>>)
    int result_right_shift = a >> 1;
    std::cout << "a >> 1 = " << result_right_shift << " (" << std::bitset<8>(result_right_shift) << ")\n";
    // Explanation: 0001 1101 >> 1 = 0000 1110 (14)

    return 0;
}

/*
Explanation of Bitwise Operations:
-----------------------------------
1. **Bitwise AND (`&`)**:
   - Each bit in the result is 1 if the corresponding bits in both operands are 1.
   - Example: `a & b` = 0001 1101 & 0000 1111 = 0000 1101 (decimal 13)

2. **Bitwise OR (`|`)**:
   - Each bit in the result is 1 if at least one of the corresponding bits in either operand is 1.
   - Example: `a | b` = 0001 1101 | 0000 1111 = 0001 1111 (decimal 31)

3. **Bitwise XOR (`^`)**:
   - Each bit in the result is 1 if the corresponding bits in the operands are different.
   - Example: `a ^ b` = 0001 1101 ^ 0000 1111 = 0001 0010 (decimal 18)

4. **Bitwise NOT (`~`)**:
   - Each bit in the result is the inverse of the corresponding bit in the operand.
   - Example: `~a` = ~0001 1101 = 1110 0010 (in two’s complement: decimal -30)

5. **Left Shift (`<<`)**:
   - Shifts bits to the left, filling with 0s from the right.
   - Example: `a << 1` = 0001 1101 << 1 = 0011 1010 (decimal 58)

6. **Right Shift (`>>`)**:
   - Shifts bits to the right, discarding bits from the right.
   - Example: `a >> 1` = 0001 1101 >> 1 = 0000 1110 (decimal 14)

Practical Uses:
---------------
- Bitwise AND (`&`): Often used in masking operations to clear specific bits.
- Bitwise OR (`|`): Used to set specific bits.
- Bitwise XOR (`^`): Commonly used to toggle specific bits or in encryption algorithms.
- Bitwise NOT (`~`): Useful for bitwise negation or creating a bitmask.
- Shifts (`<<`, `>>`): Often used in low-level programming, efficient multiplication/division by powers of 2.
*/