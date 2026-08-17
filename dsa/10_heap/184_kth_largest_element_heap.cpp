/*
 * 184. Kth Largest Element in an Array (Heap)
 * Topic: Heap | Difficulty: Medium
 *
 * Find the k-th largest element using a heap rather than sorting.
 *
 * Approach: keep a min-heap of size k holding the k largest values seen. Its
 * root is the smallest of those, so it is exactly the k-th largest overall, and
 * any new element only needs to be compared against that root.
 *
 * Time: O(n log k)   Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;

int findKthLargest(const vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for (int x : nums) {
        minHeap.push(x);
        if ((int)minHeap.size() > k) minHeap.pop();     // drop the smallest
    }
    return minHeap.top();
}

int main() {
    cout << findKthLargest({3, 2, 1, 5, 6, 4}, 2) << "\n";            // 5
    cout << findKthLargest({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4) << "\n";   // 4
    return 0;
}
