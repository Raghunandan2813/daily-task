/*
 * 102. Permutations II (with Duplicates)
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * Generate all distinct permutations when the input may contain repeats.
 *
 * Approach: sort, then use a `used` array and skip nums[i] whenever it equals
 * nums[i-1] and that predecessor is not currently used. This forces equal values
 * to be placed in a fixed left-to-right order, so each multiset arrangement is
 * produced exactly once.
 *
 * Time: O(n * n!) worst case   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(const vector<int>& nums, vector<bool>& used, vector<int>& cur,
                vector<vector<int>>& out) {
    if (cur.size() == nums.size()) { out.push_back(cur); return; }
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        used[i] = true;
        cur.push_back(nums[i]);
        dfs(nums, used, cur, out);
        cur.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    vector<int> cur;
    vector<vector<int>> out;
    dfs(nums, used, cur, out);
    return out;
}

int main() {
    for (const auto& p : permuteUnique({1, 1, 2})) {
        for (int x : p) cout << x;
        cout << " ";
    }
    cout << "\n";   // 112 121 211
    return 0;
}
