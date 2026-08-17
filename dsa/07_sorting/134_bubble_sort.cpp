/*
 * 134. Bubble Sort
 * Topic: Sorting | Difficulty: Easy
 *
 * Sort by repeatedly swapping adjacent elements that are out of order.
 *
 * Approach: after pass i the largest i+1 elements have bubbled to the end, so
 * each pass can stop earlier. A swap flag lets an already-sorted array exit in a
 * single O(n) pass. Bubble sort is stable.
 *
 * Time: O(n^2), O(n) best case   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j)
            if (a[j] > a[j + 1]) { swap(a[j], a[j + 1]); swapped = true; }
        if (!swapped) break;                         // already sorted
    }
}

int main() {
    vector<int> v = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(v);
    for (int x : v) cout << x << " ";
    cout << "\n";   // 11 12 22 25 34 64 90
    return 0;
}
