/*
 * 123. Integer Square Root
 * Topic: Binary Search | Difficulty: Easy
 *
 * Compute floor(sqrt(x)) for a non-negative integer without using a math library
 * square root.
 *
 * Approach: binary search on the answer over [1, x]. The predicate
 * "mid*mid <= x" is monotone, so we keep the largest mid that satisfies it. The
 * product is computed in long long to avoid overflow.
 *
 * Time: O(log x)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if (x < 2) return x;
    int lo = 1, hi = x / 2, ans = 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if ((long long)mid * mid <= x) { ans = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    return ans;
}

int main() {
    cout << mySqrt(4) << "\n";        // 2
    cout << mySqrt(8) << "\n";        // 2
    cout << mySqrt(2147395599) << "\n";   // 46339
    return 0;
}
