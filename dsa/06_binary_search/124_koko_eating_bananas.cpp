/*
 * 124. Koko Eating Bananas
 * Topic: Binary Search | Difficulty: Medium
 *
 * Given piles of bananas and h hours, find the minimum integer eating speed k
 * such that all piles are finished in time. Eating a pile takes ceil(pile/k)
 * hours regardless of leftovers.
 *
 * Approach: binary search on the answer. Total hours needed is monotonically
 * non-increasing in k, so we search for the smallest k whose total fits in h.
 *
 * Time: O(n log(max pile))   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static long long hoursNeeded(const vector<int>& piles, int k) {
    long long total = 0;
    for (int p : piles) total += (p + k - 1) / k;   // ceil division
    return total;
}

int minEatingSpeed(const vector<int>& piles, int h) {
    int lo = 1, hi = *max_element(piles.begin(), piles.end());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (hoursNeeded(piles, mid) <= h) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    cout << minEatingSpeed({3, 6, 7, 11}, 8) << "\n";         // 4
    cout << minEatingSpeed({30, 11, 23, 4, 20}, 5) << "\n";   // 30
    cout << minEatingSpeed({30, 11, 23, 4, 20}, 6) << "\n";   // 23
    return 0;
}
