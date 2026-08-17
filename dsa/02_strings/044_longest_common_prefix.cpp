/*
 * 044. Longest Common Prefix
 * Topic: Strings | Difficulty: Easy
 *
 * Find the longest common prefix shared by every string in an array.
 *
 * Approach: start with the first string as the candidate prefix and shorten it
 * against each subsequent string until it is a prefix of that string too.
 *
 * Time: O(total characters)   Space: O(1) extra
 */
#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(const vector<string>& v) {
    if (v.empty()) return "";
    string prefix = v[0];
    for (int i = 1; i < (int)v.size(); ++i) {
        int j = 0;
        while (j < (int)prefix.size() && j < (int)v[i].size() && prefix[j] == v[i][j]) ++j;
        prefix.resize(j);
        if (prefix.empty()) break;
    }
    return prefix;
}

int main() {
    cout << "[" << longestCommonPrefix({"flower", "flow", "flight"}) << "]\n";   // [fl]
    cout << "[" << longestCommonPrefix({"dog", "racecar", "car"}) << "]\n";      // []
    return 0;
}
