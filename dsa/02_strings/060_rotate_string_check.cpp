/*
 * 060. Rotate String
 * Topic: Strings | Difficulty: Easy
 *
 * Decide whether string b is a rotation of string a.
 *
 * Approach: every rotation of a appears as a substring of a+a. So the check is
 * simply "same length" plus "b occurs inside a doubled".
 *
 * Time: O(n^2) with std::string::find, O(n) if KMP is used for the search
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

bool rotateString(const string& a, const string& b) {
    return a.size() == b.size() && (a + a).find(b) != string::npos;
}

int main() {
    cout << rotateString("abcde", "cdeab") << "\n";   // 1
    cout << rotateString("abcde", "abced") << "\n";   // 0
    return 0;
}
