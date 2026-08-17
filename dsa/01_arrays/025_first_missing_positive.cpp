/*
 * 025. First Missing Positive
 * Topic: Arrays | Difficulty: Hard
 *
 * Find the smallest positive integer absent from an unsorted array, in O(n) time
 * and O(1) extra space.
 *
 * Approach: cyclic sort. Repeatedly place each value v in [1, n] at index v-1 by
 * swapping. Afterwards the first index i whose value is not i+1 gives the answer;
 * if all match, the answer is n+1.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i)
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    for (int i = 0; i < n; ++i)
        if (nums[i] != i + 1) return i + 1;
    return n + 1;
}

int main() {
    cout << firstMissingPositive({1, 2, 0}) << "\n";          // 3
    cout << firstMissingPositive({3, 4, -1, 1}) << "\n";      // 2
    cout << firstMissingPositive({7, 8, 9, 11, 12}) << "\n";  // 1
    return 0;
}
