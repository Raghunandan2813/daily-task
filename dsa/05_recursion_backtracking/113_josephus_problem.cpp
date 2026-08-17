/*
 * 113. Josephus Problem
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * n people stand in a circle and every k-th person is eliminated until one
 * remains. Find the survivor's original position (1-indexed).
 *
 * Approach: the recurrence J(1) = 0 and J(n) = (J(n-1) + k) % n works in
 * 0-indexed terms. After one elimination the problem is the same with n-1
 * people, just rotated by k positions. Iterating avoids deep recursion.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k) {
    int survivor = 0;                             // 0-indexed answer for n = 1
    for (int size = 2; size <= n; ++size)
        survivor = (survivor + k) % size;
    return survivor + 1;                          // convert to 1-indexed
}

int main() {
    cout << josephus(5, 2) << "\n";    // 3
    cout << josephus(7, 3) << "\n";    // 4
    cout << josephus(1, 5) << "\n";    // 1
    return 0;
}
