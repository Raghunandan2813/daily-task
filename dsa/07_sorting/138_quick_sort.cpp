/*
 * 138. Quick Sort
 * Topic: Sorting | Difficulty: Medium
 *
 * Partition around a pivot so smaller values end up left and larger ones right,
 * then recurse on both sides.
 *
 * Approach: Lomuto partition with a randomised pivot. Randomisation is what
 * keeps sorted or adversarial input from triggering the O(n^2) worst case.
 * Quicksort is in-place but not stable.
 *
 * Time: O(n log n) expected, O(n^2) worst case   Space: O(log n) recursion
 */
#include <bits/stdc++.h>
using namespace std;

static int partitionRange(vector<int>& a, int lo, int hi) {
    swap(a[lo + rand() % (hi - lo + 1)], a[hi]);     // randomised pivot
    int pivot = a[hi], i = lo - 1;
    for (int j = lo; j < hi; ++j)
        if (a[j] <= pivot) swap(a[++i], a[j]);
    swap(a[i + 1], a[hi]);
    return i + 1;
}

static void sortRange(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;
    int p = partitionRange(a, lo, hi);
    sortRange(a, lo, p - 1);
    sortRange(a, p + 1, hi);
}

void quickSort(vector<int>& a) {
    if (a.size() > 1) sortRange(a, 0, a.size() - 1);
}

int main() {
    srand(12345);
    vector<int> v = {10, 7, 8, 9, 1, 5};
    quickSort(v);
    for (int x : v) cout << x << " ";
    cout << "\n";   // 1 5 7 8 9 10
    return 0;
}
