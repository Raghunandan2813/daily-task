/*
 * 014. Next Permutation
 * Topic: Arrays | Difficulty: Medium
 *
 * Rearrange the numbers into the lexicographically next greater permutation. If
 * no such permutation exists, rearrange into the lowest order (sorted ascending).
 *
 * Approach: scan from the right for the first index i with a[i] < a[i+1] (the
 * pivot). Swap it with the rightmost element greater than it, then reverse the
 * suffix so it becomes the smallest possible tail.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& a) {
    int n = a.size(), i = n - 2;
    while (i >= 0 && a[i] >= a[i + 1]) --i;
    if (i >= 0) {
        int j = n - 1;
        while (a[j] <= a[i]) --j;
        swap(a[i], a[j]);
    }
    reverse(a.begin() + i + 1, a.end());
}

int main() {
    vector<int> v = {1, 2, 3};
    nextPermutation(v);
    for (int x : v) cout << x << " ";   // 1 3 2
    cout << "\n";
    vector<int> w = {3, 2, 1};
    nextPermutation(w);
    for (int x : w) cout << x << " ";   // 1 2 3
    cout << "\n";
    return 0;
}
