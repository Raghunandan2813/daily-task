/*
 * 201. Number of Islands
 * Topic: Graphs | Difficulty: Medium
 *
 * Count the connected groups of land cells ('1') in a grid, where cells connect
 * horizontally and vertically.
 *
 * Approach: scan the grid; each time an unvisited land cell is found, increment
 * the count and flood-fill its whole component so it is never counted again.
 * Sinking the land in place (writing '0') avoids a separate visited grid.
 *
 * Time: O(m * n)   Space: O(m * n) recursion worst case
 */
#include <bits/stdc++.h>
using namespace std;

static void sink(vector<vector<char> >& grid, int r, int c) {
    if (r < 0 || c < 0 || r >= (int)grid.size() || c >= (int)grid[0].size()) return;
    if (grid[r][c] != '1') return;
    grid[r][c] = '0';
    sink(grid, r + 1, c);
    sink(grid, r - 1, c);
    sink(grid, r, c + 1);
    sink(grid, r, c - 1);
}

int numIslands(vector<vector<char> > grid) {
    int count = 0;
    for (int r = 0; r < (int)grid.size(); ++r)
        for (int c = 0; c < (int)grid[0].size(); ++c)
            if (grid[r][c] == '1') { ++count; sink(grid, r, c); }
    return count;
}

int main() {
    vector<string> raw = {"11110", "11010", "11000", "00000"};
    vector<vector<char> > grid;
    for (const string& row : raw) grid.push_back(vector<char>(row.begin(), row.end()));
    cout << numIslands(grid) << "\n";   // 1

    vector<string> raw2 = {"11000", "11000", "00100", "00011"};
    vector<vector<char> > g2;
    for (const string& row : raw2) g2.push_back(vector<char>(row.begin(), row.end()));
    cout << numIslands(g2) << "\n";     // 3
    return 0;
}
