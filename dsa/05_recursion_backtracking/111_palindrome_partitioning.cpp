/*
 * 111. Palindrome Partitioning
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * Partition a string so every piece is a palindrome, and return all such
 * partitions.
 *
 * Approach: backtrack over cut positions. From index `start`, try every prefix
 * that is a palindrome, recurse on the remainder, then undo. A precomputed
 * isPal[i][j] table makes each palindrome test O(1).
 *
 * Time: O(n * 2^n)   Space: O(n^2) for the table
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(const string& s, int start, const vector<vector<bool>>& isPal,
                vector<string>& cur, vector<vector<string>>& out) {
    if (start == (int)s.size()) { out.push_back(cur); return; }
    for (int end = start; end < (int)s.size(); ++end) {
        if (!isPal[start][end]) continue;
        cur.push_back(s.substr(start, end - start + 1));
        dfs(s, end + 1, isPal, cur, out);
        cur.pop_back();
    }
}

vector<vector<string>> partition(const string& s) {
    int n = s.size();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; --i)
        for (int j = i; j < n; ++j)
            isPal[i][j] = (s[i] == s[j]) && (j - i < 2 || isPal[i + 1][j - 1]);

    vector<string> cur;
    vector<vector<string>> out;
    dfs(s, 0, isPal, cur, out);
    return out;
}

int main() {
    for (const auto& p : partition("aab")) {
        cout << "[";
        for (const string& piece : p) cout << piece << " ";
        cout << "] ";
    }
    cout << "\n";   // [a a b] [aa b]
    return 0;
}
