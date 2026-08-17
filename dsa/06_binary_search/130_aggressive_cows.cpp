/*
 * 130. Aggressive Cows
 * Topic: Binary Search | Difficulty: Hard
 *
 * Place k cows in stalls positioned along a line so that the minimum distance
 * between any two cows is as large as possible.
 *
 * Approach: binary search on the distance. For a candidate gap, greedily place a
 * cow in the first stall and then in every stall at least `gap` beyond the last
 * placement; feasibility is monotone in the gap, so keep the largest feasible one.
 *
 * Time: O(n log n + n log(range))   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static bool canPlace(const vector<int>& stalls, int cows, int gap) {
    int placed = 1, last = stalls[0];
    for (int i = 1; i < (int)stalls.size(); ++i) {
        if (stalls[i] - last >= gap) { ++placed; last = stalls[i]; }
        if (placed >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int lo = 1, hi = stalls.back() - stalls.front(), best = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canPlace(stalls, cows, mid)) { best = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    return best;
}

int main() {
    cout << aggressiveCows({1, 2, 4, 8, 9}, 3) << "\n";   // 3
    cout << aggressiveCows({0, 3, 4, 7, 10, 9}, 4) << "\n";   // 3
    return 0;
}
