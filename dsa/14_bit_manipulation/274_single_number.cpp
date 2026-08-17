/*
 * 274. Single Number
 * Topic: Bit Manipulation | Difficulty: Easy
 *
 * Every element appears twice except one. Find it in linear time with constant
 * space.
 *
 * Approach: XOR the whole array. XOR is commutative and associative, and
 * x ^ x == 0, so every pair cancels regardless of order and only the lone value
 * survives.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int>& nums) {
    int acc = 0;
    for (int x : nums) acc ^= x;
    return acc;
}

int main() {
    cout << singleNumber({2, 2, 1}) << "\n";           // 1
    cout << singleNumber({4, 1, 2, 1, 2}) << "\n";     // 4
    return 0;
}
