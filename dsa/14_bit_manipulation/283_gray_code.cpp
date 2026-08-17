/*
 * 283. Gray Code
 * Topic: Bit Manipulation | Difficulty: Medium
 *
 * Generate the n-bit Gray code sequence, in which consecutive entries differ by
 * exactly one bit and the sequence wraps around.
 *
 * Approach: the i-th standard reflected Gray code is simply i ^ (i >> 1).
 * Adjacent integers differ in a suffix of the form 0111..1 -> 1000..0, and
 * XORing with the shifted value collapses that whole suffix change into a single
 * bit difference.
 *
 * Time: O(2^n)   Space: O(1) beyond the output
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n) {
    vector<int> out;
    out.reserve(1 << n);
    for (int i = 0; i < (1 << n); ++i) out.push_back(i ^ (i >> 1));
    return out;
}

int main() {
    for (int g : grayCode(3)) cout << g << " ";
    cout << "\n";   // 0 1 3 2 6 7 5 4

    vector<int> g = grayCode(4);            // verify the one-bit property
    bool ok = true;
    for (size_t i = 0; i < g.size(); ++i) {
        int diff = g[i] ^ g[(i + 1) % g.size()];
        if ((diff & (diff - 1)) != 0) ok = false;
    }
    cout << ok << "\n";   // 1
    return 0;
}
