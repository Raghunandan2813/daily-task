/*
 * 241. Longest Increasing Subsequence (O(n log n))
 * Topic: Dynamic Programming | Difficulty: Hard
 *
 * The same problem solved with patience sorting.
 *
 * Approach: maintain `tails`, where tails[k] is the smallest possible tail of an
 * increasing subsequence of length k+1. For each value, binary search for the
 * first tail that is not smaller and overwrite it - keeping tails as small as
 * possible leaves the most room to extend later. Its length is the answer, though
 * its contents are not necessarily a valid subsequence.
 *
 * Time: O(n log n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(const vector<int>& nums) {
    vector<int> tails;
    for (int x : nums) {
        vector<int>::iterator it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);   // extends the longest run
        else *it = x;                                // tightens an existing one
    }
    return tails.size();
}

int main() {
    cout << lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) << "\n";   // 4
    cout << lengthOfLIS({0, 1, 0, 3, 2, 3}) << "\n";             // 4
    return 0;
}
