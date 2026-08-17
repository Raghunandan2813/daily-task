/*
 * 032. Maximum Sum Subarray of Size K
 * Topic: Arrays | Difficulty: Easy
 *
 * Return the largest sum among all contiguous subarrays of exactly length k.
 *
 * Approach: fixed-size sliding window. Build the first window, then slide it one
 * step at a time, adding the entering element and subtracting the leaving one.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

long long maxSumSubarrayK(const vector<int>& nums, int k) {
    int n = nums.size();
    if (k > n) return 0;
    long long sum = 0;
    for (int i = 0; i < k; ++i) sum += nums[i];
    long long best = sum;
    for (int i = k; i < n; ++i) {
        sum += nums[i] - nums[i - k];
        best = max(best, sum);
    }
    return best;
}

int main() {
    cout << maxSumSubarrayK({2, 1, 5, 1, 3, 2}, 3) << "\n";   // 9
    return 0;
}
