/*
 * 001. Two Sum
 * Topic: Arrays | Difficulty: Easy
 *
 * Given an array of integers and a target value, return the indices of the two
 * numbers that add up to the target. Exactly one valid answer exists and the
 * same element may not be used twice.
 *
 * Approach: one pass with a hash map from value -> index. For each element x we
 * look for (target - x) among the elements already seen.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < (int)nums.size(); ++i) {
        auto it = seen.find(target - nums[i]);
        if (it != seen.end()) return {it->second, i};
        seen[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans = twoSum(nums, 9);
    cout << ans[0] << " " << ans[1] << "\n";   // 0 1
    return 0;
}
