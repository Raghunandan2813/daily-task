/*
 * 290. Count Distinct Substrings Using a Trie
 * Topic: Trie | Difficulty: Hard
 *
 * Count the number of distinct substrings of a string (excluding the empty one).
 *
 * Approach: every substring is a prefix of some suffix, so inserting all n
 * suffixes into a trie makes each distinct substring correspond to exactly one
 * trie node. Counting the nodes created (excluding the root) therefore counts
 * the distinct substrings, with duplicates merged automatically by the shared
 * paths.
 *
 * Time: O(n^2)   Space: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* child[26];
    Node() { for (int i = 0; i < 26; ++i) child[i] = NULL; }
};

long long countDistinctSubstrings(const string& s) {
    Node* root = new Node();
    long long nodes = 0;
    for (int start = 0; start < (int)s.size(); ++start) {
        Node* cur = root;
        for (int i = start; i < (int)s.size(); ++i) {
            int idx = s[i] - 'a';
            if (!cur->child[idx]) { cur->child[idx] = new Node(); ++nodes; }
            cur = cur->child[idx];
        }
    }
    return nodes;
}

int main() {
    cout << countDistinctSubstrings("ababa") << "\n";   // 9
    cout << countDistinctSubstrings("abc") << "\n";     // 6
    cout << countDistinctSubstrings("aaa") << "\n";     // 3
    return 0;
}
