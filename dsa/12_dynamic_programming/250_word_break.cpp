/*
 * 250. Word Break
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Decide whether a string can be segmented into a sequence of dictionary words.
 *
 * Approach: dp[i] records whether the first i characters can be segmented. For
 * each i, look for a split point j where the prefix is segmentable and the
 * remaining piece s[j..i) is a dictionary word. A hash set makes each lookup
 * O(1) on average.
 *
 * Time: O(n^2) substring checks   Space: O(n + dictionary)
 */
#include <bits/stdc++.h>
using namespace std;

bool wordBreak(const string& s, const vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<char> dp(n + 1, false);
    dp[0] = true;                                    // the empty prefix
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            if (dp[j] && dict.count(s.substr(j, i - j))) { dp[i] = true; break; }
    return dp[n];
}

int main() {
    cout << wordBreak("leetcode", {"leet", "code"}) << "\n";               // 1
    cout << wordBreak("applepenapple", {"apple", "pen"}) << "\n";          // 1
    cout << wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) << "\n";   // 0
    return 0;
}
