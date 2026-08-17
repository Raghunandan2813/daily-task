/*
 * 278. XOR Swap and Common Bit Tricks
 * Topic: Bit Manipulation | Difficulty: Easy
 *
 * A collection of the standard single-expression bit manipulations.
 *
 * Approach: each rests on a property of XOR or two's complement. XOR swapping
 * works because x ^ y ^ y == x (but breaks when both operands alias the same
 * variable). -x is ~x + 1, which is why x & -x isolates the lowest set bit.
 *
 * Time: O(1) each   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void xorSwap(int& a, int& b) {
    if (&a == &b) return;                            // aliasing would zero both
    a ^= b;
    b ^= a;
    a ^= b;
}

bool getBit(int x, int i)      { return (x >> i) & 1; }
int  setBit(int x, int i)      { return x | (1 << i); }
int  clearBit(int x, int i)    { return x & ~(1 << i); }
int  toggleBit(int x, int i)   { return x ^ (1 << i); }
int  lowestSetBit(int x)       { return x & -x; }
int  clearLowestSetBit(int x)  { return x & (x - 1); }
bool isOdd(int x)              { return x & 1; }

int main() {
    int a = 5, b = 9;
    xorSwap(a, b);
    cout << a << " " << b << "\n";       // 9 5
    cout << getBit(11, 1) << "\n";       // 1  (1011)
    cout << setBit(8, 1) << "\n";        // 10
    cout << clearBit(11, 1) << "\n";     // 9
    cout << toggleBit(11, 2) << "\n";    // 15
    cout << lowestSetBit(12) << "\n";    // 4
    cout << clearLowestSetBit(12) << "\n";   // 8
    cout << isOdd(7) << "\n";            // 1
    return 0;
}
