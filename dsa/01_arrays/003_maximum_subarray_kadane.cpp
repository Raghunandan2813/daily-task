/*
 * 003. Maximum Subarray (Kadane's Algorithm)
 * Topic: Arrays | Difficulty: Medium
 *
 * Find the contiguous subarray with the largest sum and return that sum.
 *
 * Approach: Kadane. Let cur be the best sum of a subarray ending at i. Either we
 * extend the previous subarray or start fresh at nums[i]:
 *     cur = max(nums[i], cur + nums[i])
 * The answer is the maximum cur over all i.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int>& nums) {
    int cur = nums[0], best = nums[0];
    for (int i = 1; i < (int)nums.size(); ++i) {
        cur = max(nums[i], cur + nums[i]);
        best = max(best, cur);
    }
    return best;
}

int main() {
    cout << maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << "\n";   // 6
    cout << maxSubArray({-3, -1, -7}) << "\n";                      // -1
    return 0;
}
