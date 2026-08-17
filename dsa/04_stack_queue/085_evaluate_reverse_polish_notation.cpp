/*
 * 085. Evaluate Reverse Polish Notation
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * Evaluate an arithmetic expression given in postfix form.
 *
 * Approach: push operands; on an operator pop two values, apply it (minding the
 * order - the second pop is the left operand) and push the result back. The
 * single remaining value is the answer.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int evalRPN(const vector<string>& tokens) {
    stack<long long> st;
    for (const string& t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            if (t == "+") st.push(a + b);
            else if (t == "-") st.push(a - b);
            else if (t == "*") st.push(a * b);
            else st.push(a / b);
        } else st.push(stoll(t));
    }
    return (int)st.top();
}

int main() {
    cout << evalRPN({"2", "1", "+", "3", "*"}) << "\n";   // 9
    cout << evalRPN({"4", "13", "5", "/", "+"}) << "\n";  // 6
    return 0;
}
