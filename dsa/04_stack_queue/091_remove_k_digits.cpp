/*
 * 091. Remove K Digits
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * Remove k digits from a number string so the remaining number is as small as
 * possible.
 *
 * Approach: greedy with a monotonic increasing stack. A digit larger than the
 * one following it should go, because removing it lowers a more significant
 * place. Any budget left over is spent on the trailing digits.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

string removeKdigits(const string& num, int k) {
    string st;
    for (char c : num) {
        while (k > 0 && !st.empty() && st.back() > c) { st.pop_back(); --k; }
        st.push_back(c);
    }
    st.resize(st.size() - k);                     // spend any leftover budget
    int i = 0;
    while (i < (int)st.size() && st[i] == '0') ++i;   // strip leading zeroes
    string out = st.substr(i);
    return out.empty() ? "0" : out;
}

int main() {
    cout << removeKdigits("1432219", 3) << "\n";   // 1219
    cout << removeKdigits("10200", 1) << "\n";     // 200
    cout << removeKdigits("10", 2) << "\n";        // 0
    return 0;
}
