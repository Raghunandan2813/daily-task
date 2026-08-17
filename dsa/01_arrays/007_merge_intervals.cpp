/*
 * 007. Merge Intervals
 * Topic: Arrays | Difficulty: Medium
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Approach: sort by start. Walk the sorted list keeping the current merged
 * interval; if the next interval starts before the current end, extend the end,
 * otherwise push the current interval and start a new one.
 *
 * Time: O(n log n)   Space: O(n) for the output
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> out;
    out.push_back(intervals[0]);
    for (int i = 1; i < (int)intervals.size(); ++i) {
        if (intervals[i][0] <= out.back()[1])
            out.back()[1] = max(out.back()[1], intervals[i][1]);
        else
            out.push_back(intervals[i]);
    }
    return out;
}

int main() {
    vector<vector<int>> in = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    for (const auto& iv : merge(in)) cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << "\n";   // [1,6] [8,10] [15,18]
    return 0;
}
