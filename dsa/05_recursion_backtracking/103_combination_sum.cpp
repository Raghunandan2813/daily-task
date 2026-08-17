/*
 * 103. Combination Sum
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * Given distinct candidates, find all combinations summing to a target. Each
 * candidate may be reused any number of times.
 *
 * Approach: backtracking where recursing on the same index allows reuse, and
 * never revisiting earlier indices keeps combinations sorted and unique. Sorting
 * lets us break out of the loop as soon as a candidate exceeds the remainder.
 *
 * Time: exponential in the target/candidate ratio   Space: O(target) recursion
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(const vector<int>& cand, int start, int remain,
                vector<int>& cur, vector<vector<int>>& out) {
    if (remain == 0) { out.push_back(cur); return; }
    for (int i = start; i < (int)cand.size(); ++i) {
        if (cand[i] > remain) break;                // sorted, so the rest are too big
        cur.push_back(cand[i]);
        dfs(cand, i, remain - cand[i], cur, out);   // i, not i+1: reuse allowed
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> cur;
    vector<vector<int>> out;
    dfs(candidates, 0, target, cur, out);
    return out;
}

int main() {
    for (const auto& c : combinationSum({2, 3, 6, 7}, 7)) {
        cout << "[";
        for (int x : c) cout << x << " ";
        cout << "] ";
    }
    cout << "\n";   // [2 2 3] [7]
    return 0;
}
