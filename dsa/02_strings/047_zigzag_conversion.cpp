/*
 * 047. Zigzag Conversion
 * Topic: Strings | Difficulty: Medium
 *
 * Write the string in a zigzag pattern across numRows rows, then read it row by
 * row.
 *
 * Approach: simulate. Append each character to its current row and flip the
 * vertical direction whenever the top or bottom row is reached.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

string convert(const string& s, int numRows) {
    if (numRows <= 1) return s;
    vector<string> rows(numRows);
    int row = 0, step = 1;
    for (char c : s) {
        rows[row] += c;
        if (row == 0) step = 1;
        else if (row == numRows - 1) step = -1;
        row += step;
    }
    string out;
    for (const string& r : rows) out += r;
    return out;
}

int main() {
    cout << convert("PAYPALISHIRING", 3) << "\n";   // PAHNAPLSIIGYIR
    cout << convert("PAYPALISHIRING", 4) << "\n";   // PINALSIGYAHRPI
    return 0;
}
