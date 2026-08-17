/*
 * 284. Implement Trie (Prefix Tree)
 * Topic: Trie | Difficulty: Medium
 *
 * Support insert, exact search and prefix search over a set of lowercase words.
 *
 * Approach: each node owns 26 child pointers, one per letter, and a flag marking
 * the end of a word. Words sharing a prefix share the same path, so every
 * operation costs O(length of the key) regardless of how many words are stored -
 * the property a hash set cannot offer for prefix queries.
 *
 * Time: O(L) per operation   Space: O(total characters * 26)
 */
#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        Node* child[26];
        bool isWord;
        Node() : isWord(false) { for (int i = 0; i < 26; ++i) child[i] = NULL; }
    };
    Node* root;

    Node* walk(const string& s) const {
        Node* cur = root;
        for (char c : s) {
            int i = c - 'a';
            if (!cur->child[i]) return NULL;
            cur = cur->child[i];
        }
        return cur;
    }
public:
    Trie() : root(new Node()) {}

    void insert(const string& word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->child[i]) cur->child[i] = new Node();
            cur = cur->child[i];
        }
        cur->isWord = true;
    }
    bool search(const string& word) const {
        Node* n = walk(word);
        return n && n->isWord;
    }
    bool startsWith(const string& prefix) const { return walk(prefix) != NULL; }
};

int main() {
    Trie t;
    t.insert("apple");
    cout << t.search("apple") << "\n";       // 1
    cout << t.search("app") << "\n";         // 0
    cout << t.startsWith("app") << "\n";     // 1
    t.insert("app");
    cout << t.search("app") << "\n";         // 1
    return 0;
}
