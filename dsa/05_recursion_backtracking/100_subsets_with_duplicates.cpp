/*
 * 100. Subsets II (with Duplicates)
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * Generate all unique subsets when the input may contain repeated values.
 *
 * Approach: sort first so equal values are adjacent, then at each recursion
 * level skip a value identical to the previous sibling choice. That prevents
 * generating the same multiset twice without needing a deduplicating set.
 *
 * Time: O(n * 2^n)   Space: O(n) recursion
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(const vector<int>& nums, int start, vector<int>& cur,
                vector<vector<int>>& out) {
    out.push_back(cur);
    for (int i = start; i < (int)nums.size(); ++i) {
        if (i > start && nums[i] == nums[i - 1]) continue;   // skip duplicate sibling
        cur.push_back(nums[i]);
        dfs(nums, i + 1, cur, out);
        cur.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> out;
    vector<int> cur;
    dfs(nums, 0, cur, out);
    return out;
}

int main() {
    for (const auto& s : subsetsWithDup({1, 2, 2})) {
        cout << "{";
        for (int x : s) cout << x << " ";
        cout << "} ";
    }
    cout << "\n";   // {} {1} {1 2} {1 2 2} {2} {2 2}
    return 0;
}
