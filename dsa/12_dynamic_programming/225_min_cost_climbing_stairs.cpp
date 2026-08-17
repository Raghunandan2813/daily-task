/*
 * 225. Min Cost Climbing Stairs
 * Topic: Dynamic Programming | Difficulty: Easy
 *
 * Paying cost[i] lets you step off stair i by one or two steps. You may start at
 * index 0 or 1. Find the cheapest way to reach the top.
 *
 * Approach: dp[i] is the cheapest cost to *stand on* stair i, which is cost[i]
 * plus the cheaper of the two stairs you could have come from. The top is one
 * past the end, so the answer is the cheaper of the last two stairs.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(const vector<int>& cost) {
    int prev2 = cost[0], prev1 = cost[1];
    for (int i = 2; i < (int)cost.size(); ++i) {
        int cur = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = cur;
    }
    return min(prev1, prev2);
}

int main() {
    cout << minCostClimbingStairs({10, 15, 20}) << "\n";                   // 15
    cout << minCostClimbingStairs({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}) << "\n";   // 6
    return 0;
}
