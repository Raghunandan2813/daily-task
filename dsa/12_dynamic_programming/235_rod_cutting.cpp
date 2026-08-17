/*
 * 235. Rod Cutting
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * A rod of length n can be cut into pieces; a piece of length i sells for
 * price[i-1]. Maximise the revenue.
 *
 * Approach: unbounded knapsack where the "weight" of a piece is its length and
 * the "value" is its price. dp[len] is the best revenue for a rod of that
 * length, and pieces may repeat, so the length loop runs upwards.
 *
 * Time: O(n^2)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int rodCutting(const vector<int>& price) {
    int n = price.size();
    vector<int> dp(n + 1, 0);
    for (int piece = 1; piece <= n; ++piece)
        for (int len = piece; len <= n; ++len)
            dp[len] = max(dp[len], dp[len - piece] + price[piece - 1]);
    return dp[n];
}

int main() {
    cout << rodCutting({1, 5, 8, 9, 10, 17, 17, 20}) << "\n";   // 22
    cout << rodCutting({3, 5, 8, 9, 10, 17, 17, 20}) << "\n";   // 24
    return 0;
}
