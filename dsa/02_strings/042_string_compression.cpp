/*
 * 042. String Compression (Run-Length Encoding)
 * Topic: Strings | Difficulty: Medium
 *
 * Compress a string by replacing each run of repeated characters with the
 * character followed by the run length (lengths of 1 are omitted).
 *
 * Approach: single scan. Extend a run while the next character matches, then
 * emit the character and, when the run is longer than one, its length.
 *
 * Time: O(n)   Space: O(n) for the output
 */
#include <bits/stdc++.h>
using namespace std;

string compress(const string& s) {
    string out;
    int i = 0, n = s.size();
    while (i < n) {
        int j = i;
        while (j < n && s[j] == s[i]) ++j;
        out += s[i];
        if (j - i > 1) out += to_string(j - i);
        i = j;
    }
    return out;
}

int main() {
    cout << compress("aabcccccaaa") << "\n";   // a2bc5a3
    cout << compress("abc") << "\n";           // abc
    return 0;
}
