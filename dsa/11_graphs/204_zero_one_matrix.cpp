/*
 * 204. 01 Matrix (Distance to Nearest Zero)
 * Topic: Graphs | Difficulty: Medium
 *
 * For each cell, report the distance to the nearest cell containing 0.
 *
 * Approach: multi-source BFS seeded with every zero cell at distance 0. Running
 * outward from all zeros at once settles each cell at its true minimum on first
 * visit - far simpler than a BFS per cell, which would be O((m*n)^2).
 *
 * Time: O(m * n)   Space: O(m * n)
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > updateMatrix(const vector<vector<int> >& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int> > dist(m, vector<int>(n, -1));
    queue<pair<int, int> > q;
    for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
            if (mat[r][c] == 0) { dist[r][c] = 0; q.push(make_pair(r, c)); }

    const int dr[] = {1, -1, 0, 0};
    const int dc[] = {0, 0, 1, -1};
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (dist[nr][nc] != -1) continue;          // already settled
            dist[nr][nc] = dist[r][c] + 1;
            q.push(make_pair(nr, nc));
        }
    }
    return dist;
}

int main() {
    vector<vector<int> > mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    for (const auto& row : updateMatrix(mat)) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    // 0 0 0 / 0 1 0 / 1 2 1
    return 0;
}
