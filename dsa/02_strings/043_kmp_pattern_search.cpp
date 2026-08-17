/*
 * 043. KMP Pattern Searching
 * Topic: Strings | Difficulty: Hard
 *
 * Find every occurrence of a pattern inside a text in linear time.
 *
 * Approach: Knuth-Morris-Pratt. Precompute the LPS array, where lps[i] is the
 * length of the longest proper prefix of pattern[0..i] that is also a suffix.
 * On a mismatch, fall back to lps[j-1] instead of restarting, so the text
 * pointer never moves backwards.
 *
 * Time: O(n + m)   Space: O(m)
 */
#include <bits/stdc++.h>
using namespace std;

static vector<int> buildLPS(const string& p) {
    vector<int> lps(p.size(), 0);
    int len = 0;
    for (int i = 1; i < (int)p.size(); ) {
        if (p[i] == p[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

vector<int> kmpSearch(const string& text, const string& pat) {
    vector<int> hits;
    if (pat.empty()) return hits;
    vector<int> lps = buildLPS(pat);
    int i = 0, j = 0;
    while (i < (int)text.size()) {
        if (text[i] == pat[j]) {
            ++i; ++j;
            if (j == (int)pat.size()) { hits.push_back(i - j); j = lps[j - 1]; }
        } else if (j) j = lps[j - 1];
        else ++i;
    }
    return hits;
}

int main() {
    for (int idx : kmpSearch("ababcabcabababd", "ababd")) cout << idx << " ";
    cout << "\n";   // 10
    for (int idx : kmpSearch("aaaaa", "aa")) cout << idx << " ";
    cout << "\n";   // 0 1 2 3
    return 0;
}
