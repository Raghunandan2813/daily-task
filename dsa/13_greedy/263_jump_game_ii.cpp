/*
 * 263. Jump Game II (Minimum Jumps)
 * Topic: Greedy | Difficulty: Medium
 *
 * Return the minimum number of jumps needed to reach the last index, assuming it
 * is always reachable.
 *
 * Approach: an implicit BFS in layers. `currentEnd` marks where the present jump
 * can take us at most; while scanning within it we accumulate `furthest`, the
 * reach of the next layer. Crossing currentEnd means a jump has been spent, so
 * the counter increments exactly once per BFS level.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int jump(const vector<int>& nums) {
    int jumps = 0, currentEnd = 0, furthest = 0;
    for (int i = 0; i + 1 < (int)nums.size(); ++i) {
        furthest = max(furthest, i + nums[i]);
        if (i == currentEnd) { ++jumps; currentEnd = furthest; }
    }
    return jumps;
}

int main() {
    cout << jump({2, 3, 1, 1, 4}) << "\n";   // 2
    cout << jump({2, 3, 0, 1, 4}) << "\n";   // 2
    cout << jump({0}) << "\n";               // 0
    return 0;
}
