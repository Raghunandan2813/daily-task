/*
 * 036. Reverse String
 * Topic: Strings | Difficulty: Easy
 *
 * Reverse a character array in place.
 *
 * Approach: two pointers converging from both ends, swapping as they go. Only
 * n/2 swaps are needed.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void reverseString(string& s) {
    int lo = 0, hi = (int)s.size() - 1;
    while (lo < hi) swap(s[lo++], s[hi--]);
}

int main() {
    string s = "hello";
    reverseString(s);
    cout << s << "\n";   // olleh
    return 0;
}
