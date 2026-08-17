/*
 * 270. Partition Labels
 * Topic: Greedy | Difficulty: Medium
 *
 * Split a string into as many parts as possible so that each letter appears in
 * at most one part.
 *
 * Approach: record the last index of every letter, then sweep while extending
 * the current part's end to the furthest last-occurrence seen so far. When the
 * scan position reaches that end, no letter inside the part appears later, so it
 * can be closed.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(const string& s) {
    vector<int> lastIndex(26, 0);
    for (int i = 0; i < (int)s.size(); ++i) lastIndex[s[i] - 'a'] = i;

    vector<int> sizes;
    int start = 0, end = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        end = max(end, lastIndex[s[i] - 'a']);
        if (i == end) { sizes.push_back(end - start + 1); start = i + 1; }
    }
    return sizes;
}

int main() {
    for (int n : partitionLabels("ababcbacadefegdehijhklij")) cout << n << " ";
    cout << "\n";   // 9 7 8
    return 0;
}
