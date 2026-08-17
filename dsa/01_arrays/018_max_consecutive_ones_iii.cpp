/*
 * 018. Max Consecutive Ones III
 * Topic: Arrays | Difficulty: Medium
 *
 * Given a binary array and an integer k, return the length of the longest
 * subarray of 1s obtainable by flipping at most k zeroes.
 *
 * Approach: sliding window. Grow the right edge and count zeroes inside the
 * window; while the count exceeds k, advance the left edge. The largest valid
 * window is the answer.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int longestOnes(const vector<int>& nums, int k) {
    int left = 0, zeros = 0, best = 0;
    for (int right = 0; right < (int)nums.size(); ++right) {
        if (nums[right] == 0) ++zeros;
        while (zeros > k) {
            if (nums[left] == 0) --zeros;
            ++left;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

int main() {
    cout << longestOnes({1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2) << "\n";   // 6
    return 0;
}
