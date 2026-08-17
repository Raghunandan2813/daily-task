/*
 * 194. Smallest Range Covering Elements from K Lists
 * Topic: Heap | Difficulty: Hard
 *
 * Find the smallest range [a, b] that includes at least one number from each of
 * k sorted lists.
 *
 * Approach: keep one pointer per list and a min-heap of the current candidates
 * plus a running maximum of them. The heap top and that maximum bound a valid
 * range; advancing the list that owns the minimum is the only move that can
 * shrink it.
 *
 * Time: O(n log k)   Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, listIdx, elemIdx;
    bool operator>(const Item& o) const { return value > o.value; }
};

vector<int> smallestRange(const vector<vector<int> >& lists) {
    priority_queue<Item, vector<Item>, greater<Item> > heap;
    int curMax = INT_MIN;
    for (int i = 0; i < (int)lists.size(); ++i) {
        Item it = {lists[i][0], i, 0};
        heap.push(it);
        curMax = max(curMax, lists[i][0]);
    }
    int bestLo = heap.top().value, bestHi = curMax;
    while (true) {
        Item lo = heap.top();
        heap.pop();
        if (curMax - lo.value < bestHi - bestLo) { bestLo = lo.value; bestHi = curMax; }
        int nextIdx = lo.elemIdx + 1;
        if (nextIdx == (int)lists[lo.listIdx].size()) break;   // a list ran out
        Item nx = {lists[lo.listIdx][nextIdx], lo.listIdx, nextIdx};
        curMax = max(curMax, nx.value);
        heap.push(nx);
    }
    return {bestLo, bestHi};
}

int main() {
    vector<vector<int> > lists;
    lists.push_back(vector<int>{4, 10, 15, 24, 26});
    lists.push_back(vector<int>{0, 9, 12, 20});
    lists.push_back(vector<int>{5, 18, 22, 30});
    vector<int> r = smallestRange(lists);
    cout << r[0] << " " << r[1] << "\n";   // 20 24
    return 0;
}
