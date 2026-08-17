/*
 * 117. Find First and Last Position of Element in Sorted Array
 * Topic: Binary Search | Difficulty: Medium
 *
 * Return the first and last index of a target in a sorted array with duplicates,
 * or {-1, -1} if absent.
 *
 * Approach: two boundary searches. lower_bound finds the first index whose value
 * is >= target; upper_bound finds the first index whose value is > target, so the
 * last occurrence sits one place before it.
 *
 * Time: O(log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static int lowerBound(const vector<int>& a, int target) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

static int upperBound(const vector<int>& a, int target) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

vector<int> searchRange(const vector<int>& a, int target) {
    int first = lowerBound(a, target);
    if (first == (int)a.size() || a[first] != target) return {-1, -1};
    return {first, upperBound(a, target) - 1};
}

int main() {
    vector<int> r = searchRange({5, 7, 7, 8, 8, 10}, 8);
    cout << r[0] << " " << r[1] << "\n";   // 3 4
    vector<int> q = searchRange({5, 7, 7, 8, 8, 10}, 6);
    cout << q[0] << " " << q[1] << "\n";   // -1 -1
    return 0;
}
