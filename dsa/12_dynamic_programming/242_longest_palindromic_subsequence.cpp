/*
 * 242. Longest Palindromic Subsequence
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Find the length of the longest subsequence that reads the same both ways.
 *
 * Approach: a palindrome reads identically forwards and backwards, so the
 * longest palindromic subsequence of s is exactly the longest common subsequence
 * of s and its reverse. That reduction reuses the LCS table with no new
 * recurrence.
 *
 * Time: O(n^2)   Space: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubseq(const string& s) {
    string r(s.rbegin(), s.rend());
    int n = s.size();
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = (s[i - 1] == r[j - 1]) ? dp[i - 1][j - 1] + 1
                                              : max(dp[i - 1][j], dp[i][j - 1]);
    return dp[n][n];
}

int main() {
    cout << longestPalindromeSubseq("bbbab") << "\n";   // 4
    cout << longestPalindromeSubseq("cbbd") << "\n";    // 2
    return 0;
}
