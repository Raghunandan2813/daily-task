/*
 * 276. Single Number III
 * Topic: Bit Manipulation | Difficulty: Medium
 *
 * Exactly two elements appear once; every other appears twice. Find both.
 *
 * Approach: XOR everything to get a ^ b, the XOR of the two loners. Any set bit
 * in that result is a position where a and b differ, so isolating the lowest such
 * bit (via x & -x) splits the array into two groups - one containing a, the
 * other b - each of which reduces to the ordinary Single Number problem.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumberIII(const vector<int>& nums) {
    unsigned int xorAll = 0;
    for (int x : nums) xorAll ^= (unsigned int)x;
    unsigned int lowestDiffBit = xorAll & (~xorAll + 1);   // isolate lowest set bit

    int a = 0, b = 0;
    for (int x : nums) {
        if ((unsigned int)x & lowestDiffBit) a ^= x;
        else b ^= x;
    }
    return {a, b};
}

int main() {
    vector<int> r = singleNumberIII({1, 2, 1, 3, 2, 5});
    sort(r.begin(), r.end());
    cout << r[0] << " " << r[1] << "\n";   // 3 5
    return 0;
}
