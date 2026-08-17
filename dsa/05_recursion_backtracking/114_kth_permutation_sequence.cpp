/*
 * 114. Permutation Sequence
 * Topic: Recursion & Backtracking | Difficulty: Hard
 *
 * Return the k-th permutation (1-indexed) of the numbers 1..n in lexicographic
 * order, without enumerating the earlier ones.
 *
 * Approach: the permutations starting with a fixed first digit form a block of
 * (n-1)! entries. Dividing k by that block size picks the digit directly; remove
 * it from the candidate list and repeat on the shrunken problem.
 *
 * Time: O(n^2) - the erase from a vector dominates   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
    vector<int> factorial(n + 1, 1);
    for (int i = 1; i <= n; ++i) factorial[i] = factorial[i - 1] * i;

    vector<char> digits;
    for (int i = 1; i <= n; ++i) digits.push_back(char('0' + i));

    --k;                                            // switch to 0-indexed
    string out;
    for (int i = n; i >= 1; --i) {
        int block = factorial[i - 1];
        int idx = k / block;
        k %= block;
        out += digits[idx];
        digits.erase(digits.begin() + idx);
    }
    return out;
}

int main() {
    cout << getPermutation(3, 3) << "\n";   // 213
    cout << getPermutation(4, 9) << "\n";   // 2314
    return 0;
}
