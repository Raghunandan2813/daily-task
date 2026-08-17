/*
 * 273. Power of Two
 * Topic: Bit Manipulation | Difficulty: Easy
 *
 * Decide whether an integer is a power of two.
 *
 * Approach: a power of two has exactly one set bit, so n & (n-1) clears that bit
 * and leaves zero. The n > 0 guard rules out zero and negatives, whose two's
 * complement patterns would otherwise slip through.
 *
 * Time: O(1)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }

bool isPowerOfFour(int n) {
    // A power of four is a power of two whose single bit sits at an even
    // position; 0x55555555 masks exactly those positions.
    return isPowerOfTwo(n) && (n & 0x55555555) != 0;
}

int main() {
    cout << isPowerOfTwo(16) << "\n";    // 1
    cout << isPowerOfTwo(12) << "\n";    // 0
    cout << isPowerOfTwo(0) << "\n";     // 0
    cout << isPowerOfFour(16) << "\n";   // 1
    cout << isPowerOfFour(8) << "\n";    // 0
    return 0;
}
