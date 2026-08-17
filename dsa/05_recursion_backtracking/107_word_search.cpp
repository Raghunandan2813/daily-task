/*
 * 107. Word Search
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * Decide whether a word can be spelled by walking through adjacent cells of a
 * grid without reusing a cell.
 *
 * Approach: DFS from every cell that matches the first letter. The visited mark
 * is written directly into the board (temporarily blanking the cell) and undone
 * on the way out, so no separate visited grid is needed.
 *
 * Time: O(m * n * 4^L) for a word of length L   Space: O(L) recursion
 */
#include <bits/stdc++.h>
using namespace std;

static bool dfs(vector<vector<char>>& b, const string& w, int r, int c, int k) {
    if (k == (int)w.size()) return true;
    if (r < 0 || c < 0 || r >= (int)b.size() || c >= (int)b[0].size()) return false;
    if (b[r][c] != w[k]) return false;

    char saved = b[r][c];
    b[r][c] = '#';                                   // mark as visited
    bool found = dfs(b, w, r + 1, c, k + 1) || dfs(b, w, r - 1, c, k + 1) ||
                 dfs(b, w, r, c + 1, k + 1) || dfs(b, w, r, c - 1, k + 1);
    b[r][c] = saved;
    return found;
}

bool exist(vector<vector<char>> board, const string& word) {
    for (int r = 0; r < (int)board.size(); ++r)
        for (int c = 0; c < (int)board[0].size(); ++c)
            if (dfs(board, word, r, c, 0)) return true;
    return false;
}

int main() {
    vector<vector<char>> b = {{'A', 'B', 'C', 'E'},
                              {'S', 'F', 'C', 'S'},
                              {'A', 'D', 'E', 'E'}};
    cout << exist(b, "ABCCED") << "\n";   // 1
    cout << exist(b, "SEE") << "\n";      // 1
    cout << exist(b, "ABCB") << "\n";     // 0
    return 0;
}
