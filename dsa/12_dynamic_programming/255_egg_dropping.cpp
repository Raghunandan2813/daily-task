/*
 * 255. Egg Dropping Puzzle
 * Topic: Dynamic Programming | Difficulty: Hard
 *
 * With k eggs and n floors, find the minimum number of drops that guarantees
 * identifying the critical floor in the worst case.
 *
 * Approach: invert the question. Instead of "how many drops for n floors", ask
 * "how many floors can m drops with k eggs cover". One drop either breaks the
 * egg (covering the floors below with k-1 eggs) or does not (covering the floors
 * above with k eggs), plus the current floor:
 *     dp[k] = dp[k] + dp[k-1] + 1
 * Increment the drop count until the coverage reaches n. This is O(k * n) rather
 * than the O(k * n^2) of the direct formulation.
 *
 * Time: O(k * n)   Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;

int eggDrop(int eggs, int floors) {
    vector<int> dp(eggs + 1, 0);                     // floors covered per egg count
    int drops = 0;
    while (dp[eggs] < floors) {
        ++drops;
        for (int e = eggs; e >= 1; --e)              // downwards: dp[e-1] must be old
            dp[e] = dp[e] + dp[e - 1] + 1;
    }
    return drops;
}

int main() {
    cout << eggDrop(2, 10) << "\n";     // 4
    cout << eggDrop(2, 100) << "\n";    // 14
    cout << eggDrop(3, 14) << "\n";     // 4
    cout << eggDrop(1, 25) << "\n";     // 25
    return 0;
}
