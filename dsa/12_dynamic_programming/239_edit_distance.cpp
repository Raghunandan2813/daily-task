/*
 * 239. Edit Distance (Levenshtein)
 * Topic: Dynamic Programming | Difficulty: Hard
 *
 * Find the minimum number of insertions, deletions and substitutions turning one
 * string into another.
 *
 * Approach: dp[i][j] is the distance between the prefixes of length i and j.
 * Matching characters cost nothing and inherit the diagonal; otherwise take one
 * plus the cheapest of delete (dp[i-1][j]), insert (dp[i][j-1]) or replace
 * (dp[i-1][j-1]). The first row and column are the base cases - the cost of
 * building a string from nothing.
 *
 * Time: O(n * m)   Space: O(n * m)
 */
#include <bits/stdc++.h>
using namespace std;

int minDistance(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 0; j <= m; ++j) dp[0][j] = j;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = (a[i - 1] == b[j - 1])
                ? dp[i - 1][j - 1]
                : 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
    return dp[n][m];
}

int main() {
    cout << minDistance("horse", "ros") << "\n";              // 3
    cout << minDistance("intention", "execution") << "\n";    // 5
    return 0;
}
