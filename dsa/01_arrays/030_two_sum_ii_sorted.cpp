/*
 * 030. Two Sum II (Sorted Input)
 * Topic: Arrays | Difficulty: Medium
 *
 * The input array is sorted ascending. Return the 1-based indices of the two
 * numbers adding up to target, using constant extra space.
 *
 * Approach: two pointers from both ends. If the sum is too small the only way to
 * grow it is to move the left pointer right; if too large, move the right
 * pointer left.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumSorted(const vector<int>& a, int target) {
    int lo = 0, hi = a.size() - 1;
    while (lo < hi) {
        int sum = a[lo] + a[hi];
        if (sum == target) return {lo + 1, hi + 1};
        if (sum < target) ++lo;
        else --hi;
    }
    return {};
}

int main() {
    vector<int> ans = twoSumSorted({2, 7, 11, 15}, 9);
    cout << ans[0] << " " << ans[1] << "\n";   // 1 2
    return 0;
}
