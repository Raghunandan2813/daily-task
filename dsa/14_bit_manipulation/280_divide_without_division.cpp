/*
 * 280. Divide Two Integers Without Division
 * Topic: Bit Manipulation | Difficulty: Medium
 *
 * Compute the integer quotient without using /, * or %.
 *
 * Approach: repeated subtraction is too slow, so double the divisor (by
 * shifting) to subtract the largest possible multiple each round - effectively
 * long division in binary. The work is done in long long with positive
 * magnitudes so INT_MIN does not overflow when negated, and the one overflowing
 * result is special-cased.
 *
 * Time: O(log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;   // would overflow
    bool negative = (dividend < 0) != (divisor < 0);
    long long a = llabs((long long)dividend);
    long long b = llabs((long long)divisor);

    long long quotient = 0;
    while (a >= b) {
        long long chunk = b, multiple = 1;
        while (a >= (chunk << 1)) { chunk <<= 1; multiple <<= 1; }
        a -= chunk;
        quotient += multiple;
    }
    return (int)(negative ? -quotient : quotient);
}

int main() {
    cout << divide(10, 3) << "\n";          // 3
    cout << divide(7, -3) << "\n";          // -2
    cout << divide(INT_MIN, -1) << "\n";    // 2147483647
    cout << divide(-2147483648, 2) << "\n"; // -1073741824
    return 0;
}
