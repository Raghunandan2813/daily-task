/*
 * 121. Find Peak Element
 * Topic: Binary Search | Difficulty: Medium
 *
 * A peak is an element strictly greater than its neighbours (out-of-bounds
 * neighbours count as negative infinity). Return the index of any peak in
 * O(log n).
 *
 * Approach: binary search on the slope. If a[mid] < a[mid+1] the array is rising
 * at mid, so a peak must exist to the right; otherwise one exists at mid or to
 * its left. The range always contains a peak, so the loop converges to one.
 *
 * Time: O(log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(const vector<int>& a) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < a[mid + 1]) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main() {
    cout << findPeakElement({1, 2, 3, 1}) << "\n";            // 2
    cout << findPeakElement({1, 2, 1, 3, 5, 6, 4}) << "\n";   // 5 (or 1)
    return 0;
}
