/*
 * 262. Jump Game
 * Topic: Greedy | Difficulty: Medium
 *
 * nums[i] is the maximum jump length from index i. Decide whether the last index
 * is reachable from the first.
 *
 * Approach: sweep left to right tracking the furthest index reachable so far. If
 * the sweep ever reaches an index beyond that frontier, the array is
 * disconnected there and the answer is no. There is no need to track *how* we
 * got anywhere - only how far we can get.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

bool canJump(const vector<int>& nums) {
    int furthest = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (i > furthest) return false;              // a gap we cannot cross
        furthest = max(furthest, i + nums[i]);
    }
    return true;
}

int main() {
    cout << canJump({2, 3, 1, 1, 4}) << "\n";   // 1
    cout << canJump({3, 2, 1, 0, 4}) << "\n";   // 0
    return 0;
}
