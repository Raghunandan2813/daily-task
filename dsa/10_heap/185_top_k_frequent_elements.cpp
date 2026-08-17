/*
 * 185. Top K Frequent Elements
 * Topic: Heap | Difficulty: Medium
 *
 * Return the k most frequent values in an array.
 *
 * Approach: tally frequencies in a hash map, then keep a min-heap of size k
 * ordered by frequency. Bounding the heap at k means we never sort all the
 * distinct values, which is the win when k is small.
 *
 * Time: O(n log k)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int x : nums) ++freq[x];

    // min-heap keyed on frequency: (count, value)
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > > heap;
    for (auto& kv : freq) {
        heap.push(make_pair(kv.second, kv.first));
        if ((int)heap.size() > k) heap.pop();
    }
    vector<int> out;
    while (!heap.empty()) { out.push_back(heap.top().second); heap.pop(); }
    reverse(out.begin(), out.end());                    // most frequent first
    return out;
}

int main() {
    for (int x : topKFrequent({1, 1, 1, 2, 2, 3}, 2)) cout << x << " ";
    cout << "\n";   // 1 2
    for (int x : topKFrequent({1}, 1)) cout << x << " ";
    cout << "\n";   // 1
    return 0;
}
