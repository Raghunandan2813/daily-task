/*
 * 246. Unique Paths II (with Obstacles)
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Same grid-path count, but some cells are blocked.
 *
 * Approach: identical rolling-row DP, except a blocked cell is forced to zero
 * before the addition. That zero then propagates naturally to every cell whose
 * only routes passed through it.
 *
 * Time: O(m * n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

long long uniquePathsWithObstacles(const vector<vector<int> >& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<long long> dp(n, 0);
    dp[0] = (grid[0][0] == 0) ? 1 : 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) dp[j] = 0;          // blocked
            else if (j > 0) dp[j] += dp[j - 1];
        }
    return dp[n - 1];
}

int main() {
    cout << uniquePathsWithObstacles({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}) << "\n";   // 2
    cout << uniquePathsWithObstacles({{0, 1}, {0, 0}}) << "\n";                    // 1
    return 0;
}
