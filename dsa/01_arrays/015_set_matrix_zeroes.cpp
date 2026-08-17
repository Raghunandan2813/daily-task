/*
 * 015. Set Matrix Zeroes
 * Topic: Arrays | Difficulty: Medium
 *
 * If an element in an m x n matrix is 0, set its entire row and column to 0.
 * Do it in place with O(1) extra space.
 *
 * Approach: use the first row and first column as marker storage. A separate
 * flag remembers whether the first column itself must be zeroed, since cell
 * (0,0) is shared between the two markers.
 *
 * Time: O(m*n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    bool firstCol = false;
    for (int i = 0; i < m; ++i) {
        if (mat[i][0] == 0) firstCol = true;
        for (int j = 1; j < n; ++j)
            if (mat[i][j] == 0) { mat[i][0] = 0; mat[0][j] = 0; }
    }
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 1; --j)
            if (mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;
        if (firstCol) mat[i][0] = 0;
    }
}

int main() {
    vector<vector<int>> m = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(m);
    for (const auto& row : m) { for (int x : row) cout << x << " "; cout << "\n"; }
    // 1 0 1 / 0 0 0 / 1 0 1
    return 0;
}
