/*
 * 236. Unbounded Knapsack
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Maximise value within a weight capacity, where each item may be taken any
 * number of times.
 *
 * Approach: identical to 0/1 knapsack except the capacity loop runs upwards. At
 * the moment dp[w - weight] is read it may already include the current item,
 * which is exactly the reuse the unbounded version allows.
 *
 * Time: O(n * capacity)   Space: O(capacity)
 */
#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(const vector<int>& weights, const vector<int>& values,
                      int capacity) {
    vector<int> dp(capacity + 1, 0);
    for (int i = 0; i < (int)weights.size(); ++i)
        for (int w = weights[i]; w <= capacity; ++w)       // upwards: reuse allowed
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
    return dp[capacity];
}

int main() {
    cout << unboundedKnapsack({2, 4, 6}, {5, 11, 13}, 10) << "\n";   // 27
    cout << unboundedKnapsack({1, 3, 4, 5}, {10, 40, 50, 70}, 8) << "\n";   // 110
    return 0;
}
