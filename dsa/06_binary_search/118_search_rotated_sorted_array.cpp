/*
 * 118. Search in Rotated Sorted Array
 * Topic: Binary Search | Difficulty: Medium
 *
 * A sorted array of distinct values was rotated at some pivot. Find a target in
 * O(log n).
 *
 * Approach: at every midpoint one of the two halves is guaranteed to be sorted.
 * Identify that half by comparing a[lo] with a[mid], check whether the target
 * lies inside its range, and discard the other half.
 *
 * Time: O(log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int search(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[lo] <= a[mid]) {                       // left half is sorted
            if (a[lo] <= target && target < a[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {                                     // right half is sorted
            if (a[mid] < target && target <= a[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    cout << search({4, 5, 6, 7, 0, 1, 2}, 0) << "\n";   // 4
    cout << search({4, 5, 6, 7, 0, 1, 2}, 3) << "\n";   // -1
    return 0;
}
