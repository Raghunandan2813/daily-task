/*
 * 189. Sort a Nearly Sorted (K-Sorted) Array
 * Topic: Heap | Difficulty: Medium
 *
 * Every element is at most k positions away from its sorted place. Sort the
 * array faster than a general sort.
 *
 * Approach: a min-heap of size k+1. Once k+1 elements are in the heap, its root
 * is guaranteed to be the next element in sorted order, because nothing further
 * right could displace it by more than k.
 *
 * Time: O(n log k)   Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> sortKSorted(const vector<int>& a, int k) {
    priority_queue<int, vector<int>, greater<int> > heap;
    vector<int> out;
    out.reserve(a.size());
    for (int x : a) {
        heap.push(x);
        if ((int)heap.size() > k + 1) { out.push_back(heap.top()); heap.pop(); }
    }
    while (!heap.empty()) { out.push_back(heap.top()); heap.pop(); }
    return out;
}

int main() {
    for (int x : sortKSorted({6, 5, 3, 2, 8, 10, 9}, 3)) cout << x << " ";
    cout << "\n";   // 2 3 5 6 8 9 10
    return 0;
}
