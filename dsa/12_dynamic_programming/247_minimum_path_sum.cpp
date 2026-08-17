/*
 * 247. Minimum Path Sum
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Find the path from top-left to bottom-right of a grid of costs that minimises
 * the sum, moving only right or down.
 *
 * Approach: dp[j] is the cheapest cost to reach column j of the current row.
 * Interior cells take the cheaper of "from above" (the stale dp[j]) and "from
 * the left" (dp[j-1]); the first row and column have only one predecessor.
 *
 * Time: O(m * n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int minPathSum(const vector<vector<int> >& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n, 0);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) dp[j] = grid[0][0];
            else if (i == 0) dp[j] = dp[j - 1] + grid[i][j];
            else if (j == 0) dp[j] = dp[j] + grid[i][j];
            else dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
        }
    return dp[n - 1];
}

int main() {
    cout << minPathSum({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}) << "\n";   // 7
    cout << minPathSum({{1, 2, 3}, {4, 5, 6}}) << "\n";              // 12
    return 0;
}
