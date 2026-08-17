/*
 * 183. Implement a Min Heap
 * Topic: Heap | Difficulty: Medium
 *
 * Build a binary min-heap from scratch supporting push, pop and top.
 *
 * Approach: an implicit binary tree stored in an array - the children of index i
 * live at 2i+1 and 2i+2. push appends and sifts up; pop moves the last element
 * to the root and sifts down. Both restore the heap property in O(log n).
 *
 * Time: O(log n) push/pop, O(1) top   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;

    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] <= heap[i]) break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }
    void siftDown(int i) {
        int n = heap.size();
        while (true) {
            int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
            if (l < n && heap[l] < heap[smallest]) smallest = l;
            if (r < n && heap[r] < heap[smallest]) smallest = r;
            if (smallest == i) return;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }
public:
    bool empty() const { return heap.empty(); }
    int top() const { return heap.front(); }
    void push(int x) { heap.push_back(x); siftUp(heap.size() - 1); }
    void pop() {
        heap.front() = heap.back();
        heap.pop_back();
        if (!heap.empty()) siftDown(0);
    }
};

int main() {
    MinHeap h;
    int vals[] = {5, 3, 8, 1, 9, 2};
    for (int v : vals) h.push(v);
    while (!h.empty()) { cout << h.top() << " "; h.pop(); }
    cout << "\n";   // 1 2 3 5 8 9
    return 0;
}
