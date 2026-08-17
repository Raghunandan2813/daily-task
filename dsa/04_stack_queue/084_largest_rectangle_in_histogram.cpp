/*
 * 084. Largest Rectangle in Histogram
 * Topic: Stack & Queue | Difficulty: Hard
 *
 * Find the area of the largest rectangle that fits inside a histogram.
 *
 * Approach: monotonic increasing stack of indices. When a shorter bar arrives,
 * every taller bar on the stack has found its right boundary, and the new stack
 * top is its left boundary - so its maximal rectangle can be finalised. A
 * sentinel height of 0 at the end flushes the stack.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

long long largestRectangleArea(vector<int> heights) {
    heights.push_back(0);                        // sentinel flushes the stack
    stack<int> st;
    long long best = 0;
    for (int i = 0; i < (int)heights.size(); ++i) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            int h = heights[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            best = max(best, (long long)h * (i - left - 1));
        }
        st.push(i);
    }
    return best;
}

int main() {
    cout << largestRectangleArea({2, 1, 5, 6, 2, 3}) << "\n";   // 10
    cout << largestRectangleArea({2, 4}) << "\n";               // 4
    return 0;
}
