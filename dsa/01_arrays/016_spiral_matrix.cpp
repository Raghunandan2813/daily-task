/*
 * 016. Spiral Matrix
 * Topic: Arrays | Difficulty: Medium
 *
 * Return all elements of an m x n matrix in spiral order.
 *
 * Approach: keep four boundaries (top, bottom, left, right) and peel one layer
 * at a time, shrinking the boundary after each edge. The two extra guards stop
 * a single leftover row or column from being emitted twice.
 *
 * Time: O(m*n)   Space: O(1) extra
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(const vector<vector<int>>& mat) {
    if (mat.empty()) return {};
    int top = 0, bottom = mat.size() - 1, left = 0, right = mat[0].size() - 1;
    vector<int> out;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j) out.push_back(mat[top][j]);
        ++top;
        for (int i = top; i <= bottom; ++i) out.push_back(mat[i][right]);
        --right;
        if (top <= bottom) {
            for (int j = right; j >= left; --j) out.push_back(mat[bottom][j]);
            --bottom;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) out.push_back(mat[i][left]);
            ++left;
        }
    }
    return out;
}

int main() {
    vector<vector<int>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int x : spiralOrder(m)) cout << x << " ";
    cout << "\n";   // 1 2 3 6 9 8 7 4 5
    return 0;
}
