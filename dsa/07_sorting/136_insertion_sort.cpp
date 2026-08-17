/*
 * 136. Insertion Sort
 * Topic: Sorting | Difficulty: Easy
 *
 * Build the sorted region one element at a time by inserting each new element
 * into its correct place among those already sorted.
 *
 * Approach: hold the current element aside and shift larger elements one slot
 * right until the gap is in the right position. Insertion sort is stable and
 * runs in O(n) on nearly sorted input, which is why hybrid sorts fall back to it
 * for small ranges.
 *
 * Time: O(n^2), O(n) best case   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& a) {
    for (int i = 1; i < (int)a.size(); ++i) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; --j; }
        a[j + 1] = key;
    }
}

int main() {
    vector<int> v = {12, 11, 13, 5, 6};
    insertionSort(v);
    for (int x : v) cout << x << " ";
    cout << "\n";   // 5 6 11 12 13
    return 0;
}
