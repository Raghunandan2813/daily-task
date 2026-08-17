/*
 * 089. Sliding Window Maximum
 * Topic: Stack & Queue | Difficulty: Hard
 *
 * Report the maximum of every window of size k as it slides across the array.
 *
 * Approach: monotonic deque of indices whose values decrease from front to back.
 * The front is always the window maximum. Indices that fall out of the window
 * are dropped from the front, and any index whose value is <= the incoming one
 * is dropped from the back because it can never be a future maximum.
 *
 * Time: O(n)   Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    deque<int> dq;                                // indices, values decreasing
    vector<int> out;
    for (int i = 0; i < (int)nums.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) out.push_back(nums[dq.front()]);
    }
    return out;
}

int main() {
    for (int x : maxSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3)) cout << x << " ";
    cout << "\n";   // 3 3 5 5 6 7
    return 0;
}
