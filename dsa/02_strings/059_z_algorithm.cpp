/*
 * 059. Z-Algorithm Pattern Search
 * Topic: Strings | Difficulty: Hard
 *
 * Compute the Z-array of a string (z[i] = length of the longest substring
 * starting at i that is also a prefix) and use it for pattern matching.
 *
 * Approach: maintain the rightmost known prefix-match window [l, r]. Inside that
 * window a previously computed value can be reused as a starting guess, so the
 * total work stays linear.
 *
 * Time: O(n + m)   Space: O(n + m)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> zArray(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

vector<int> zSearch(const string& text, const string& pat) {
    string combined = pat + '\x01' + text;
    vector<int> z = zArray(combined), hits;
    int m = pat.size();
    for (int i = m + 1; i < (int)combined.size(); ++i)
        if (z[i] == m) hits.push_back(i - m - 1);
    return hits;
}

int main() {
    for (int i : zSearch("aabxaabxcaabxaabxay", "aabxa")) cout << i << " ";
    cout << "\n";   // 0 4 9 13
    return 0;
}
