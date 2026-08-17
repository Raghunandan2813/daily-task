/*
 * 028. Non-overlapping Intervals
 * Topic: Arrays | Difficulty: Medium
 *
 * Return the minimum number of intervals to remove so that the rest do not
 * overlap.
 *
 * Approach: greedy by earliest finishing time. Sort by end; always keep the
 * interval that finishes first, since it leaves the most room for the remainder.
 * Anything starting before the last kept end is removed.
 *
 * Time: O(n log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>> iv) {
    if (iv.empty()) return 0;
    sort(iv.begin(), iv.end(),
         [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    int kept = 1, lastEnd = iv[0][1];
    for (int i = 1; i < (int)iv.size(); ++i) {
        if (iv[i][0] >= lastEnd) { ++kept; lastEnd = iv[i][1]; }
    }
    return (int)iv.size() - kept;
}

int main() {
    cout << eraseOverlapIntervals({{1, 2}, {2, 3}, {3, 4}, {1, 3}}) << "\n";   // 1
    cout << eraseOverlapIntervals({{1, 2}, {1, 2}, {1, 2}}) << "\n";           // 2
    return 0;
}
