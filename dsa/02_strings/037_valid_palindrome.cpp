/*
 * 037. Valid Palindrome
 * Topic: Strings | Difficulty: Easy
 *
 * Decide whether a string is a palindrome, considering only alphanumeric
 * characters and ignoring case.
 *
 * Approach: two pointers that skip non-alphanumeric characters and compare the
 * lowercased letters they land on.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& s) {
    int lo = 0, hi = (int)s.size() - 1;
    while (lo < hi) {
        while (lo < hi && !isalnum((unsigned char)s[lo])) ++lo;
        while (lo < hi && !isalnum((unsigned char)s[hi])) --hi;
        if (tolower((unsigned char)s[lo]) != tolower((unsigned char)s[hi])) return false;
        ++lo; --hi;
    }
    return true;
}

int main() {
    cout << isPalindrome("A man, a plan, a canal: Panama") << "\n";   // 1
    cout << isPalindrome("race a car") << "\n";                       // 0
    return 0;
}
