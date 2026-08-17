/*
 * 132. Single Element in a Sorted Array
 * Topic: Binary Search | Difficulty: Medium
 *
 * Every element appears exactly twice except one. The array is sorted. Find the
 * lone element in O(log n).
 *
 * Approach: before the unique element, every pair starts at an even index; after
 * it, pairs start at odd indices. Force mid to an even index and compare it with
 * its successor: if they match, the odd one out is to the right.
 *
 * Time: O(log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(const vector<int>& a) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (mid % 2 == 1) --mid;                     // align to an even index
        if (a[mid] == a[mid + 1]) lo = mid + 2;
        else hi = mid;
    }
    return a[lo];
}

int main() {
    cout << singleNonDuplicate({1, 1, 2, 3, 3, 4, 4, 8, 8}) << "\n";   // 2
    cout << singleNonDuplicate({3, 3, 7, 7, 10, 11, 11}) << "\n";      // 10
    return 0;
}
