/*
 * 039. Longest Substring Without Repeating Characters
 * Topic: Strings | Difficulty: Medium
 *
 * Find the length of the longest substring containing no repeated character.
 *
 * Approach: sliding window with a last-seen index per character. When the
 * character at `right` was already seen inside the current window, jump the left
 * edge just past that previous occurrence.
 *
 * Time: O(n)   Space: O(1) - 128 ASCII slots
 */
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(const string& s) {
    vector<int> lastSeen(128, -1);
    int left = 0, best = 0;
    for (int right = 0; right < (int)s.size(); ++right) {
        int c = (unsigned char)s[right];
        if (lastSeen[c] >= left) left = lastSeen[c] + 1;
        lastSeen[c] = right;
        best = max(best, right - left + 1);
    }
    return best;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << "\n";   // 3
    cout << lengthOfLongestSubstring("bbbbb") << "\n";      // 1
    cout << lengthOfLongestSubstring("pwwkew") << "\n";     // 3
    return 0;
}
