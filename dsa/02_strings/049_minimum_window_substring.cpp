/*
 * 049. Minimum Window Substring
 * Topic: Strings | Difficulty: Hard
 *
 * Find the shortest substring of s containing every character of t including
 * multiplicities. Return "" if none exists.
 *
 * Approach: sliding window with a need table. `missing` counts how many required
 * characters are still unmatched; when it hits zero the window is valid and we
 * shrink it from the left as far as it stays valid.
 *
 * Time: O(n + m)   Space: O(1) - 128 ASCII slots
 */
#include <bits/stdc++.h>
using namespace std;

string minWindow(const string& s, const string& t) {
    if (t.empty() || s.size() < t.size()) return "";
    vector<int> need(128, 0);
    for (char c : t) ++need[(unsigned char)c];
    int missing = t.size(), left = 0, bestLen = INT_MAX, bestStart = 0;
    for (int right = 0; right < (int)s.size(); ++right) {
        if (need[(unsigned char)s[right]]-- > 0) --missing;
        while (missing == 0) {
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }
            if (++need[(unsigned char)s[left]] > 0) ++missing;
            ++left;
        }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << "\n";   // BANC
    cout << "[" << minWindow("a", "aa") << "]\n";        // []
    return 0;
}
