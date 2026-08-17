/*
 * 277. Generate Subsets Using Bitmasks
 * Topic: Bit Manipulation | Difficulty: Medium
 *
 * Enumerate the power set without recursion.
 *
 * Approach: each of the 2^n integers from 0 to 2^n - 1 is a membership mask -
 * bit i set means element i is included. Iterating the masks therefore walks
 * every subset exactly once, with no call stack at all.
 *
 * Time: O(n * 2^n)   Space: O(1) beyond the output
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > subsets(const vector<int>& nums) {
    int n = nums.size();
    vector<vector<int> > out;
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i)) subset.push_back(nums[i]);
        out.push_back(subset);
    }
    return out;
}

int main() {
    for (const auto& s : subsets({1, 2, 3})) {
        cout << "{";
        for (int x : s) cout << x << " ";
        cout << "} ";
    }
    cout << "\n";   // {} {1} {2} {1 2} {3} {1 3} {2 3} {1 2 3}
    return 0;
}
