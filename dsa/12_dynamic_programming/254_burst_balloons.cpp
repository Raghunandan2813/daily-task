/*
 * 254. Burst Balloons
 * Topic: Dynamic Programming | Difficulty: Hard
 *
 * Bursting balloon i earns nums[left] * nums[i] * nums[right] where left and
 * right are its current neighbours. Maximise the total.
 *
 * Approach: interval DP with the order reversed. Thinking about which balloon to
 * burst *first* fails because it changes the neighbours of everything. Instead
 * ask which balloon in an interval is burst *last* - at that point its
 * neighbours are exactly the interval boundaries, which are fixed. Padding the
 * array with 1s at both ends removes the edge cases.
 *
 * Time: O(n^3)   Space: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for (int len = 2; len < n; ++len) {              // span between the borders
        for (int lo = 0; lo + len < n; ++lo) {
            int hi = lo + len;
            for (int last = lo + 1; last < hi; ++last) {
                int coins = dp[lo][last] + dp[last][hi] +
                            nums[lo] * nums[last] * nums[hi];
                dp[lo][hi] = max(dp[lo][hi], coins);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    cout << maxCoins({3, 1, 5, 8}) << "\n";   // 167
    cout << maxCoins({1, 5}) << "\n";         // 10
    return 0;
}
