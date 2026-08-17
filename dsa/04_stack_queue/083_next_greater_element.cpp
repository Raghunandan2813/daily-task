/*
 * 083. Next Greater Element
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * For each element, find the first larger element to its right, or -1 if there
 * is none.
 *
 * Approach: monotonic decreasing stack scanned right to left. Anything on the
 * stack that is not larger than the current element can never be an answer for
 * anything further left, so it is popped.
 *
 * Time: O(n) amortised   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(const vector<int>& nums) {
    int n = nums.size();
    vector<int> out(n, -1);
    stack<int> st;                                // holds candidate values
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= nums[i]) st.pop();
        if (!st.empty()) out[i] = st.top();
        st.push(nums[i]);
    }
    return out;
}

int main() {
    for (int x : nextGreater({4, 5, 2, 25})) cout << x << " ";
    cout << "\n";   // 5 25 25 -1
    for (int x : nextGreater({13, 7, 6, 12})) cout << x << " ";
    cout << "\n";   // -1 12 12 -1
    return 0;
}
