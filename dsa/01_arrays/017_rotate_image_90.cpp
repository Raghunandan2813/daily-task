/*
 * 017. Rotate Image by 90 Degrees
 * Topic: Arrays | Difficulty: Medium
 *
 * Rotate an n x n matrix by 90 degrees clockwise, in place.
 *
 * Approach: transpose the matrix (reflect across the main diagonal), then
 * reverse each row. Transpose plus horizontal flip equals a clockwise rotation.
 *
 * Time: O(n^2)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            swap(mat[i][j], mat[j][i]);
    for (int i = 0; i < n; ++i)
        reverse(mat[i].begin(), mat[i].end());
}

int main() {
    vector<vector<int>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(m);
    for (const auto& row : m) { for (int x : row) cout << x << " "; cout << "\n"; }
    // 7 4 1 / 8 5 2 / 9 6 3
    return 0;
}
