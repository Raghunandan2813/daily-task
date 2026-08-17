/*
 * 092. Decode String
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * Expand an encoded string of the form k[encoded], where the bracketed part is
 * repeated k times. Encodings may nest.
 *
 * Approach: two stacks, one for pending repeat counts and one for the partial
 * string built at each outer level. On '[' push the current state and reset; on
 * ']' pop and append the repeated segment.
 *
 * Time: O(length of output)   Space: O(nesting depth)
 */
#include <bits/stdc++.h>
using namespace std;

string decodeString(const string& s) {
    stack<int> counts;
    stack<string> parts;
    string cur;
    int num = 0;
    for (char c : s) {
        if (isdigit((unsigned char)c)) num = num * 10 + (c - '0');
        else if (c == '[') { counts.push(num); parts.push(cur); num = 0; cur.clear(); }
        else if (c == ']') {
            string repeated;
            for (int i = 0; i < counts.top(); ++i) repeated += cur;
            counts.pop();
            cur = parts.top() + repeated;
            parts.pop();
        } else cur += c;
    }
    return cur;
}

int main() {
    cout << decodeString("3[a]2[bc]") << "\n";     // aaabcbc
    cout << decodeString("3[a2[c]]") << "\n";      // accaccacc
    cout << decodeString("2[abc]3[cd]ef") << "\n"; // abcabccdcdcdef
    return 0;
}
