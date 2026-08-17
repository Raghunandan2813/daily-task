/*
 * 116. Binary Search
 * Topic: Binary Search | Difficulty: Easy
 *
 * Find the index of a target in a sorted array, or -1 if it is absent.
 *
 * Approach: halve the search range each step. The midpoint is computed as
 * lo + (hi - lo) / 2 rather than (lo + hi) / 2 so it cannot overflow for large
 * indices.
 *
 * Time: O(log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    cout << binarySearch(a, 9) << "\n";   // 4
    cout << binarySearch(a, 2) << "\n";   // -1
    return 0;
}
