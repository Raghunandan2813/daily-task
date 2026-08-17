/*
 * 131. Search a 2D Matrix
 * Topic: Binary Search | Difficulty: Medium
 *
 * Each row of the matrix is sorted and the first value of each row is greater
 * than the last value of the previous row. Find a target in O(log(m*n)).
 *
 * Approach: the matrix reads as one sorted array of length m*n, so run a single
 * binary search over that virtual index and map it back with
 * row = idx / cols, col = idx % cols.
 *
 * Time: O(log(m*n))   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(const vector<vector<int>>& mat, int target) {
    if (mat.empty() || mat[0].empty()) return false;
    int rows = mat.size(), cols = mat[0].size();
    int lo = 0, hi = rows * cols - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int val = mat[mid / cols][mid % cols];
        if (val == target) return true;
        if (val < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> m = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << searchMatrix(m, 3) << "\n";    // 1
    cout << searchMatrix(m, 13) << "\n";   // 0
    return 0;
}
