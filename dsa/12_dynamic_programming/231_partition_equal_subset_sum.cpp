/*
 * 231. Partition Equal Subset Sum
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Decide whether the array can be split into two subsets with equal sums.
 *
 * Approach: an equal split means each half sums to total/2, so an odd total is
 * immediately impossible. Otherwise this reduces to a subset-sum query for
 * total/2. A bitset makes the inner loop a single shift-and-or over machine
 * words.
 *
 * Time: O(n * sum / 64)   Space: O(sum)
 */
#include <bits/stdc++.h>
using namespace std;

bool canPartition(const vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2) return false;
    int half = total / 2;

    vector<char> dp(half + 1, false);
    dp[0] = true;
    for (int x : nums)
        for (int s = half; s >= x; --s)
            if (dp[s - x]) dp[s] = true;
    return dp[half];
}

int main() {
    cout << canPartition({1, 5, 11, 5}) << "\n";   // 1
    cout << canPartition({1, 2, 3, 5}) << "\n";    // 0
    return 0;
}
