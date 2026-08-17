/*
 * 141. Radix Sort
 * Topic: Sorting | Difficulty: Medium
 *
 * Sort non-negative integers digit by digit, least significant digit first.
 *
 * Approach: run a stable counting sort on each decimal digit position. Stability
 * is essential - it is what preserves the ordering established by the previous,
 * less significant digits.
 *
 * Time: O(d * (n + 10)) for d digits   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

static void countingSortByDigit(vector<int>& a, int exp) {
    int n = a.size();
    vector<int> out(n), count(10, 0);
    for (int x : a) ++count[(x / exp) % 10];
    for (int i = 1; i < 10; ++i) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; --i)                  // backwards keeps it stable
        out[--count[(a[i] / exp) % 10]] = a[i];
    a = out;
}

void radixSort(vector<int>& a) {
    if (a.empty()) return;
    int mx = *max_element(a.begin(), a.end());
    for (int exp = 1; mx / exp > 0; exp *= 10) countingSortByDigit(a, exp);
}

int main() {
    vector<int> v = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(v);
    for (int x : v) cout << x << " ";
    cout << "\n";   // 2 24 45 66 75 90 170 802
    return 0;
}
