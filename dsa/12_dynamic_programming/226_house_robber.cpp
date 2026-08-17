/*
 * 226. House Robber
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Maximise the loot from a row of houses without robbing two adjacent ones.
 *
 * Approach: at each house the choice is to rob it (adding its value to the best
 * total two houses back) or skip it (keeping the best total one house back):
 *     dp[i] = max(dp[i-1], dp[i-2] + nums[i])
 * Only the last two values matter.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int rob(const vector<int>& nums) {
    int prev2 = 0, prev1 = 0;                       // best up to i-2 and i-1
    for (int x : nums) {
        int cur = max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    cout << rob({1, 2, 3, 1}) << "\n";       // 4
    cout << rob({2, 7, 9, 3, 1}) << "\n";    // 12
    return 0;
}
