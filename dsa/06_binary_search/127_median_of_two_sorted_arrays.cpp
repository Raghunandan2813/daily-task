/*
 * 127. Median of Two Sorted Arrays
 * Topic: Binary Search | Difficulty: Hard
 *
 * Find the median of two sorted arrays in O(log(min(n, m))) time.
 *
 * Approach: binary search for a partition point. Cut both arrays so the combined
 * left side holds exactly half the elements; the cut is correct when every value
 * on the left is <= every value on the right. Searching over the shorter array
 * bounds the work.
 *
 * Time: O(log(min(n, m)))   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> a, vector<int> b) {
    if (a.size() > b.size()) swap(a, b);
    int n = a.size(), m = b.size(), half = (n + m + 1) / 2;
    int lo = 0, hi = n;
    while (lo <= hi) {
        int i = lo + (hi - lo) / 2;                  // elements taken from a
        int j = half - i;                            // elements taken from b
        int aLeft  = (i == 0) ? INT_MIN : a[i - 1];
        int aRight = (i == n) ? INT_MAX : a[i];
        int bLeft  = (j == 0) ? INT_MIN : b[j - 1];
        int bRight = (j == m) ? INT_MAX : b[j];

        if (aLeft <= bRight && bLeft <= aRight) {
            if ((n + m) % 2) return max(aLeft, bLeft);
            return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
        }
        if (aLeft > bRight) hi = i - 1;
        else lo = i + 1;
    }
    return 0.0;
}

int main() {
    cout << findMedianSortedArrays({1, 3}, {2}) << "\n";       // 2
    cout << findMedianSortedArrays({1, 2}, {3, 4}) << "\n";    // 2.5
    return 0;
}
