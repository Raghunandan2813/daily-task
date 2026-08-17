/*
 * 140. Counting Sort
 * Topic: Sorting | Difficulty: Medium
 *
 * Sort integers drawn from a small known range without comparing them.
 *
 * Approach: tally each value, turn the tallies into prefix sums (giving each
 * value's final position), then place elements by walking the input backwards -
 * which is what makes counting sort stable. It beats the O(n log n) comparison
 * bound because it never compares two elements.
 *
 * Time: O(n + k) for a value range of k   Space: O(n + k)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(const vector<int>& a) {
    if (a.empty()) return {};
    int lo = *min_element(a.begin(), a.end());
    int hi = *max_element(a.begin(), a.end());
    vector<int> count(hi - lo + 1, 0);
    for (int x : a) ++count[x - lo];
    for (int i = 1; i < (int)count.size(); ++i) count[i] += count[i - 1];

    vector<int> out(a.size());
    for (int i = (int)a.size() - 1; i >= 0; --i)      // backwards keeps it stable
        out[--count[a[i] - lo]] = a[i];
    return out;
}

int main() {
    for (int x : countingSort({4, 2, 2, 8, 3, 3, 1})) cout << x << " ";
    cout << "\n";   // 1 2 2 3 3 4 8
    for (int x : countingSort({-5, -10, 0, -3, 8, 5, -1, 10})) cout << x << " ";
    cout << "\n";   // -10 -5 -3 -1 0 5 8 10
    return 0;
}
