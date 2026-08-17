/*
 * 137. Merge Sort
 * Topic: Sorting | Difficulty: Medium
 *
 * Divide and conquer: sort each half, then merge the two sorted halves.
 *
 * Approach: recursion splits down to single elements, which are trivially
 * sorted, and the merge step combines two sorted runs in linear time using a
 * scratch buffer. Merge sort is stable and its O(n log n) bound holds for every
 * input, unlike quicksort.
 *
 * Time: O(n log n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

static void merge(vector<int>& a, int lo, int mid, int hi, vector<int>& buf) {
    int i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= hi)
        buf[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];   // <= keeps it stable
    while (i <= mid) buf[k++] = a[i++];
    while (j <= hi) buf[k++] = a[j++];
    for (int t = lo; t <= hi; ++t) a[t] = buf[t];
}

static void sortRange(vector<int>& a, int lo, int hi, vector<int>& buf) {
    if (lo >= hi) return;
    int mid = lo + (hi - lo) / 2;
    sortRange(a, lo, mid, buf);
    sortRange(a, mid + 1, hi, buf);
    merge(a, lo, mid, hi, buf);
}

void mergeSort(vector<int>& a) {
    if (a.size() < 2) return;
    vector<int> buf(a.size());
    sortRange(a, 0, a.size() - 1, buf);
}

int main() {
    vector<int> v = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(v);
    for (int x : v) cout << x << " ";
    cout << "\n";   // 3 9 10 27 38 43 82
    return 0;
}
