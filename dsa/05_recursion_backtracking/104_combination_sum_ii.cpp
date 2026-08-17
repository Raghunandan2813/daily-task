/*
 * 104. Combination Sum II
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * Candidates may repeat, but each array element may be used at most once. Find
 * all unique combinations summing to the target.
 *
 * Approach: sort, recurse on i+1 so each element is consumed once, and skip a
 * candidate equal to the previous sibling at the same level so duplicate
 * combinations are never generated.
 *
 * Time: O(2^n) worst case   Space: O(n) recursion
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(const vector<int>& cand, int start, int remain,
                vector<int>& cur, vector<vector<int>>& out) {
    if (remain == 0) { out.push_back(cur); return; }
    for (int i = start; i < (int)cand.size(); ++i) {
        if (i > start && cand[i] == cand[i - 1]) continue;   // duplicate sibling
        if (cand[i] > remain) break;
        cur.push_back(cand[i]);
        dfs(cand, i + 1, remain - cand[i], cur, out);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> cur;
    vector<vector<int>> out;
    dfs(candidates, 0, target, cur, out);
    return out;
}

int main() {
    for (const auto& c : combinationSum2({10, 1, 2, 7, 6, 1, 5}, 8)) {
        cout << "[";
        for (int x : c) cout << x << " ";
        cout << "] ";
    }
    cout << "\n";   // [1 1 6] [1 2 5] [1 7] [2 6]
    return 0;
}
