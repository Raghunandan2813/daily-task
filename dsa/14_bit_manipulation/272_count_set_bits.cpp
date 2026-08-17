/*
 * 272. Count Set Bits
 * Topic: Bit Manipulation | Difficulty: Easy
 *
 * Count the 1 bits in an integer, and in every integer from 0 to n.
 *
 * Approach: Brian Kernighan's trick - n & (n-1) clears the lowest set bit, so
 * the loop runs once per set bit rather than once per bit position. For the
 * range version, dp[i] = dp[i >> 1] + (i & 1) reuses the already-computed count
 * of i with its last bit dropped.
 *
 * Time: O(number of set bits) single, O(n) for the range   Space: O(1) / O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int countBits(unsigned int n) {
    int count = 0;
    while (n) { n &= n - 1; ++count; }               // clears the lowest set bit
    return count;
}

vector<int> countBitsRange(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) dp[i] = dp[i >> 1] + (i & 1);
    return dp;
}

int main() {
    cout << countBits(11) << "\n";    // 3  (1011)
    cout << countBits(255) << "\n";   // 8
    for (int c : countBitsRange(8)) cout << c << " ";
    cout << "\n";   // 0 1 1 2 1 2 2 3 1
    return 0;
}
