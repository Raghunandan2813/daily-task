/*
 * 005. Rotate Array by K Steps
 * Topic: Arrays | Difficulty: Medium
 *
 * Rotate the array to the right by k steps, in place.
 *
 * Approach: the reversal trick. Reverse the whole array, then reverse the first
 * k elements and the remaining n-k elements. k is reduced modulo n first.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;
    k %= n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    rotate(v, 3);
    for (int x : v) cout << x << " ";   // 5 6 7 1 2 3 4
    cout << "\n";
    return 0;
}
