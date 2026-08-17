/*
 * 055. Add Binary
 * Topic: Strings | Difficulty: Easy
 *
 * Add two binary strings and return their sum as a binary string.
 *
 * Approach: walk both strings from the least significant end, summing the two
 * bits and the carry. Build the result reversed and flip it at the end.
 *
 * Time: O(max(n, m))   Space: O(max(n, m))
 */
#include <bits/stdc++.h>
using namespace std;

string addBinary(const string& a, const string& b) {
    string out;
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        out += char('0' + (sum % 2));
        carry = sum / 2;
    }
    reverse(out.begin(), out.end());
    return out;
}

int main() {
    cout << addBinary("11", "1") << "\n";        // 100
    cout << addBinary("1010", "1011") << "\n";   // 10101
    return 0;
}
