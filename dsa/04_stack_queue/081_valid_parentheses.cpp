/*
 * 081. Valid Parentheses
 * Topic: Stack & Queue | Difficulty: Easy
 *
 * Decide whether a string of brackets is correctly balanced and nested.
 *
 * Approach: push every opening bracket. On a closing bracket the stack top must
 * be its matching partner, otherwise the string is invalid. A leftover stack at
 * the end means some brackets were never closed.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

bool isValid(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') ||
                (c == '}' && top != '{')) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    cout << isValid("()[]{}") << "\n";   // 1
    cout << isValid("([)]") << "\n";     // 0
    cout << isValid("{[]}") << "\n";     // 1
    return 0;
}
