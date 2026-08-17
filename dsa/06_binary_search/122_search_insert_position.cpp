/*
 * 122. Search Insert Position
 * Topic: Binary Search | Difficulty: Easy
 *
 * Return the index of a target in a sorted array, or the index where it would be
 * inserted to keep the array sorted.
 *
 * Approach: a lower-bound search. The half-open invariant means the loop always
 * terminates with `lo` sitting at the first element not less than the target,
 * which is exactly the insertion point.
 *
 * Time: O(log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int searchInsert(const vector<int>& a, int target) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main() {
    cout << searchInsert({1, 3, 5, 6}, 5) << "\n";   // 2
    cout << searchInsert({1, 3, 5, 6}, 2) << "\n";   // 1
    cout << searchInsert({1, 3, 5, 6}, 7) << "\n";   // 4
    return 0;
}
