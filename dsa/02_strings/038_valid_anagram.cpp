/*
 * 038. Valid Anagram
 * Topic: Strings | Difficulty: Easy
 *
 * Decide whether two strings are anagrams of each other.
 *
 * Approach: count characters of the first string in a 26-slot table and subtract
 * the counts of the second. The strings are anagrams iff every counter returns
 * to zero (lengths must also match).
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(const string& s, const string& t) {
    if (s.size() != t.size()) return false;
    int count[26] = {0};
    for (int i = 0; i < (int)s.size(); ++i) {
        ++count[s[i] - 'a'];
        --count[t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) if (count[i] != 0) return false;
    return true;
}

int main() {
    cout << isAnagram("anagram", "nagaram") << "\n";   // 1
    cout << isAnagram("rat", "car") << "\n";           // 0
    return 0;
}
