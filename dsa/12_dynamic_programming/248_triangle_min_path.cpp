/*
 * 248. Triangle Minimum Path Sum
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Descend a triangle from the apex to the base, at each step moving to an
 * adjacent number on the row below. Minimise the total.
 *
 * Approach: work bottom-up. Starting from the base, replace each cell by its own
 * value plus the cheaper of the two cells beneath it. Going upwards avoids the
 * boundary bookkeeping that a top-down pass needs, and the answer ends up at the
 * apex.
 *
 * Time: O(n^2)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int minimumTotal(const vector<vector<int> >& triangle) {
    vector<int> dp = triangle.back();               // start from the base row
    for (int row = (int)triangle.size() - 2; row >= 0; --row)
        for (int col = 0; col <= row; ++col)
            dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
    return dp[0];
}

int main() {
    vector<vector<int> > t = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(t) << "\n";      // 11
    cout << minimumTotal({{-10}}) << "\n";   // -10
    return 0;
}
