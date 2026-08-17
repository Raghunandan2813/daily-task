/*
 * 232. Target Sum
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Assign a + or - sign to every number so the expression evaluates to a target.
 * Count the ways.
 *
 * Approach: let P be the sum of the positives and N of the negatives. Then
 * P - N = target and P + N = total, so P = (total + target) / 2. Counting sign
 * assignments therefore reduces to counting subsets summing to P - a standard
 * counting knapsack.
 *
 * Time: O(n * sum)   Space: O(sum)
 */
#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(const vector<int>& nums, int target) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > total || (total + target) % 2) return 0;
    int want = (total + target) / 2;

    vector<int> dp(want + 1, 0);
    dp[0] = 1;
    for (int x : nums)
        for (int s = want; s >= x; --s)
            dp[s] += dp[s - x];
    return dp[want];
}

int main() {
    cout << findTargetSumWays({1, 1, 1, 1, 1}, 3) << "\n";   // 5
    cout << findTargetSumWays({1}, 1) << "\n";               // 1
    return 0;
}
