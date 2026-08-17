/*
 * 238. Longest Common Substring
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Find the length of the longest *contiguous* run of characters shared by two
 * strings.
 *
 * Approach: dp[i][j] is the length of the common suffix ending at a[i-1] and
 * b[j-1]. Unlike the subsequence version, a mismatch resets the cell to zero -
 * that reset is exactly what enforces contiguity. The answer is the largest cell
 * anywhere in the table, not dp[n][m].
 *
 * Time: O(n * m)   Space: O(n * m)
 */
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(const string& a, const string& b) {
    int n = a.size(), m = b.size(), best = 0;
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                best = max(best, dp[i][j]);
            }                                        // else it stays 0
    return best;
}

int main() {
    cout << longestCommonSubstring("abcde", "abfce") << "\n";   // 2
    cout << longestCommonSubstring("GeeksforGeeks", "GeeksQuiz") << "\n";   // 5
    return 0;
}
