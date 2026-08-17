/*
 * 024. Find All Duplicates in an Array
 * Topic: Arrays | Difficulty: Medium
 *
 * Every value in the array is in [1, n] and appears once or twice. Return all
 * values appearing twice, using O(1) extra space.
 *
 * Approach: use the sign of the array itself as a visited marker. For value v,
 * negate the entry at index v-1; if it is already negative we have seen v before.
 *
 * Time: O(n)   Space: O(1) extra
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> nums) {
    vector<int> out;
    for (int i = 0; i < (int)nums.size(); ++i) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) out.push_back(idx + 1);
        else nums[idx] = -nums[idx];
    }
    return out;
}

int main() {
    for (int x : findDuplicates({4, 3, 2, 7, 8, 2, 3, 1})) cout << x << " ";
    cout << "\n";   // 2 3
    return 0;
}
