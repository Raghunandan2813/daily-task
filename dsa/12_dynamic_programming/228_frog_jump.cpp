/*
 * 228. Frog Jump (Minimum Energy)
 * Topic: Dynamic Programming | Difficulty: Easy
 *
 * A frog on stone 0 jumps to stone n-1, moving one or two stones at a time and
 * spending |height[i] - height[j]| energy per jump. Minimise the total.
 *
 * Approach: dp[i] is the cheapest cost to reach stone i, coming from either i-1
 * or i-2. As with the stairs problems, only the last two entries are ever read.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int minEnergy(const vector<int>& height) {
    int n = height.size();
    if (n == 1) return 0;
    int prev2 = 0, prev1 = abs(height[1] - height[0]);
    for (int i = 2; i < n; ++i) {
        int viaOne = prev1 + abs(height[i] - height[i - 1]);
        int viaTwo = prev2 + abs(height[i] - height[i - 2]);
        int cur = min(viaOne, viaTwo);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    cout << minEnergy({10, 20, 30, 10}) << "\n";       // 20
    cout << minEnergy({30, 10, 60, 10, 60, 50}) << "\n";   // 40
    return 0;
}
