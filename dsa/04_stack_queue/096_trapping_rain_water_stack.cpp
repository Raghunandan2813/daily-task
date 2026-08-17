/*
 * 096. Trapping Rain Water (Monotonic Stack)
 * Topic: Stack & Queue | Difficulty: Hard
 *
 * Compute trapped rain water, this time with a stack rather than two pointers.
 *
 * Approach: keep a decreasing stack of indices. When a taller bar arrives, the
 * bar it pops is the floor of a basin whose walls are the new bar and the next
 * stack entry. Add that basin's water layer by layer.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int trap(const vector<int>& height) {
    stack<int> st;
    int total = 0;
    for (int i = 0; i < (int)height.size(); ++i) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int floorIdx = st.top();
            st.pop();
            if (st.empty()) break;                 // no left wall
            int leftIdx = st.top();
            int width = i - leftIdx - 1;
            int depth = min(height[leftIdx], height[i]) - height[floorIdx];
            total += width * depth;
        }
        st.push(i);
    }
    return total;
}

int main() {
    cout << trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << "\n";   // 6
    cout << trap({4, 2, 0, 3, 2, 5}) << "\n";                     // 9
    return 0;
}
