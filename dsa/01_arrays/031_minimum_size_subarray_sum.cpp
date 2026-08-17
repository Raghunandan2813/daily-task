/*
 * 031. Minimum Size Subarray Sum
 * Topic: Arrays | Difficulty: Medium
 *
 * Given positive integers, find the length of the shortest contiguous subarray
 * whose sum is at least target. Return 0 if none exists.
 *
 * Approach: sliding window. All values are positive, so the running sum grows
 * monotonically as the window widens - shrink from the left as long as the sum
 * still meets the target.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, const vector<int>& nums) {
    int left = 0, best = INT_MAX;
    long long sum = 0;
    for (int right = 0; right < (int)nums.size(); ++right) {
        sum += nums[right];
        while (sum >= target) {
            best = min(best, right - left + 1);
            sum -= nums[left++];
        }
    }
    return best == INT_MAX ? 0 : best;
}

int main() {
    cout << minSubArrayLen(7, {2, 3, 1, 2, 4, 3}) << "\n";   // 2
    cout << minSubArrayLen(11, {1, 1, 1, 1}) << "\n";        // 0
    return 0;
}
