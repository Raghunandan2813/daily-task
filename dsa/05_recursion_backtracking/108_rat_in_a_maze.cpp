/*
 * 108. Rat in a Maze
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * A rat starts at (0,0) of an n x n grid where 1 means open and 0 means blocked.
 * Print every path to (n-1,n-1) using the moves D, L, R, U.
 *
 * Approach: DFS trying the four directions in lexicographic order so the paths
 * come out sorted. A visited grid stops the rat from looping back on itself, and
 * the mark is cleared on the way out.
 *
 * Time: O(4^(n*n)) worst case   Space: O(n*n)
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(const vector<vector<int>>& m, vector<vector<bool>>& seen,
                int r, int c, string& path, vector<string>& out) {
    int n = m.size();
    if (r == n - 1 && c == n - 1) { out.push_back(path); return; }

    const int dr[] = {1, 0, 0, -1};
    const int dc[] = {0, -1, 1, 0};
    const char dir[] = {'D', 'L', 'R', 'U'};        // lexicographic order
    for (int k = 0; k < 4; ++k) {
        int nr = r + dr[k], nc = c + dc[k];
        if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
        if (seen[nr][nc] || m[nr][nc] == 0) continue;
        seen[nr][nc] = true;
        path.push_back(dir[k]);
        dfs(m, seen, nr, nc, path, out);
        path.pop_back();
        seen[nr][nc] = false;
    }
}

vector<string> findPaths(const vector<vector<int>>& m) {
    vector<string> out;
    if (m.empty() || m[0][0] == 0) return out;
    vector<vector<bool>> seen(m.size(), vector<bool>(m.size(), false));
    seen[0][0] = true;
    string path;
    dfs(m, seen, 0, 0, path, out);
    return out;
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    for (const string& p : findPaths(maze)) cout << p << " ";
    cout << "\n";   // DDRDRR DRDDRR
    return 0;
}
