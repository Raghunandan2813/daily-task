/*
 * 050. Permutation in String
 * Topic: Strings | Difficulty: Medium
 *
 * Decide whether s2 contains any permutation of s1 as a substring.
 *
 * Approach: fixed-size sliding window of length |s1| over s2, comparing
 * character-frequency tables. A `matches` counter tracks how many of the 26
 * letters currently agree, so each slide costs O(1) instead of O(26).
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(const string& s1, const string& s2) {
    int n = s1.size(), m = s2.size();
    if (n > m) return false;
    vector<int> need(26, 0), window(26, 0);
    for (int i = 0; i < n; ++i) {
        ++need[s1[i] - 'a'];
        ++window[s2[i] - 'a'];
    }
    int matches = 0;
    for (int i = 0; i < 26; ++i) if (need[i] == window[i]) ++matches;
    for (int right = n; right < m; ++right) {
        if (matches == 26) return true;
        int in = s2[right] - 'a', out = s2[right - n] - 'a';
        if (window[in]++ == need[in]) --matches;
        else if (window[in] == need[in]) ++matches;
        if (window[out]-- == need[out]) --matches;
        else if (window[out] == need[out]) ++matches;
    }
    return matches == 26;
}

int main() {
    cout << checkInclusion("ab", "eidbaooo") << "\n";   // 1
    cout << checkInclusion("ab", "eidboaoo") << "\n";   // 0
    return 0;
}
