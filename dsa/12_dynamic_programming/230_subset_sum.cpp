/*
 * 230. Subset Sum
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Decide whether some subset of the array sums to a target.
 *
 * Approach: the 0/1 knapsack pattern with booleans instead of values.
 * dp[s] records whether sum s is reachable; each new element propagates
 * reachability upward, and the capacity loop again runs downwards so an element
 * is used at most once.
 *
 * Time: O(n * target)   Space: O(target)
 */
#include <bits/stdc++.h>
using namespace std;

bool subsetSum(const vector<int>& nums, int target) {
    vector<char> dp(target + 1, false);
    dp[0] = true;                                   // the empty subset
    for (int x : nums)
        for (int s = target; s >= x; --s)
            if (dp[s - x]) dp[s] = true;
    return dp[target];
}

int main() {
    cout << subsetSum({3, 34, 4, 12, 5, 2}, 9) << "\n";    // 1
    cout << subsetSum({3, 34, 4, 12, 5, 2}, 30) << "\n";   // 0
    return 0;
}
