/*
 * 133. Nth Root of a Number
 * Topic: Binary Search | Difficulty: Medium
 *
 * Find the integer n-th root of m, or -1 if m is not a perfect n-th power.
 *
 * Approach: binary search on the root over [1, m]. Exponentiation is done with a
 * helper that aborts as soon as the running product exceeds the target, which
 * both prunes the work and prevents overflow.
 *
 * Time: O(n log m)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

// Returns -1 if base^exp < target, 0 if equal, 1 if greater.
static int comparePower(long long base, int exp, long long target) {
    long long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
        if (result > target) return 1;               // early exit, no overflow
    }
    return result == target ? 0 : -1;
}

int nthRoot(int n, int m) {
    int lo = 1, hi = m;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int cmp = comparePower(mid, n, m);
        if (cmp == 0) return mid;
        if (cmp < 0) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main() {
    cout << nthRoot(3, 27) << "\n";     // 3
    cout << nthRoot(4, 69) << "\n";     // -1
    cout << nthRoot(2, 100000) << "\n"; // -1
    cout << nthRoot(2, 65536) << "\n";  // 256
    return 0;
}
