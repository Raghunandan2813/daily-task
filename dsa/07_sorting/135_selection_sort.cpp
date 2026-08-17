/*
 * 135. Selection Sort
 * Topic: Sorting | Difficulty: Easy
 *
 * Repeatedly select the smallest remaining element and place it at the front of
 * the unsorted region.
 *
 * Approach: for each position i, scan the suffix for the minimum and swap it
 * into place. Selection sort always performs exactly n-1 swaps, which makes it
 * useful when writes are expensive. It is not stable.
 *
 * Time: O(n^2) in all cases   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[minIdx]) minIdx = j;
        if (minIdx != i) swap(a[i], a[minIdx]);
    }
}

int main() {
    vector<int> v = {64, 25, 12, 22, 11};
    selectionSort(v);
    for (int x : v) cout << x << " ";
    cout << "\n";   // 11 12 22 25 64
    return 0;
}
