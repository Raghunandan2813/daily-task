/*
 * 109. Generate Parentheses
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * Generate all well-formed strings of n pairs of parentheses.
 *
 * Approach: build the string one character at a time. An opening bracket is
 * legal while fewer than n have been used; a closing bracket is legal only while
 * it would not outnumber the open ones. That invariant means every string
 * produced is already valid - no filtering pass is needed.
 *
 * Time: O(4^n / sqrt(n)) - the Catalan number of results   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(int open, int close, int n, string& cur, vector<string>& out) {
    if ((int)cur.size() == 2 * n) { out.push_back(cur); return; }
    if (open < n) {
        cur.push_back('(');
        dfs(open + 1, close, n, cur, out);
        cur.pop_back();
    }
    if (close < open) {
        cur.push_back(')');
        dfs(open, close + 1, n, cur, out);
        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> out;
    string cur;
    dfs(0, 0, n, cur, out);
    return out;
}

int main() {
    for (const string& s : generateParenthesis(3)) cout << s << " ";
    cout << "\n";   // ((())) (()()) (())() ()(()) ()()()
    return 0;
}
