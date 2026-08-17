/*
 * 243. Palindrome Partitioning II (Minimum Cuts)
 * Topic: Dynamic Programming | Difficulty: Hard
 *
 * Find the fewest cuts needed to split a string into palindromic pieces.
 *
 * Approach: precompute isPal[i][j] in O(n^2), then let cuts[i] be the minimum
 * cuts for the prefix ending at i. If the whole prefix is a palindrome the
 * answer is 0; otherwise try every j where s[j..i] is a palindrome and take
 * cuts[j-1] + 1. The precomputed table keeps each check O(1).
 *
 * Time: O(n^2)   Space: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;

int minCut(const string& s) {
    int n = s.size();
    if (n <= 1) return 0;
    vector<vector<bool> > isPal(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; --i)
        for (int j = i; j < n; ++j)
            isPal[i][j] = (s[i] == s[j]) && (j - i < 2 || isPal[i + 1][j - 1]);

    vector<int> cuts(n, 0);
    for (int i = 0; i < n; ++i) {
        if (isPal[0][i]) { cuts[i] = 0; continue; }
        cuts[i] = INT_MAX;
        for (int j = 1; j <= i; ++j)
            if (isPal[j][i]) cuts[i] = min(cuts[i], cuts[j - 1] + 1);
    }
    return cuts[n - 1];
}

int main() {
    cout << minCut("aab") << "\n";     // 1
    cout << minCut("a") << "\n";       // 0
    cout << minCut("abcde") << "\n";   // 4
    return 0;
}
