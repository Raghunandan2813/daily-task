/*
 * 099. Subsets (Power Set)
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * Generate all 2^n subsets of an array of distinct integers.
 *
 * Approach: backtracking with an include/exclude decision at each index. Push the
 * current element, recurse, then pop to undo - the classic choose/unchoose
 * pattern.
 *
 * Time: O(n * 2^n)   Space: O(n) recursion
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(const vector<int>& nums, int i, vector<int>& cur,
                vector<vector<int>>& out) {
    if (i == (int)nums.size()) { out.push_back(cur); return; }
    dfs(nums, i + 1, cur, out);                    // exclude nums[i]
    cur.push_back(nums[i]);                        // include nums[i]
    dfs(nums, i + 1, cur, out);
    cur.pop_back();
}

vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> out;
    vector<int> cur;
    dfs(nums, 0, cur, out);
    return out;
}

int main() {
    for (const auto& s : subsets({1, 2, 3})) {
        cout << "{";
        for (int x : s) cout << x << " ";
        cout << "} ";
    }
    cout << "\n";   // 8 subsets including the empty one
    return 0;
}
