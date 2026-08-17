/*
 * 020. Longest Consecutive Sequence
 * Topic: Arrays | Difficulty: Medium
 *
 * Return the length of the longest run of consecutive integers present in an
 * unsorted array, in O(n) time.
 *
 * Approach: put everything in a hash set. Only start counting from values x
 * where x-1 is absent - those are the true starts of a run - so every element is
 * visited a constant number of times overall.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(const vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int best = 0;
    for (int x : s) {
        if (s.count(x - 1)) continue;          // not the start of a run
        int len = 1, cur = x;
        while (s.count(cur + 1)) { ++cur; ++len; }
        best = max(best, len);
    }
    return best;
}

int main() {
    cout << longestConsecutive({100, 4, 200, 1, 3, 2}) << "\n";   // 4
    return 0;
}
