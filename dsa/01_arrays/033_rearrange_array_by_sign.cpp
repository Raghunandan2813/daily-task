/*
 * 033. Rearrange Array Elements by Sign
 * Topic: Arrays | Difficulty: Medium
 *
 * The array has an equal number of positive and negative values. Rearrange it so
 * that signs alternate starting with a positive, preserving the relative order
 * within each sign group.
 *
 * Approach: positives belong at even indices and negatives at odd indices. Walk
 * the input once with two independent write cursors.
 *
 * Time: O(n)   Space: O(n) for the output
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeBySign(const vector<int>& nums) {
    int n = nums.size();
    vector<int> out(n);
    int pos = 0, neg = 1;
    for (int x : nums) {
        if (x >= 0) { out[pos] = x; pos += 2; }
        else { out[neg] = x; neg += 2; }
    }
    return out;
}

int main() {
    for (int x : rearrangeBySign({3, 1, -2, -5, 2, -4})) cout << x << " ";
    cout << "\n";   // 3 -2 1 -5 2 -4
    return 0;
}
