/*
 * 012. Majority Element (Boyer-Moore Voting)
 * Topic: Arrays | Difficulty: Easy
 *
 * Find the element that appears more than n/2 times. It is guaranteed to exist.
 *
 * Approach: Boyer-Moore voting. Keep a candidate and a counter; a matching
 * element increments the count, a different one decrements it. Pairs of unequal
 * elements cancel out, so the true majority survives.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int majorityElement(const vector<int>& nums) {
    int candidate = nums[0], count = 0;
    for (int x : nums) {
        if (count == 0) candidate = x;
        count += (x == candidate) ? 1 : -1;
    }
    return candidate;
}

int main() {
    cout << majorityElement({3, 2, 3}) << "\n";                  // 3
    cout << majorityElement({2, 2, 1, 1, 1, 2, 2}) << "\n";      // 2
    return 0;
}
