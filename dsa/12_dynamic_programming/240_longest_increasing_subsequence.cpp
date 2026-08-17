/*
 * 240. Longest Increasing Subsequence (O(n^2))
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Find the length of the longest strictly increasing subsequence.
 *
 * Approach: dp[i] is the length of the best increasing subsequence *ending at*
 * i. For each i, scan every earlier j with a smaller value and extend the best
 * of those. The answer is the maximum over all i, not dp[n-1].
 *
 * Time: O(n^2)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(const vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> dp(nums.size(), 1);
    int best = 1;
    for (int i = 1; i < (int)nums.size(); ++i) {
        for (int j = 0; j < i; ++j)
            if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        best = max(best, dp[i]);
    }
    return best;
}

int main() {
    cout << lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) << "\n";   // 4
    cout << lengthOfLIS({7, 7, 7, 7}) << "\n";                   // 1
    return 0;
}
