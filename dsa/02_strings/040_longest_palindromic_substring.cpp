/*
 * 040. Longest Palindromic Substring
 * Topic: Strings | Difficulty: Medium
 *
 * Return the longest substring that reads the same forwards and backwards.
 *
 * Approach: expand around centres. Every palindrome has a centre that is either
 * a character (odd length) or a gap between two characters (even length), giving
 * 2n-1 centres to try.
 *
 * Time: O(n^2)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static int expand(const string& s, int lo, int hi) {
    while (lo >= 0 && hi < (int)s.size() && s[lo] == s[hi]) { --lo; ++hi; }
    return hi - lo - 1;                       // length of the palindrome found
}

string longestPalindrome(const string& s) {
    if (s.empty()) return "";
    int start = 0, best = 1;
    for (int i = 0; i < (int)s.size(); ++i) {
        int len = max(expand(s, i, i), expand(s, i, i + 1));
        if (len > best) {
            best = len;
            start = i - (len - 1) / 2;
        }
    }
    return s.substr(start, best);
}

int main() {
    cout << longestPalindrome("babad") << "\n";   // bab (aba also valid)
    cout << longestPalindrome("cbbd") << "\n";    // bb
    return 0;
}
