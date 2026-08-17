/*
 * 237. Longest Common Subsequence
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Find the length of the longest subsequence present in both strings (characters
 * in order, not necessarily contiguous).
 *
 * Approach: dp[i][j] is the LCS length of the first i characters of a and first
 * j of b. Matching characters extend the diagonal answer by one; otherwise the
 * best is whichever string we drop a character from. The table is also what
 * powers edit distance and diff tools.
 *
 * Time: O(n * m)   Space: O(n * m)
 */
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = (a[i - 1] == b[j - 1]) ? dp[i - 1][j - 1] + 1
                                              : max(dp[i - 1][j], dp[i][j - 1]);
    return dp[n][m];
}

int main() {
    cout << longestCommonSubsequence("abcde", "ace") << "\n";   // 3
    cout << longestCommonSubsequence("abc", "def") << "\n";     // 0
    return 0;
}
