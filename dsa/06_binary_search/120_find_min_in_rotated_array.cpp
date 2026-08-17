/*
 * 120. Find Minimum in Rotated Sorted Array
 * Topic: Binary Search | Difficulty: Medium
 *
 * Find the smallest element of a rotated sorted array of distinct values.
 *
 * Approach: compare the midpoint against the right end rather than the left. If
 * a[mid] > a[hi] the rotation point must lie to the right of mid, so the minimum
 * is in (mid, hi]; otherwise it is in [lo, mid].
 *
 * Time: O(log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int findMin(const vector<int>& a) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] > a[hi]) lo = mid + 1;
        else hi = mid;
    }
    return a[lo];
}

int main() {
    cout << findMin({3, 4, 5, 1, 2}) << "\n";           // 1
    cout << findMin({4, 5, 6, 7, 0, 1, 2}) << "\n";     // 0
    cout << findMin({11, 13, 15, 17}) << "\n";          // 11
    return 0;
}
