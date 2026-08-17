/*
 * 223. Fibonacci Numbers (Memoisation and Tabulation)
 * Topic: Dynamic Programming | Difficulty: Easy
 *
 * Compute the n-th Fibonacci number, illustrating the three standard DP forms.
 *
 * Approach: naive recursion recomputes the same subproblems exponentially often.
 * Memoisation caches results top-down; tabulation fills the same table bottom-up;
 * and since each value depends only on the previous two, the table collapses to
 * two variables.
 *
 * Time: O(n)   Space: O(n) memoised, O(1) space-optimised
 */
#include <bits/stdc++.h>
using namespace std;

long long fibMemo(int n, vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
}

long long fibTabulation(int n) {
    if (n <= 1) return n;
    vector<long long> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

long long fibOptimised(int n) {
    if (n <= 1) return n;
    long long prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; ++i) {
        long long cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    vector<long long> memo(51, -1);
    cout << fibMemo(50, memo) << "\n";      // 12586269025
    cout << fibTabulation(50) << "\n";      // 12586269025
    cout << fibOptimised(50) << "\n";       // 12586269025
    return 0;
}
