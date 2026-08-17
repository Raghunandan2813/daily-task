/*
 * 128. Kth Element of Two Sorted Arrays
 * Topic: Binary Search | Difficulty: Hard
 *
 * Find the k-th smallest element (1-indexed) of the union of two sorted arrays.
 *
 * Approach: the same partition search used for the median, but the left side is
 * sized to exactly k elements instead of half. The answer is the larger of the
 * two values ending the left partitions.
 *
 * Time: O(log(min(n, m)))   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> a, vector<int> b, int k) {
    if (a.size() > b.size()) swap(a, b);
    int n = a.size(), m = b.size();
    int lo = max(0, k - m), hi = min(k, n);
    while (lo <= hi) {
        int i = lo + (hi - lo) / 2;
        int j = k - i;
        int aLeft  = (i == 0) ? INT_MIN : a[i - 1];
        int aRight = (i == n) ? INT_MAX : a[i];
        int bLeft  = (j == 0) ? INT_MIN : b[j - 1];
        int bRight = (j == m) ? INT_MAX : b[j];

        if (aLeft <= bRight && bLeft <= aRight) return max(aLeft, bLeft);
        if (aLeft > bRight) hi = i - 1;
        else lo = i + 1;
    }
    return -1;
}

int main() {
    cout << kthElement({2, 3, 6, 7, 9}, {1, 4, 8, 10}, 5) << "\n";   // 6
    cout << kthElement({100, 112, 256, 349, 770}, {72, 86, 113, 119, 265, 445, 892}, 7) << "\n";   // 256
    return 0;
}
