/*
 * 291. Add and Search Word (Wildcard Matching)
 * Topic: Trie | Difficulty: Medium
 *
 * Support adding words and searching, where '.' in a query matches any single
 * character.
 *
 * Approach: a trie plus a DFS search. A concrete letter descends one branch as
 * usual; a '.' must branch into all 26 children, so the search becomes a
 * backtracking traversal rather than a simple walk. Only queries containing dots
 * pay that cost.
 *
 * Time: O(L) without dots, up to O(26^d * L) with d dots   Space: O(total chars)
 */
#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
    struct Node {
        Node* child[26];
        bool isWord;
        Node() : isWord(false) { for (int i = 0; i < 26; ++i) child[i] = NULL; }
    };
    Node* root;

    bool match(const string& w, int pos, Node* node) const {
        if (!node) return false;
        if (pos == (int)w.size()) return node->isWord;
        if (w[pos] != '.') return match(w, pos + 1, node->child[w[pos] - 'a']);
        for (int i = 0; i < 26; ++i)                 // '.' tries every branch
            if (match(w, pos + 1, node->child[i])) return true;
        return false;
    }
public:
    WordDictionary() : root(new Node()) {}

    void addWord(const string& word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->child[i]) cur->child[i] = new Node();
            cur = cur->child[i];
        }
        cur->isWord = true;
    }
    bool search(const string& word) const { return match(word, 0, root); }
};

int main() {
    WordDictionary d;
    d.addWord("bad");
    d.addWord("dad");
    d.addWord("mad");
    cout << d.search("pad") << "\n";   // 0
    cout << d.search("bad") << "\n";   // 1
    cout << d.search(".ad") << "\n";   // 1
    cout << d.search("b..") << "\n";   // 1
    return 0;
}
