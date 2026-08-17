/*
 * 144. Cycle Sort
 * Topic: Sorting | Difficulty: Medium
 *
 * Sort while performing the theoretical minimum number of writes to the array.
 *
 * Approach: for each starting position, count how many elements are smaller to
 * learn where the current value belongs, then rotate that permutation cycle into
 * place. Every element is written exactly once, which is what makes cycle sort
 * attractive when writes are far costlier than reads (e.g. flash memory).
 *
 * Time: O(n^2)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void cycleSort(vector<int>& a) {
    int n = a.size();
    for (int start = 0; start < n - 1; ++start) {
        int item = a[start];

        int pos = start;                              // find where `item` belongs
        for (int i = start + 1; i < n; ++i) if (a[i] < item) ++pos;
        if (pos == start) continue;                   // already in place
        while (item == a[pos]) ++pos;                 // skip duplicates
        swap(item, a[pos]);

        while (pos != start) {                        // rotate the rest of the cycle
            pos = start;
            for (int i = start + 1; i < n; ++i) if (a[i] < item) ++pos;
            while (item == a[pos]) ++pos;
            swap(item, a[pos]);
        }
    }
}

int main() {
    vector<int> v = {20, 40, 50, 10, 30};
    cycleSort(v);
    for (int x : v) cout << x << " ";
    cout << "\n";   // 10 20 30 40 50
    return 0;
}
