/*
 * 227. House Robber II (Circular Street)
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Same as House Robber, but the houses are arranged in a circle so the first and
 * last are adjacent.
 *
 * Approach: the first and last house can never both be robbed, so run the linear
 * solver twice - once excluding the last house, once excluding the first - and
 * take the better result. The single-house case is handled separately.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static int robLine(const vector<int>& nums, int lo, int hi) {
    int prev2 = 0, prev1 = 0;
    for (int i = lo; i <= hi; ++i) {
        int cur = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int rob(const vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return max(robLine(nums, 0, n - 2), robLine(nums, 1, n - 1));
}

int main() {
    cout << rob({2, 3, 2}) << "\n";       // 3
    cout << rob({1, 2, 3, 1}) << "\n";    // 4
    cout << rob({5}) << "\n";             // 5
    return 0;
}
