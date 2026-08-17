/*
 * 023. Missing Number
 * Topic: Arrays | Difficulty: Easy
 *
 * An array holds n distinct numbers drawn from [0, n]. Find the one missing.
 *
 * Approach: XOR every index 0..n with every array value. Each present number
 * appears exactly twice and cancels to zero, leaving only the missing one. XOR
 * avoids the overflow risk of the sum formula.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int missingNumber(const vector<int>& nums) {
    int n = nums.size(), acc = n;
    for (int i = 0; i < n; ++i) acc ^= i ^ nums[i];
    return acc;
}

int main() {
    cout << missingNumber({3, 0, 1}) << "\n";                  // 2
    cout << missingNumber({9, 6, 4, 2, 3, 5, 7, 0, 1}) << "\n";  // 8
    return 0;
}
