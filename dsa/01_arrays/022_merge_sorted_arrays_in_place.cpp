/*
 * 022. Merge Sorted Array (in place)
 * Topic: Arrays | Difficulty: Easy
 *
 * nums1 has length m+n with the last n slots empty. Merge nums2 (length n) into
 * nums1 so that nums1 is sorted.
 *
 * Approach: merge from the back. Writing into the tail of nums1 never overwrites
 * an element that has not been consumed yet, so no temporary buffer is needed.
 *
 * Time: O(m+n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void mergeSorted(vector<int>& nums1, int m, const vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, w = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) nums1[w--] = nums1[i--];
        else nums1[w--] = nums2[j--];
    }
}

int main() {
    vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> b = {2, 5, 6};
    mergeSorted(a, 3, b, 3);
    for (int x : a) cout << x << " ";
    cout << "\n";   // 1 2 2 3 5 6
    return 0;
}
