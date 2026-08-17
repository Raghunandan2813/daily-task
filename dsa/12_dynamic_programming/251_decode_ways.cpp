/*
 * 251. Decode Ways
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * 'A' maps to 1 through 'Z' to 26. Count the ways to decode a digit string.
 *
 * Approach: a Fibonacci-shaped recurrence with validity guards. The character at
 * i can stand alone if it is not '0', and can pair with the one before it if
 * that two-digit value lies in 10..26. Sum whichever options are legal.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int numDecodings(const string& s) {
    if (s.empty() || s[0] == '0') return 0;
    int prev2 = 1, prev1 = 1;                        // ways for "" and s[0..0]
    for (int i = 1; i < (int)s.size(); ++i) {
        int cur = 0;
        if (s[i] != '0') cur += prev1;               // stands alone
        int pair = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if (pair >= 10 && pair <= 26) cur += prev2;  // pairs with the previous
        if (cur == 0) return 0;                      // undecodable
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    cout << numDecodings("12") << "\n";     // 2
    cout << numDecodings("226") << "\n";    // 3
    cout << numDecodings("06") << "\n";     // 0
    return 0;
}
