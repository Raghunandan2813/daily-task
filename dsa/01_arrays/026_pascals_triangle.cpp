/*
 * 026. Pascal's Triangle
 * Topic: Arrays | Difficulty: Easy
 *
 * Generate the first numRows rows of Pascal's triangle.
 *
 * Approach: each row starts and ends with 1, and every interior entry is the sum
 * of the two entries directly above it in the previous row.
 *
 * Time: O(n^2)   Space: O(n^2) for the output
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> tri;
    for (int i = 0; i < numRows; ++i) {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; ++j)
            row[j] = tri[i - 1][j - 1] + tri[i - 1][j];
        tri.push_back(row);
    }
    return tri;
}

int main() {
    for (const auto& row : generate(5)) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    // 1 / 1 1 / 1 2 1 / 1 3 3 1 / 1 4 6 4 1
    return 0;
}
