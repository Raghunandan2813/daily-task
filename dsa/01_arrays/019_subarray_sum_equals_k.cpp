/*
 * 019. Subarray Sum Equals K
 * Topic: Arrays | Difficulty: Medium
 *
 * Count the number of contiguous subarrays whose sum equals k. Values may be
 * negative, so a sliding window does not apply.
 *
 * Approach: prefix sums. A subarray (j, i] sums to k when prefix[i] - prefix[j]
 * == k. Keep a hash map of how many times each prefix sum has occurred and add
 * the count of (prefix - k) at every step.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int subarraySum(const vector<int>& nums, int k) {
    unordered_map<long long, int> freq;
    freq[0] = 1;
    long long prefix = 0;
    int count = 0;
    for (int x : nums) {
        prefix += x;
        auto it = freq.find(prefix - k);
        if (it != freq.end()) count += it->second;
        ++freq[prefix];
    }
    return count;
}

int main() {
    cout << subarraySum({1, 1, 1}, 2) << "\n";        // 2
    cout << subarraySum({1, 2, 3}, 3) << "\n";        // 2
    cout << subarraySum({1, -1, 0}, 0) << "\n";       // 3
    return 0;
}
