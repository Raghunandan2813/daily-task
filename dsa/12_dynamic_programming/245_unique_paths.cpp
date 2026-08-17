/*
 * 245. Unique Paths
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Count the paths from the top-left to the bottom-right of an m x n grid moving
 * only right or down.
 *
 * Approach: dp[j] holds the path count for the current row. Each cell is the sum
 * of the cell above (the previous value of dp[j]) and the cell to the left
 * (dp[j-1]), so a single row of storage suffices as it is updated in place.
 *
 * Time: O(m * n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

long long uniquePaths(int m, int n) {
    vector<long long> dp(n, 1);                     // the first row is all 1s
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            dp[j] += dp[j - 1];                     // above + left
    return dp[n - 1];
}

int main() {
    cout << uniquePaths(3, 7) << "\n";   // 28
    cout << uniquePaths(3, 2) << "\n";   // 3
    return 0;
}
