/*
 * 013. Sort Colors (Dutch National Flag)
 * Topic: Arrays | Difficulty: Medium
 *
 * Sort an array containing only 0, 1 and 2 in a single pass without a library
 * sort.
 *
 * Approach: three pointers. Everything before `low` is 0, everything after
 * `high` is 2, and [low, mid) holds 1s. Scan with `mid`, swapping 0s to the
 * front and 2s to the back.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1) ++mid;
        else swap(nums[mid], nums[high--]);
    }
}

int main() {
    vector<int> v = {2, 0, 2, 1, 1, 0};
    sortColors(v);
    for (int x : v) cout << x << " ";   // 0 0 1 1 2 2
    cout << "\n";
    return 0;
}
