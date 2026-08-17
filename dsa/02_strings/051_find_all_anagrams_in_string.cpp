/*
 * 051. Find All Anagrams in a String
 * Topic: Strings | Difficulty: Medium
 *
 * Return the start indices of every substring of s that is an anagram of p.
 *
 * Approach: fixed-size sliding window of length |p| with a difference table. A
 * counter of how many letters currently match lets each slide run in O(1).
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(const string& s, const string& p) {
    vector<int> out;
    int n = p.size(), m = s.size();
    if (n > m) return out;
    vector<int> need(26, 0), window(26, 0);
    for (int i = 0; i < n; ++i) {
        ++need[p[i] - 'a'];
        ++window[s[i] - 'a'];
    }
    if (need == window) out.push_back(0);
    for (int right = n; right < m; ++right) {
        ++window[s[right] - 'a'];
        --window[s[right - n] - 'a'];
        if (need == window) out.push_back(right - n + 1);
    }
    return out;
}

int main() {
    for (int i : findAnagrams("cbaebabacd", "abc")) cout << i << " ";
    cout << "\n";   // 0 6
    for (int i : findAnagrams("abab", "ab")) cout << i << " ";
    cout << "\n";   // 0 1 2
    return 0;
}
