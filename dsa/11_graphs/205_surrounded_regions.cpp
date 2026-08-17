/*
 * 205. Surrounded Regions
 * Topic: Graphs | Difficulty: Medium
 *
 * Capture every region of 'O' that is fully surrounded by 'X' by flipping it to
 * 'X'. Regions touching the border survive.
 *
 * Approach: invert the problem. Instead of testing each region for enclosure,
 * flood-fill inward from every border 'O' and mark those as safe; everything
 * still marked 'O' afterwards must be surrounded.
 *
 * Time: O(m * n)   Space: O(m * n)
 */
#include <bits/stdc++.h>
using namespace std;

static void markSafe(vector<vector<char> >& b, int r, int c) {
    if (r < 0 || c < 0 || r >= (int)b.size() || c >= (int)b[0].size()) return;
    if (b[r][c] != 'O') return;
    b[r][c] = 'S';                                    // safe
    markSafe(b, r + 1, c);
    markSafe(b, r - 1, c);
    markSafe(b, r, c + 1);
    markSafe(b, r, c - 1);
}

void solve(vector<vector<char> >& board) {
    if (board.empty()) return;
    int m = board.size(), n = board[0].size();
    for (int r = 0; r < m; ++r) { markSafe(board, r, 0); markSafe(board, r, n - 1); }
    for (int c = 0; c < n; ++c) { markSafe(board, 0, c); markSafe(board, m - 1, c); }
    for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
            board[r][c] = (board[r][c] == 'S') ? 'O' : 'X';
}

int main() {
    vector<string> raw = {"XXXX", "XOOX", "XXOX", "XOXX"};
    vector<vector<char> > b;
    for (const string& row : raw) b.push_back(vector<char>(row.begin(), row.end()));
    solve(b);
    for (const auto& row : b) {
        for (char ch : row) cout << ch;
        cout << "\n";
    }
    // XXXX / XXXX / XXXX / XOXX
    return 0;
}
