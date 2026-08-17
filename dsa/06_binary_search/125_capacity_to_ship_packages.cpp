/*
 * 125. Capacity To Ship Packages Within D Days
 * Topic: Binary Search | Difficulty: Medium
 *
 * Packages must be shipped in their given order within `days` days. Find the
 * smallest ship capacity that makes this possible.
 *
 * Approach: binary search on capacity. The lower bound is the heaviest single
 * package (it must fit) and the upper bound is the total weight (one day). A
 * greedy pass counts the days a candidate capacity requires.
 *
 * Time: O(n log(total weight))   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static int daysNeeded(const vector<int>& w, int cap) {
    int days = 1, load = 0;
    for (int x : w) {
        if (load + x > cap) { ++days; load = 0; }
        load += x;
    }
    return days;
}

int shipWithinDays(const vector<int>& weights, int days) {
    int lo = *max_element(weights.begin(), weights.end());
    int hi = accumulate(weights.begin(), weights.end(), 0);
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (daysNeeded(weights, mid) <= days) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    cout << shipWithinDays({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5) << "\n";   // 15
    cout << shipWithinDays({3, 2, 2, 4, 1, 4}, 3) << "\n";                // 6
    return 0;
}
