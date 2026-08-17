/*
 * 045. Roman to Integer
 * Topic: Strings | Difficulty: Easy
 *
 * Convert a Roman numeral string into its integer value.
 *
 * Approach: scan left to right. A symbol whose value is smaller than the symbol
 * after it is a subtractive prefix (IV, IX, XL, ...) and is subtracted; every
 * other symbol is added.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int romanToInt(const string& s) {
    unordered_map<char, int> val = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                    {'C', 100}, {'D', 500}, {'M', 1000}};
    int total = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (i + 1 < (int)s.size() && val[s[i]] < val[s[i + 1]]) total -= val[s[i]];
        else total += val[s[i]];
    }
    return total;
}

int main() {
    cout << romanToInt("III") << "\n";        // 3
    cout << romanToInt("LVIII") << "\n";      // 58
    cout << romanToInt("MCMXCIV") << "\n";    // 1994
    return 0;
}
