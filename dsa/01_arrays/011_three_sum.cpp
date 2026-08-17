/*
 * 011. 3Sum
 * Topic: Arrays | Difficulty: Medium
 *
 * Find all unique triplets in the array that sum to zero.
 *
 * Approach: sort, then fix the first element and solve a 2Sum on the remaining
 * suffix with two pointers. Skipping equal neighbours at each level removes
 * duplicate triplets without needing a set.
 *
 * Time: O(n^2)   Space: O(1) extra
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> out;
    for (int i = 0; i + 2 < n; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int lo = i + 1, hi = n - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum == 0) {
                out.push_back({nums[i], nums[lo], nums[hi]});
                while (lo < hi && nums[lo] == nums[lo + 1]) ++lo;
                while (lo < hi && nums[hi] == nums[hi - 1]) --hi;
                ++lo; --hi;
            } else if (sum < 0) ++lo;
            else --hi;
        }
    }
    return out;
}

int main() {
    for (const auto& t : threeSum({-1, 0, 1, 2, -1, -4}))
        cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    cout << "\n";   // [-1,-1,2] [-1,0,1]
    return 0;
}
