/*
 * 257. Distinct Subsequences
 * Topic: Dynamic Programming | Difficulty: Hard
 *
 * Count how many distinct subsequences of s equal the string t.
 *
 * Approach: dp[i][j] counts the ways the first i characters of s can produce the
 * first j of t. When the characters match we may either use this character of s
 * (dp[i-1][j-1]) or skip it (dp[i-1][j]), so the two counts add. When they do
 * not match, skipping is the only option. dp[i][0] = 1 because the empty target
 * is always matched exactly once.
 *
 * Time: O(n * m)   Space: O(m)
 */
#include <bits/stdc++.h>
using namespace std;

long long numDistinct(const string& s, const string& t) {
    int m = t.size();
    vector<long long> dp(m + 1, 0);
    dp[0] = 1;                                       // the empty target
    for (int i = 1; i <= (int)s.size(); ++i)
        for (int j = m; j >= 1; --j)                 // backwards: dp[j-1] stays old
            if (s[i - 1] == t[j - 1]) dp[j] += dp[j - 1];
    return dp[m];
}

int main() {
    cout << numDistinct("rabbbit", "rabbit") << "\n";   // 3
    cout << numDistinct("babgbag", "bag") << "\n";      // 5
    return 0;
}
