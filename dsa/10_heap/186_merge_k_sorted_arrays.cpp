/*
 * 186. Merge K Sorted Arrays
 * Topic: Heap | Difficulty: Medium
 *
 * Merge k sorted arrays into one sorted array.
 *
 * Approach: a min-heap holding one candidate per array, each tagged with which
 * array and index it came from. Popping the global minimum and pushing that
 * array's next element keeps the heap at size k.
 *
 * Time: O(n log k) for n total elements   Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;

struct Entry {
    int value, arrayIdx, elemIdx;
    bool operator>(const Entry& o) const { return value > o.value; }
};

vector<int> mergeKArrays(const vector<vector<int> >& arrays) {
    priority_queue<Entry, vector<Entry>, greater<Entry> > heap;
    for (int i = 0; i < (int)arrays.size(); ++i) {
        if (arrays[i].empty()) continue;
        Entry e = {arrays[i][0], i, 0};
        heap.push(e);
    }
    vector<int> out;
    while (!heap.empty()) {
        Entry e = heap.top();
        heap.pop();
        out.push_back(e.value);
        int nextIdx = e.elemIdx + 1;
        if (nextIdx < (int)arrays[e.arrayIdx].size()) {
            Entry n = {arrays[e.arrayIdx][nextIdx], e.arrayIdx, nextIdx};
            heap.push(n);
        }
    }
    return out;
}

int main() {
    vector<vector<int> > arrays;
    arrays.push_back(vector<int>{1, 3, 5, 7});
    arrays.push_back(vector<int>{2, 4, 6, 8});
    arrays.push_back(vector<int>{0, 9, 10, 11});
    for (int x : mergeKArrays(arrays)) cout << x << " ";
    cout << "\n";   // 0 1 2 3 4 5 6 7 8 9 10 11
    return 0;
}
