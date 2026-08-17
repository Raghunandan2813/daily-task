/*
 * 296. Reverse Integer
 * Topic: Math | Difficulty: Medium
 *
 * Reverse the digits of a signed 32-bit integer, returning 0 if the result
 * overflows.
 *
 * Approach: peel digits off with % 10 and push them onto the result with * 10.
 * The overflow test must happen *before* the multiply - checking afterwards
 * would already be undefined behaviour - so compare the accumulator against
 * INT_MAX/10 first.
 *
 * Time: O(number of digits)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int reverseInteger(int x) {
    int result = 0;
    while (x != 0) {
        int digit = x % 10;                          // keeps the sign in C++11
        x /= 10;
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) return 0;
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) return 0;
        result = result * 10 + digit;
    }
    return result;
}

int main() {
    cout << reverseInteger(123) << "\n";          // 321
    cout << reverseInteger(-123) << "\n";         // -321
    cout << reverseInteger(120) << "\n";          // 21
    cout << reverseInteger(1534236469) << "\n";   // 0 (overflows)
    return 0;
}
