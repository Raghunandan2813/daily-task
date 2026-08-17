/*
 * 256. Wildcard Pattern Matching
 * Topic: Dynamic Programming | Difficulty: Hard
 *
 * Match a string against a pattern where '?' matches any single character and
 * '*' matches any sequence, including the empty one.
 *
 * Approach: dp[i][j] says whether the first i characters of s match the first j
 * of p. A literal or '?' consumes one character from each. A '*' either matches
 * nothing (dp[i][j-1]) or absorbs one more character (dp[i-1][j]) - that pair of
 * options is the whole trick. The base row handles a pattern of leading stars
 * matching the empty string.
 *
 * Time: O(n * m)   Space: O(n * m)
 */
#include <bits/stdc++.h>
using namespace std;

bool isMatch(const string& s, const string& p) {
    int n = s.size(), m = p.size();
    vector<vector<char> > dp(n + 1, vector<char>(m + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; ++j)
        if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (p[j - 1] == '*') dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) dp[i][j] = dp[i - 1][j - 1];
        }
    return dp[n][m] != 0;
}

int main() {
    cout << isMatch("aa", "a") << "\n";        // 0
    cout << isMatch("aa", "*") << "\n";        // 1
    cout << isMatch("cb", "?a") << "\n";       // 0
    cout << isMatch("adceb", "*a*b") << "\n";  // 1
    return 0;
}
