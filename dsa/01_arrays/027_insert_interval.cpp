/*
 * 027. Insert Interval
 * Topic: Arrays | Difficulty: Medium
 *
 * Given a sorted list of non-overlapping intervals, insert a new interval and
 * merge where necessary.
 *
 * Approach: three phases. Copy every interval ending before the new one starts,
 * absorb every interval that overlaps into a widened new interval, then copy the
 * rest.
 *
 * Time: O(n)   Space: O(n) for the output
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(const vector<vector<int>>& iv, vector<int> ni) {
    vector<vector<int>> out;
    int i = 0, n = iv.size();
    while (i < n && iv[i][1] < ni[0]) out.push_back(iv[i++]);
    while (i < n && iv[i][0] <= ni[1]) {
        ni[0] = min(ni[0], iv[i][0]);
        ni[1] = max(ni[1], iv[i][1]);
        ++i;
    }
    out.push_back(ni);
    while (i < n) out.push_back(iv[i++]);
    return out;
}

int main() {
    vector<vector<int>> iv = {{1, 3}, {6, 9}};
    for (const auto& x : insertInterval(iv, {2, 5})) cout << "[" << x[0] << "," << x[1] << "] ";
    cout << "\n";   // [1,5] [6,9]
    return 0;
}
