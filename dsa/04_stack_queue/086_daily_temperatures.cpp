/*
 * 086. Daily Temperatures
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * For each day, report how many days you must wait for a warmer temperature.
 * Report 0 if no warmer day follows.
 *
 * Approach: monotonic decreasing stack of indices. When today is warmer than the
 * day on top of the stack, that day has found its answer and the distance is the
 * index difference.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(const vector<int>& temps) {
    int n = temps.size();
    vector<int> out(n, 0);
    stack<int> st;                                // indices, decreasing temps
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && temps[i] > temps[st.top()]) {
            out[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return out;
}

int main() {
    for (int x : dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73}))
        cout << x << " ";
    cout << "\n";   // 1 1 4 2 1 1 0 0
    return 0;
}
