/*
 * 105. N-Queens
 * Topic: Recursion & Backtracking | Difficulty: Hard
 *
 * Place N queens on an N x N board so that none attack another. Return every
 * distinct arrangement.
 *
 * Approach: place one queen per row. Three boolean arrays mark the columns and
 * the two diagonal families already under attack, giving O(1) safety checks. The
 * diagonals are indexed by (row + col) and (row - col + n - 1).
 *
 * Time: O(n!) in the worst case   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(int row, int n, vector<int>& pos, vector<bool>& col,
                vector<bool>& diag, vector<bool>& anti,
                vector<vector<string>>& out) {
    if (row == n) {
        vector<string> board(n, string(n, '.'));
        for (int r = 0; r < n; ++r) board[r][pos[r]] = 'Q';
        out.push_back(board);
        return;
    }
    for (int c = 0; c < n; ++c) {
        int d = row + c, a = row - c + n - 1;
        if (col[c] || diag[d] || anti[a]) continue;
        col[c] = diag[d] = anti[a] = true;
        pos[row] = c;
        dfs(row + 1, n, pos, col, diag, anti, out);
        col[c] = diag[d] = anti[a] = false;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> out;
    vector<int> pos(n);
    vector<bool> col(n, false), diag(2 * n, false), anti(2 * n, false);
    dfs(0, n, pos, col, diag, anti, out);
    return out;
}

int main() {
    vector<vector<string>> sols = solveNQueens(4);
    cout << "solutions: " << sols.size() << "\n";   // 2
    for (const string& row : sols[0]) cout << row << "\n";
    // .Q.. / ...Q / Q... / ..Q.
    return 0;
}
