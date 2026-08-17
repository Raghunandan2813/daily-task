/*
 * 193. Sliding Window Median
 * Topic: Heap | Difficulty: Hard
 *
 * Report the median of every window of size k as it slides across the array.
 *
 * Approach: a multiset with an iterator parked at the lower median. Insert and
 * erase are O(log k), and the iterator only ever needs to step one position to
 * stay centred: it moves left when the incoming value lands below it, and right
 * when the outgoing value did. A multiset is used rather than two heaps because
 * it can remove an arbitrary element, not just an extreme one.
 *
 * Time: O(n log k)   Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;

vector<double> medianSlidingWindow(const vector<int>& nums, int k) {
    multiset<int> window(nums.begin(), nums.begin() + k);
    multiset<int>::iterator mid = next(window.begin(), (k - 1) / 2);
    vector<double> out;
    int n = nums.size();
    for (int i = k; ; ++i) {
        // For odd k both terms are *mid; for even k they are the two middles.
        out.push_back(((double)*mid + *next(mid, 1 - k % 2)) / 2.0);
        if (i == n) break;

        window.insert(nums[i]);
        if (nums[i] < *mid) --mid;                       // incoming went left
        if (nums[i - k] <= *mid) ++mid;                  // outgoing was at or left
        window.erase(window.lower_bound(nums[i - k]));
    }
    return out;
}

int main() {
    for (double d : medianSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3))
        cout << d << " ";
    cout << "\n";   // 1 -1 -1 3 5 6
    for (double d : medianSlidingWindow({1, 2, 3, 4}, 2)) cout << d << " ";
    cout << "\n";   // 1.5 2.5 3.5
    return 0;
}
