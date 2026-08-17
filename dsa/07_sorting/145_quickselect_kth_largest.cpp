/*
 * 145. Kth Largest Element (Quickselect)
 * Topic: Sorting | Difficulty: Medium
 *
 * Find the k-th largest element without fully sorting the array.
 *
 * Approach: quickselect. Partition as in quicksort, but recurse into only the
 * side that can contain the target index. That drops the expected cost from
 * O(n log n) to O(n), since the work halves geometrically.
 *
 * Time: O(n) expected, O(n^2) worst case   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static int partitionRange(vector<int>& a, int lo, int hi) {
    swap(a[lo + rand() % (hi - lo + 1)], a[hi]);
    int pivot = a[hi], i = lo - 1;
    for (int j = lo; j < hi; ++j)
        if (a[j] <= pivot) swap(a[++i], a[j]);
    swap(a[i + 1], a[hi]);
    return i + 1;
}

int findKthLargest(vector<int> a, int k) {
    int target = (int)a.size() - k;                   // index in ascending order
    int lo = 0, hi = a.size() - 1;
    while (true) {
        int p = partitionRange(a, lo, hi);
        if (p == target) return a[p];
        if (p < target) lo = p + 1;
        else hi = p - 1;
    }
}

int main() {
    srand(12345);
    cout << findKthLargest({3, 2, 1, 5, 6, 4}, 2) << "\n";            // 5
    cout << findKthLargest({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4) << "\n";   // 4
    return 0;
}
