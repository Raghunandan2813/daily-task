/*
 * 139. Heap Sort
 * Topic: Sorting | Difficulty: Medium
 *
 * Sort by building a max-heap in the array itself, then repeatedly moving the
 * root to the end.
 *
 * Approach: heapify bottom-up in O(n), then for each step swap the maximum into
 * the shrinking tail and sift the new root down. Heap sort matches merge sort's
 * O(n log n) worst case but needs no extra array; it is not stable.
 *
 * Time: O(n log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static void siftDown(vector<int>& a, int size, int root) {
    while (true) {
        int largest = root, l = 2 * root + 1, r = 2 * root + 2;
        if (l < size && a[l] > a[largest]) largest = l;
        if (r < size && a[r] > a[largest]) largest = r;
        if (largest == root) return;
        swap(a[root], a[largest]);
        root = largest;
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; --i) siftDown(a, n, i);   // build max-heap
    for (int end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);                                    // max to the tail
        siftDown(a, end, 0);
    }
}

int main() {
    vector<int> v = {12, 11, 13, 5, 6, 7};
    heapSort(v);
    for (int x : v) cout << x << " ";
    cout << "\n";   // 5 6 7 11 12 13
    return 0;
}
