/*
 * 058. Rabin-Karp Substring Search
 * Topic: Strings | Difficulty: Medium
 *
 * Find all occurrences of a pattern using rolling hashes.
 *
 * Approach: hash the pattern and each window of the text with a polynomial hash
 * that can be rolled in O(1) - drop the leading character, shift, add the new
 * one. On a hash match, verify with a direct comparison to rule out collisions.
 *
 * Time: O(n + m) expected, O(n * m) worst case   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> rabinKarp(const string& text, const string& pat) {
    const long long BASE = 256, MOD = 1000000007LL;
    int n = text.size(), m = pat.size();
    vector<int> hits;
    if (m == 0 || m > n) return hits;

    long long high = 1;                       // BASE^(m-1) % MOD
    for (int i = 0; i < m - 1; ++i) high = high * BASE % MOD;

    long long patHash = 0, winHash = 0;
    for (int i = 0; i < m; ++i) {
        patHash = (patHash * BASE + (unsigned char)pat[i]) % MOD;
        winHash = (winHash * BASE + (unsigned char)text[i]) % MOD;
    }
    for (int i = 0; i + m <= n; ++i) {
        if (patHash == winHash && text.compare(i, m, pat) == 0) hits.push_back(i);
        if (i + m < n) {
            winHash = (winHash - (unsigned char)text[i] * high % MOD + MOD) % MOD;
            winHash = (winHash * BASE + (unsigned char)text[i + m]) % MOD;
        }
    }
    return hits;
}

int main() {
    for (int i : rabinKarp("GEEKS FOR GEEKS", "GEEK")) cout << i << " ";
    cout << "\n";   // 0 10
    return 0;
}
