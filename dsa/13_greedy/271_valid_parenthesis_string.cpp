/*
 * 271. Valid Parenthesis String (with Wildcards)
 * Topic: Greedy | Difficulty: Hard
 *
 * '*' may act as '(', ')' or an empty string. Decide whether the string can be
 * made valid.
 *
 * Approach: track the range of possible open-bracket counts with two counters.
 * `low` assumes every '*' closes a bracket and `high` assumes every '*' opens
 * one. If high ever drops below zero there are too many ')' to recover; low is
 * clamped at zero because a negative count is not a real possibility. The string
 * is valid when zero stays within the range at the end.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

bool checkValidString(const string& s) {
    int low = 0, high = 0;
    for (char c : s) {
        if (c == '(') { ++low; ++high; }
        else if (c == ')') { --low; --high; }
        else { --low; ++high; }                       // '*' spans both
        if (high < 0) return false;                   // unmatched ')'
        low = max(low, 0);
    }
    return low == 0;
}

int main() {
    cout << checkValidString("()") << "\n";     // 1
    cout << checkValidString("(*)") << "\n";    // 1
    cout << checkValidString("(*))") << "\n";   // 1
    cout << checkValidString(")(") << "\n";     // 0
    return 0;
}
