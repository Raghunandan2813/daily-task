/*
 * 053. String to Integer (atoi)
 * Topic: Strings | Difficulty: Medium
 *
 * Parse a leading integer out of a string: skip whitespace, accept one optional
 * sign, read digits, and clamp to the 32-bit range on overflow.
 *
 * Approach: straightforward scan. Overflow is detected before it happens by
 * comparing the accumulator against INT_MAX/10 rather than by letting it wrap.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int myAtoi(const string& s) {
    int i = 0, n = s.size();
    while (i < n && s[i] == ' ') ++i;
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) sign = (s[i++] == '-') ? -1 : 1;
    int result = 0;
    while (i < n && isdigit((unsigned char)s[i])) {
        int digit = s[i] - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7))
            return sign == 1 ? INT_MAX : INT_MIN;
        result = result * 10 + digit;
        ++i;
    }
    return sign * result;
}

int main() {
    cout << myAtoi("42") << "\n";              // 42
    cout << myAtoi("   -42") << "\n";          // -42
    cout << myAtoi("4193 with words") << "\n"; // 4193
    cout << myAtoi("91283472332") << "\n";     // 2147483647
    return 0;
}
