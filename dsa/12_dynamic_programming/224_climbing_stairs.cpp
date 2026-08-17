/*
 * 224. Climbing Stairs
 * Topic: Dynamic Programming | Difficulty: Easy
 *
 * You can climb 1 or 2 steps at a time. Count the distinct ways to reach step n.
 *
 * Approach: the last move to step i came from either i-1 or i-2, so
 * ways(i) = ways(i-1) + ways(i-2) - the Fibonacci recurrence. Only the previous
 * two values matter, so two variables suffice.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

long long climbStairs(int n) {
    if (n <= 2) return n;
    long long prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; ++i) {
        long long cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    cout << climbStairs(2) << "\n";    // 2
    cout << climbStairs(3) << "\n";    // 3
    cout << climbStairs(10) << "\n";   // 89
    return 0;
}
