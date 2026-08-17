/*
 * 034. Maximum Sum Circular Subarray
 * Topic: Arrays | Difficulty: Medium
 *
 * The array is circular, so a subarray may wrap around the end. Return the
 * maximum possible subarray sum.
 *
 * Approach: the answer is either a normal subarray (plain Kadane) or a wrapping
 * one. A wrapping subarray is the total minus a non-wrapping minimum subarray,
 * so run Kadane for both max and min. If every element is negative the "total -
 * min" branch yields an empty selection, so fall back to the plain maximum.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(const vector<int>& a) {
    int total = 0;
    int curMax = 0, best = INT_MIN;
    int curMin = 0, worst = INT_MAX;
    for (int x : a) {
        total += x;
        curMax = max(x, curMax + x);
        best = max(best, curMax);
        curMin = min(x, curMin + x);
        worst = min(worst, curMin);
    }
    if (best < 0) return best;             // all elements negative
    return max(best, total - worst);
}

int main() {
    cout << maxSubarraySumCircular({1, -2, 3, -2}) << "\n";    // 3
    cout << maxSubarraySumCircular({5, -3, 5}) << "\n";        // 10
    cout << maxSubarraySumCircular({-3, -2, -3}) << "\n";      // -2
    return 0;
}
