/*
 * 046. Integer to Roman
 * Topic: Strings | Difficulty: Medium
 *
 * Convert an integer in [1, 3999] into a Roman numeral.
 *
 * Approach: greedy over a table of values sorted descending that already
 * includes the subtractive forms (900 = CM, 400 = CD, ...). Repeatedly take the
 * largest value that still fits.
 *
 * Time: O(1) - the table is fixed   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    const int vals[]  = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char* syms[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
                          "X", "IX", "V", "IV", "I"};
    string out;
    for (int i = 0; i < 13; ++i)
        while (num >= vals[i]) { out += syms[i]; num -= vals[i]; }
    return out;
}

int main() {
    cout << intToRoman(3) << "\n";       // III
    cout << intToRoman(58) << "\n";      // LVIII
    cout << intToRoman(1994) << "\n";    // MCMXCIV
    return 0;
}
