/*
 * 275. Single Number II
 * Topic: Bit Manipulation | Difficulty: Medium
 *
 * Every element appears three times except one. Find it.
 *
 * Approach: plain XOR fails because triples do not cancel. Instead count the set
 * bits at each of the 32 positions across all numbers; positions belonging only
 * to the triples are multiples of three, so the remainder mod 3 reconstructs the
 * lone value bit by bit. The sign bit is handled by building into an unsigned
 * accumulator.
 *
 * Time: O(32n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int>& nums) {
    unsigned int result = 0;
    for (int bit = 0; bit < 32; ++bit) {
        int count = 0;
        for (int x : nums) count += ((unsigned int)x >> bit) & 1u;
        if (count % 3) result |= (1u << bit);
    }
    return (int)result;
}

int main() {
    cout << singleNumber({2, 2, 3, 2}) << "\n";                 // 3
    cout << singleNumber({0, 1, 0, 1, 0, 1, 99}) << "\n";       // 99
    cout << singleNumber({-2, -2, 1, -2}) << "\n";              // 1
    return 0;
}
