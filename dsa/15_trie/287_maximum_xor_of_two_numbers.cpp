/*
 * 287. Maximum XOR of Two Numbers in an Array
 * Topic: Trie | Difficulty: Hard
 *
 * Find the largest XOR obtainable from any pair of elements.
 *
 * Approach: a binary trie over the 32-bit representations. For each number,
 * greedily walk the trie preferring the opposite bit at every level - a
 * difference at a higher bit outweighs everything below it, so the greedy choice
 * is optimal. This replaces the O(n^2) pairwise scan with O(32n).
 *
 * Time: O(32n)   Space: O(32n)
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* child[2];
    Node() { child[0] = child[1] = NULL; }
};

int findMaximumXOR(const vector<int>& nums) {
    Node* root = new Node();
    for (int x : nums) {                             // build the trie
        Node* cur = root;
        for (int b = 31; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (!cur->child[bit]) cur->child[bit] = new Node();
            cur = cur->child[bit];
        }
    }
    int best = 0;
    for (int x : nums) {                             // query for each number
        Node* cur = root;
        int value = 0;
        for (int b = 31; b >= 0; --b) {
            int bit = (x >> b) & 1;
            int want = 1 - bit;                      // prefer a differing bit
            if (cur->child[want]) { value |= (1 << b); cur = cur->child[want]; }
            else cur = cur->child[bit];
        }
        best = max(best, value);
    }
    return best;
}

int main() {
    cout << findMaximumXOR({3, 10, 5, 25, 2, 8}) << "\n";   // 28
    cout << findMaximumXOR({0}) << "\n";                    // 0
    return 0;
}
