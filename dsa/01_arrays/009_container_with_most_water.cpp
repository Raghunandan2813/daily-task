/*
 * 009. Container With Most Water
 * Topic: Arrays | Difficulty: Medium
 *
 * height[i] is the height of a vertical line at position i. Pick two lines that
 * together with the x-axis hold the most water.
 *
 * Approach: two pointers at both ends. The area is limited by the shorter line,
 * so moving the taller pointer inward can never help - move the shorter one.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int maxArea(const vector<int>& height) {
    int lo = 0, hi = (int)height.size() - 1, best = 0;
    while (lo < hi) {
        best = max(best, (hi - lo) * min(height[lo], height[hi]));
        if (height[lo] < height[hi]) ++lo;
        else --hi;
    }
    return best;
}

int main() {
    cout << maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << "\n";   // 49
    return 0;
}
