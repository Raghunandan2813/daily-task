/*
 * 101. Permutations
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * Generate all n! orderings of an array of distinct integers.
 *
 * Approach: in-place swapping. At depth d, swap each remaining element into
 * position d, recurse on the suffix, then swap back. This avoids a separate
 * "used" array and any extra copying.
 *
 * Time: O(n * n!)   Space: O(n) recursion
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(vector<int>& nums, int d, vector<vector<int>>& out) {
    if (d == (int)nums.size()) { out.push_back(nums); return; }
    for (int i = d; i < (int)nums.size(); ++i) {
        swap(nums[d], nums[i]);
        dfs(nums, d + 1, out);
        swap(nums[d], nums[i]);                     // undo
    }
}

vector<vector<int>> permute(vector<int> nums) {
    vector<vector<int>> out;
    dfs(nums, 0, out);
    return out;
}

int main() {
    for (const auto& p : permute({1, 2, 3})) {
        for (int x : p) cout << x;
        cout << " ";
    }
    cout << "\n";   // 123 132 213 231 321 312
    return 0;
}
