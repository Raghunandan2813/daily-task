/*
 * 106. Sudoku Solver
 * Topic: Recursion & Backtracking | Difficulty: Hard
 *
 * Fill a partially completed 9x9 Sudoku grid so every row, column and 3x3 box
 * contains the digits 1-9 exactly once.
 *
 * Approach: find the first empty cell, try each digit that does not conflict,
 * recurse, and undo on failure. Returning a bool lets the first complete
 * solution unwind the whole recursion immediately.
 *
 * Time: exponential worst case, fast in practice   Space: O(1) beyond recursion
 */
#include <bits/stdc++.h>
using namespace std;

static bool canPlace(const vector<vector<char>>& b, int r, int c, char v) {
    int br = (r / 3) * 3, bc = (c / 3) * 3;
    for (int i = 0; i < 9; ++i) {
        if (b[r][i] == v || b[i][c] == v) return false;
        if (b[br + i / 3][bc + i % 3] == v) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& b) {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (b[r][c] != '.') continue;
            for (char v = '1'; v <= '9'; ++v) {
                if (!canPlace(b, r, c, v)) continue;
                b[r][c] = v;
                if (solve(b)) return true;
                b[r][c] = '.';
            }
            return false;                            // no digit fits here
        }
    }
    return true;                                     // no empty cells left
}

int main() {
    vector<string> raw = {
        "53..7....", "6..195...", ".98....6.",
        "8...6...3", "4..8.3..1", "7...2...6",
        ".6....28.", "...419..5", "....8..79"};
    vector<vector<char>> board;
    for (const string& row : raw) board.push_back(vector<char>(row.begin(), row.end()));
    solve(board);
    for (const auto& row : board) {
        for (char ch : row) cout << ch;
        cout << "\n";
    }
    // first row: 534678912
    return 0;
}
