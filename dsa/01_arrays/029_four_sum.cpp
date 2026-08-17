/*
 * 029. 4Sum
 * Topic: Arrays | Difficulty: Medium
 *
 * Find all unique quadruplets summing to a given target.
 *
 * Approach: sort, fix the outer two indices with nested loops, then close the
 * quadruplet with a two-pointer scan. Duplicate values are skipped at each of
 * the four levels so the result contains no repeats. long long guards the sum
 * against overflow.
 *
 * Time: O(n^3)   Space: O(1) extra
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> out;
    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int lo = j + 1, hi = n - 1;
            while (lo < hi) {
                long long sum = (long long)nums[i] + nums[j] + nums[lo] + nums[hi];
                if (sum == target) {
                    out.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo] == nums[lo + 1]) ++lo;
                    while (lo < hi && nums[hi] == nums[hi - 1]) --hi;
                    ++lo; --hi;
                } else if (sum < target) ++lo;
                else --hi;
            }
        }
    }
    return out;
}

int main() {
    for (const auto& q : fourSum({1, 0, -1, 0, -2, 2}, 0))
        cout << "[" << q[0] << "," << q[1] << "," << q[2] << "," << q[3] << "] ";
    cout << "\n";   // [-2,-1,1,2] [-2,0,0,2] [-1,0,0,1]
    return 0;
}
