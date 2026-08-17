/*
 * 082. Min Stack
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * Design a stack supporting push, pop, top and getMin, all in O(1).
 *
 * Approach: keep a parallel stack of running minima. Each push also records
 * min(new value, current minimum), so the minimum for any stack state is always
 * available at the top of the auxiliary stack.
 *
 * Time: O(1) per operation   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class MinStack {
    vector<int> data;
    vector<int> mins;
public:
    void push(int x) {
        data.push_back(x);
        mins.push_back(mins.empty() ? x : min(x, mins.back()));
    }
    void pop() { data.pop_back(); mins.pop_back(); }
    int top() const { return data.back(); }
    int getMin() const { return mins.back(); }
};

int main() {
    MinStack st;
    st.push(-2); st.push(0); st.push(-3);
    cout << st.getMin() << "\n";   // -3
    st.pop();
    cout << st.top() << "\n";      // 0
    cout << st.getMin() << "\n";   // -2
    return 0;
}
