/*
 * 010. Trapping Rain Water
 * Topic: Arrays | Difficulty: Hard
 *
 * Given an elevation map, compute how much rain water it can trap.
 *
 * Approach: water above bar i is min(maxLeft, maxRight) - height[i]. Two pointers
 * track both running maxima; whichever side has the smaller max is the binding
 * constraint, so that side can be settled immediately.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int trap(const vector<int>& height) {
    int lo = 0, hi = (int)height.size() - 1;
    int leftMax = 0, rightMax = 0, total = 0;
    while (lo < hi) {
        if (height[lo] < height[hi]) {
            leftMax = max(leftMax, height[lo]);
            total += leftMax - height[lo];
            ++lo;
        } else {
            rightMax = max(rightMax, height[hi]);
            total += rightMax - height[hi];
            --hi;
        }
    }
    return total;
}

int main() {
    cout << trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << "\n";   // 6
    cout << trap({4, 2, 0, 3, 2, 5}) << "\n";                     // 9
    return 0;
}
