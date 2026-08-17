/*
 * 233. Coin Change (Fewest Coins)
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Find the minimum number of coins summing to an amount, or -1 if impossible.
 * Coins may be reused.
 *
 * Approach: unbounded knapsack. dp[a] is the fewest coins making amount a; the
 * capacity loop runs *upwards* precisely so a coin can be reused within the same
 * round. Greedy fails here for arbitrary denominations, which is why DP is
 * required.
 *
 * Time: O(amount * number of coins)   Space: O(amount)
 */
#include <bits/stdc++.h>
using namespace std;

int coinChange(const vector<int>& coins, int amount) {
    const int INF = INT_MAX / 2;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int coin : coins)
        for (int a = coin; a <= amount; ++a)              // upwards: reuse allowed
            dp[a] = min(dp[a], dp[a - coin] + 1);
    return dp[amount] >= INF ? -1 : dp[amount];
}

int main() {
    cout << coinChange({1, 2, 5}, 11) << "\n";   // 3
    cout << coinChange({2}, 3) << "\n";          // -1
    cout << coinChange({1}, 0) << "\n";          // 0
    return 0;
}
