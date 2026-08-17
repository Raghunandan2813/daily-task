/*
 * 021. Maximum Product Subarray
 * Topic: Arrays | Difficulty: Medium
 *
 * Find the contiguous subarray with the largest product.
 *
 * Approach: a negative number swaps the roles of the largest and smallest
 * products, so track both running extremes ending at i and swap them whenever
 * the current element is negative.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int maxProduct(const vector<int>& nums) {
    int curMax = nums[0], curMin = nums[0], best = nums[0];
    for (int i = 1; i < (int)nums.size(); ++i) {
        int x = nums[i];
        if (x < 0) swap(curMax, curMin);
        curMax = max(x, curMax * x);
        curMin = min(x, curMin * x);
        best = max(best, curMax);
    }
    return best;
}

int main() {
    cout << maxProduct({2, 3, -2, 4}) << "\n";       // 6
    cout << maxProduct({-2, 0, -1}) << "\n";         // 0
    cout << maxProduct({-2, 3, -4}) << "\n";         // 24
    return 0;
}
