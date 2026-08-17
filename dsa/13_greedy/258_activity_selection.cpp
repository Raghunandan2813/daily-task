/*
 * 258. Activity Selection
 * Topic: Greedy | Difficulty: Medium
 *
 * Choose the maximum number of non-overlapping activities from a set with start
 * and finish times.
 *
 * Approach: sort by finish time and always take the next activity that starts at
 * or after the last chosen finish. Finishing earliest leaves the most room for
 * the rest, and an exchange argument shows this greedy choice is always at least
 * as good as any alternative.
 *
 * Time: O(n log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int activitySelection(vector<pair<int, int> > activities) {   // (start, finish)
    sort(activities.begin(), activities.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second < b.second;
         });
    int count = 0, lastFinish = INT_MIN;
    for (const auto& a : activities)
        if (a.first >= lastFinish) { ++count; lastFinish = a.second; }
    return count;
}

int main() {
    vector<pair<int, int> > acts;
    acts.push_back(make_pair(1, 2));
    acts.push_back(make_pair(3, 4));
    acts.push_back(make_pair(0, 6));
    acts.push_back(make_pair(5, 7));
    acts.push_back(make_pair(8, 9));
    acts.push_back(make_pair(5, 9));
    cout << activitySelection(acts) << "\n";   // 4
    return 0;
}
