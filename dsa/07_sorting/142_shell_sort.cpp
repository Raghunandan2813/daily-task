/*
 * 142. Shell Sort
 * Topic: Sorting | Difficulty: Medium
 *
 * A generalisation of insertion sort that first sorts elements far apart, then
 * narrows the gap to 1.
 *
 * Approach: for each gap, run an insertion sort over the interleaved
 * subsequences. Large gaps move out-of-place elements a long way cheaply, so by
 * the time the gap reaches 1 the array is nearly sorted and the final pass is
 * fast.
 *
 * Time: O(n^2) worst case, about O(n^1.3) in practice   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int>& a) {
    int n = a.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int key = a[i], j = i;
            while (j >= gap && a[j - gap] > key) { a[j] = a[j - gap]; j -= gap; }
            a[j] = key;
        }
    }
}

int main() {
    vector<int> v = {12, 34, 54, 2, 3};
    shellSort(v);
    for (int x : v) cout << x << " ";
    cout << "\n";   // 2 3 12 34 54
    return 0;
}
