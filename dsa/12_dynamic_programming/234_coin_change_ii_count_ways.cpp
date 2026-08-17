/*
 * 234. Coin Change II (Count Combinations)
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Count the distinct coin combinations that make up an amount. Order does not
 * matter, so {1,2} and {2,1} are the same combination.
 *
 * Approach: unbounded knapsack counting. The loop order is what distinguishes
 * combinations from permutations - putting coins on the *outside* means each
 * coin is considered once for the whole table, so a combination can only be
 * built in its canonical coin order. Swapping the loops would count permutations.
 *
 * Time: O(amount * coins)   Space: O(amount)
 */
#include <bits/stdc++.h>
using namespace std;

long long change(int amount, const vector<int>& coins) {
    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins)                          // coins outside: combinations
        for (int a = coin; a <= amount; ++a)
            dp[a] += dp[a - coin];
    return dp[amount];
}

int main() {
    cout << change(5, {1, 2, 5}) << "\n";   // 4
    cout << change(3, {2}) << "\n";         // 0
    cout << change(10, {10}) << "\n";       // 1
    return 0;
}
