/*
 * 300. Catalan Numbers
 * Topic: Math | Difficulty: Medium
 *
 * Compute the n-th Catalan number - the count of valid parenthesisations, of
 * distinct BSTs on n keys, of full binary trees, of monotonic lattice paths that
 * stay below the diagonal, and of several other structures that all share the
 * same recurrence.
 *
 * Approach: C(0) = 1 and C(n) = sum over i of C(i) * C(n-1-i). The split index i
 * is the size of the left part - for BSTs it is the left subtree, for
 * parentheses the contents of the first bracket pair - which is why one
 * recurrence covers all of them.
 *
 * Time: O(n^2)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

vector<long long> catalanUpTo(int n) {
    vector<long long> c(n + 1, 0);
    c[0] = 1;
    for (int k = 1; k <= n; ++k)
        for (int i = 0; i < k; ++i)
            c[k] += c[i] * c[k - 1 - i];
    return c;
}

int main() {
    vector<long long> c = catalanUpTo(10);
    for (long long x : c) cout << x << " ";
    cout << "\n";   // 1 1 2 5 14 42 132 429 1430 4862 16796

    // C(3) = 5: the five distinct BSTs on the keys {1, 2, 3}
    cout << "distinct BSTs with 3 nodes: " << c[3] << "\n";   // 5
    return 0;
}
