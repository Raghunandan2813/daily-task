/*
 * 298. Pow(x, n)
 * Topic: Math | Difficulty: Medium
 *
 * Compute x raised to an integer power n, which may be negative.
 *
 * Approach: binary exponentiation over doubles. A negative exponent is handled
 * by inverting the base, but n is first widened to long long - negating INT_MIN
 * as a plain int would overflow, which is the classic trap in this problem.
 *
 * Time: O(log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    long long exponent = n;                          // widen before negating
    if (exponent < 0) { x = 1.0 / x; exponent = -exponent; }
    double result = 1.0;
    while (exponent > 0) {
        if (exponent & 1) result *= x;
        x *= x;
        exponent >>= 1;
    }
    return result;
}

int main() {
    cout << myPow(2.0, 10) << "\n";        // 1024
    cout << myPow(2.1, 3) << "\n";         // 9.261
    cout << myPow(2.0, -2) << "\n";        // 0.25
    cout << myPow(1.0, INT_MIN) << "\n";   // 1
    return 0;
}
