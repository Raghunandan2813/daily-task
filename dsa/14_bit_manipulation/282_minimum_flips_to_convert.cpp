/*
 * 282. Minimum Flips to Convert A to B
 * Topic: Bit Manipulation | Difficulty: Easy
 *
 * Count the bit flips needed to turn integer a into integer b.
 *
 * Approach: a ^ b sets exactly the bits where the two numbers disagree, so the
 * answer is its population count. Brian Kernighan's loop counts those bits in
 * one pass per differing bit.
 *
 * Time: O(number of differing bits)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int minFlips(int a, int b) {
    unsigned int diff = (unsigned int)a ^ (unsigned int)b;
    int count = 0;
    while (diff) { diff &= diff - 1; ++count; }
    return count;
}

int main() {
    cout << minFlips(10, 20) << "\n";   // 4   (01010 vs 10100)
    cout << minFlips(7, 10) << "\n";    // 3
    cout << minFlips(5, 5) << "\n";     // 0
    return 0;
}
