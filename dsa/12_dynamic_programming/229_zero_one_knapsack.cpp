/*
 * 229. 0/1 Knapsack
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Choose a subset of items, each with a weight and a value, to maximise value
 * without exceeding the capacity. Each item may be taken at most once.
 *
 * Approach: dp[w] is the best value achievable with capacity w. Processing items
 * one at a time and iterating the capacity *downwards* is what enforces the
 * "at most once" rule - going upwards would let an item be reused within the
 * same round, which is the unbounded variant.
 *
 * Time: O(n * capacity)   Space: O(capacity)
 */
#include <bits/stdc++.h>
using namespace std;

int knapsack(const vector<int>& weights, const vector<int>& values, int capacity) {
    vector<int> dp(capacity + 1, 0);
    for (int i = 0; i < (int)weights.size(); ++i)
        for (int w = capacity; w >= weights[i]; --w)      // downwards!
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
    return dp[capacity];
}

int main() {
    cout << knapsack({1, 3, 4, 5}, {1, 4, 5, 7}, 7) << "\n";   // 9
    cout << knapsack({10, 20, 30}, {60, 100, 120}, 50) << "\n";   // 220
    return 0;
}
