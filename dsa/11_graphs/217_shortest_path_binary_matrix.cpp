/*
 * 217. Shortest Path in Binary Matrix
 * Topic: Graphs | Difficulty: Medium
 *
 * Find the length of the shortest clear path from the top-left to the
 * bottom-right of a binary grid, moving in any of the 8 directions.
 *
 * Approach: plain BFS. All moves cost 1, so the first time BFS reaches the
 * target it has done so along a shortest path - no priority queue needed. Cells
 * are marked blocked when enqueued to prevent re-visits.
 *
 * Time: O(n^2)   Space: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int> > grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    grid[0][0] = 1;                                 // mark as used
    int dist = 1;
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            if (r == n - 1 && c == n - 1) return dist;
            for (int dr = -1; dr <= 1; ++dr)
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 && dc == 0) continue;
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                    if (grid[nr][nc] != 0) continue;
                    grid[nr][nc] = 1;
                    q.push(make_pair(nr, nc));
                }
        }
        ++dist;
    }
    return -1;
}

int main() {
    cout << shortestPathBinaryMatrix({{0, 1}, {1, 0}}) << "\n";                  // 2
    cout << shortestPathBinaryMatrix({{0, 0, 0}, {1, 1, 0}, {1, 1, 0}}) << "\n"; // 4
    cout << shortestPathBinaryMatrix({{1, 0, 0}, {1, 1, 0}, {1, 1, 0}}) << "\n"; // -1
    return 0;
}
