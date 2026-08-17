/*
 * 143. Count Inversions
 * Topic: Sorting | Difficulty: Hard
 *
 * Count the pairs (i, j) with i < j and a[i] > a[j] - a measure of how far the
 * array is from sorted.
 *
 * Approach: piggyback on merge sort. During a merge, when an element from the
 * right half is taken before position i of the left half, it is smaller than
 * every one of the (mid - i + 1) remaining left elements, so that many
 * inversions can be counted at once.
 *
 * Time: O(n log n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

static long long mergeCount(vector<int>& a, int lo, int mid, int hi,
                            vector<int>& buf) {
    long long inv = 0;
    int i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= hi) {
        if (a[i] <= a[j]) buf[k++] = a[i++];
        else { inv += mid - i + 1; buf[k++] = a[j++]; }
    }
    while (i <= mid) buf[k++] = a[i++];
    while (j <= hi) buf[k++] = a[j++];
    for (int t = lo; t <= hi; ++t) a[t] = buf[t];
    return inv;
}

static long long sortCount(vector<int>& a, int lo, int hi, vector<int>& buf) {
    if (lo >= hi) return 0;
    int mid = lo + (hi - lo) / 2;
    long long inv = sortCount(a, lo, mid, buf) + sortCount(a, mid + 1, hi, buf);
    return inv + mergeCount(a, lo, mid, hi, buf);
}

long long countInversions(vector<int> a) {
    if (a.size() < 2) return 0;
    vector<int> buf(a.size());
    return sortCount(a, 0, a.size() - 1, buf);
}

int main() {
    cout << countInversions({2, 4, 1, 3, 5}) << "\n";   // 3
    cout << countInversions({5, 4, 3, 2, 1}) << "\n";   // 10
    cout << countInversions({1, 2, 3}) << "\n";         // 0
    return 0;
}
