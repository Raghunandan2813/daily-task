/*
 * 294. Fast Modular Exponentiation
 * Topic: Math | Difficulty: Medium
 *
 * Compute (base^exponent) mod m efficiently.
 *
 * Approach: binary exponentiation. Squaring the base each round and multiplying
 * into the result only where the exponent has a set bit turns O(n) multiplies
 * into O(log n). Reducing modulo m at every step keeps the values small enough
 * that a 64-bit product cannot overflow.
 *
 * Time: O(log exponent)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

long long modPow(long long base, long long exponent, long long mod) {
    long long result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent & 1) result = result * base % mod;
        base = base * base % mod;
        exponent >>= 1;
    }
    return result;
}

int main() {
    cout << modPow(2, 10, 1000000007LL) << "\n";      // 1024
    cout << modPow(3, 200, 1000000007LL) << "\n";     // 764735567
    cout << modPow(2, 0, 7) << "\n";                  // 1
    return 0;
}
