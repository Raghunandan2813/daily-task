/*
 * 054. Multiply Strings
 * Topic: Strings | Difficulty: Medium
 *
 * Multiply two non-negative integers given as strings, without converting them
 * to a built-in numeric type.
 *
 * Approach: schoolbook multiplication into a digit buffer of size n+m. The
 * product of digits i and j always lands in positions i+j and i+j+1, so carries
 * can be resolved locally as we go.
 *
 * Time: O(n * m)   Space: O(n + m)
 */
#include <bits/stdc++.h>
using namespace std;

string multiply(const string& a, const string& b) {
    if (a == "0" || b == "0") return "0";
    int n = a.size(), m = b.size();
    vector<int> digits(n + m, 0);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0') + digits[i + j + 1];
            digits[i + j + 1] = mul % 10;
            digits[i + j] += mul / 10;
        }
    }
    string out;
    for (int d : digits) {
        if (out.empty() && d == 0) continue;
        out += char('0' + d);
    }
    return out;
}

int main() {
    cout << multiply("2", "3") << "\n";          // 6
    cout << multiply("123", "456") << "\n";      // 56088
    return 0;
}
