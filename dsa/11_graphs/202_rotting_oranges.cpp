/*
 * 202. Rotting Oranges
 * Topic: Graphs | Difficulty: Medium
 *
 * Rotten oranges (2) spoil adjacent fresh ones (1) each minute. Return the
 * minutes until none are fresh, or -1 if that is impossible.
 *
 * Approach: multi-source BFS seeded with every initially rotten orange. Because
 * all sources start at time zero, each BFS layer corresponds to one minute. A
 * fresh counter detects unreachable oranges at the end.
 *
 * Time: O(m * n)   Space: O(m * n)
 */
#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int> > grid) {
    int m = grid.size(), n = grid[0].size(), fresh = 0;
    queue<pair<int, int> > q;
    for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] == 2) q.push(make_pair(r, c));
            else if (grid[r][c] == 1) ++fresh;
        }
    if (fresh == 0) return 0;

    const int dr[] = {1, -1, 0, 0};
    const int dc[] = {0, 0, 1, -1};
    int minutes = 0;
    while (!q.empty() && fresh > 0) {
        int levelSize = q.size();
        ++minutes;
        for (int i = 0; i < levelSize; ++i) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if (grid[nr][nc] != 1) continue;
                grid[nr][nc] = 2;
                --fresh;
                q.push(make_pair(nr, nc));
            }
        }
    }
    return fresh == 0 ? minutes : -1;
}

int main() {
    cout << orangesRotting({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}) << "\n";   // 4
    cout << orangesRotting({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}) << "\n";   // -1
    cout << orangesRotting({{0, 2}}) << "\n";                            // 0
    return 0;
}
