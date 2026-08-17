/*
 * 279. Reverse Bits
 * Topic: Bit Manipulation | Difficulty: Easy
 *
 * Reverse the 32 bits of an unsigned integer.
 *
 * Approach: shift the result left and push in the input's lowest bit, 32 times.
 * The divide-and-conquer version instead swaps adjacent bits, then pairs, then
 * nibbles, then bytes and finally halves - five masked steps instead of a loop.
 *
 * Time: O(32) or O(log 32)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

unsigned int reverseBits(unsigned int n) {
    unsigned int result = 0;
    for (int i = 0; i < 32; ++i) {
        result = (result << 1) | (n & 1u);
        n >>= 1;
    }
    return result;
}

unsigned int reverseBitsFast(unsigned int n) {
    n = ((n >> 1) & 0x55555555u) | ((n & 0x55555555u) << 1);   // swap bits
    n = ((n >> 2) & 0x33333333u) | ((n & 0x33333333u) << 2);   // swap pairs
    n = ((n >> 4) & 0x0F0F0F0Fu) | ((n & 0x0F0F0F0Fu) << 4);   // swap nibbles
    n = ((n >> 8) & 0x00FF00FFu) | ((n & 0x00FF00FFu) << 8);   // swap bytes
    return (n >> 16) | (n << 16);                              // swap halves
}

int main() {
    cout << reverseBits(43261596u) << "\n";       // 964176192
    cout << reverseBitsFast(43261596u) << "\n";   // 964176192
    return 0;
}
