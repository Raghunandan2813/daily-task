/*
 * 056. Longest Repeating Character Replacement
 * Topic: Strings | Difficulty: Medium
 *
 * You may change at most k characters. Return the length of the longest
 * substring that can be made to contain a single repeated letter.
 *
 * Approach: sliding window. A window is valid when
 * (length - count of its most frequent letter) <= k, i.e. the letters we would
 * have to overwrite fit within the budget. Grow right, and advance left whenever
 * the window becomes invalid.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int characterReplacement(const string& s, int k) {
    vector<int> count(26, 0);
    int left = 0, maxCount = 0, best = 0;
    for (int right = 0; right < (int)s.size(); ++right) {
        maxCount = max(maxCount, ++count[s[right] - 'A']);
        while (right - left + 1 - maxCount > k) {
            --count[s[left] - 'A'];
            ++left;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

int main() {
    cout << characterReplacement("ABAB", 2) << "\n";     // 4
    cout << characterReplacement("AABABBA", 1) << "\n";  // 4
    return 0;
}
