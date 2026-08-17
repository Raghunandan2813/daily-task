/*
 * 281. XOR of Range 1..N
 * Topic: Bit Manipulation | Difficulty: Medium
 *
 * Compute 1 ^ 2 ^ ... ^ n, and the XOR over an arbitrary range [l, r].
 *
 * Approach: the prefix XOR is periodic with period 4, because each block of four
 * consecutive integers XORs to zero. That gives a closed form based on n % 4.
 * A range XOR is then prefix(r) ^ prefix(l-1), since the shared prefix cancels.
 *
 * Time: O(1)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int xorUpTo(int n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        default: return 0;
    }
}

int xorRange(int l, int r) { return xorUpTo(r) ^ xorUpTo(l - 1); }

int main() {
    cout << xorUpTo(6) << "\n";        // 7
    cout << xorRange(3, 9) << "\n";    // 2
    // brute-force check
    int brute = 0;
    for (int i = 3; i <= 9; ++i) brute ^= i;
    cout << brute << "\n";             // 2
    return 0;
}
