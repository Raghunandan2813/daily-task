/*
 * 244. Matrix Chain Multiplication
 * Topic: Dynamic Programming | Difficulty: Hard
 *
 * Given matrix dimensions, parenthesise the product to minimise the number of
 * scalar multiplications.
 *
 * Approach: interval DP. dp[i][j] is the cheapest way to multiply matrices i
 * through j; try every split point k, paying dp[i][k] + dp[k+1][j] plus the cost
 * of the final multiply. Intervals must be processed in increasing length so the
 * subproblems are ready when needed.
 *
 * Time: O(n^3)   Space: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;

// dims has n+1 entries: matrix i is dims[i] x dims[i+1].
int matrixChainOrder(const vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] +
                           dims[i] * dims[k + 1] * dims[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    cout << matrixChainOrder({40, 20, 30, 10, 30}) << "\n";   // 26000
    cout << matrixChainOrder({10, 20, 30}) << "\n";           // 6000
    return 0;
}
