/*
 * 119. Search in Rotated Sorted Array II (with Duplicates)
 * Topic: Binary Search | Difficulty: Medium
 *
 * Same as the previous problem but the array may contain duplicates. Return
 * whether the target is present.
 *
 * Approach: the sorted-half test breaks when a[lo] == a[mid] == a[hi], because
 * neither side can be identified. In that case shrink both ends by one and try
 * again - which is why the worst case degrades to O(n).
 *
 * Time: O(log n) average, O(n) worst case   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

bool search(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return true;
        if (a[lo] == a[mid] && a[mid] == a[hi]) { ++lo; --hi; }
        else if (a[lo] <= a[mid]) {                  // left half is sorted
            if (a[lo] <= target && target < a[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {                                     // right half is sorted
            if (a[mid] < target && target <= a[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return false;
}

int main() {
    cout << search({2, 5, 6, 0, 0, 1, 2}, 0) << "\n";   // 1
    cout << search({2, 5, 6, 0, 0, 1, 2}, 3) << "\n";   // 0
    return 0;
}
