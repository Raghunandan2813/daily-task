/*
 * 004. Move Zeroes
 * Topic: Arrays | Difficulty: Easy
 *
 * Move all zeroes to the end of the array while keeping the relative order of
 * the non-zero elements. Must be done in place.
 *
 * Approach: two pointers. `write` marks the next slot for a non-zero value; scan
 * with `read` and swap every non-zero element into position.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int write = 0;
    for (int read = 0; read < (int)nums.size(); ++read)
        if (nums[read] != 0) swap(nums[write++], nums[read]);
}

int main() {
    vector<int> v = {0, 1, 0, 3, 12};
    moveZeroes(v);
    for (int x : v) cout << x << " ";   // 1 3 12 0 0
    cout << "\n";
    return 0;
}
