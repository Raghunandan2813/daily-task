/*
 * 249. Maximal Square
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Find the area of the largest square of 1s in a binary matrix.
 *
 * Approach: dp[i][j] is the side length of the largest square whose *bottom
 * right corner* is (i, j). A square of side k+1 needs squares of side k above,
 * to the left, and diagonally up-left, so the cell is 1 + the minimum of those
 * three. The minimum is what forces all three to be large enough.
 *
 * Time: O(m * n)   Space: O(m * n)
 */
#include <bits/stdc++.h>
using namespace std;

int maximalSquare(const vector<vector<char> >& matrix) {
    int m = matrix.size(), n = matrix[0].size(), best = 0;
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                best = max(best, dp[i][j]);
            }
    return best * best;
}

int main() {
    vector<string> raw = {"10100", "10111", "11111", "10010"};
    vector<vector<char> > m;
    for (const string& row : raw) m.push_back(vector<char>(row.begin(), row.end()));
    cout << maximalSquare(m) << "\n";   // 4
    return 0;
}
