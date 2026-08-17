/*
 * 286. Longest Word in Dictionary
 * Topic: Trie | Difficulty: Medium
 *
 * Find the longest word that can be built one character at a time, where every
 * intermediate prefix is also a word. Ties break lexicographically smallest.
 *
 * Approach: insert everything into a trie, then DFS only through nodes that are
 * themselves complete words - that restriction is exactly the buildability
 * requirement. Visiting children in alphabetical order and only replacing the
 * answer on a strictly longer word gives the correct tie-break for free.
 *
 * Time: O(total characters)   Space: O(total characters)
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* child[26];
    bool isWord;
    Node() : isWord(false) { for (int i = 0; i < 26; ++i) child[i] = NULL; }
};

static void dfs(Node* node, string& path, string& best) {
    if (path.size() > best.size()) best = path;      // ties keep the earlier one
    for (int i = 0; i < 26; ++i) {                   // alphabetical order
        Node* c = node->child[i];
        if (!c || !c->isWord) continue;              // must be buildable
        path.push_back(char('a' + i));
        dfs(c, path, best);
        path.pop_back();
    }
}

string longestWord(const vector<string>& words) {
    Node* root = new Node();
    for (const string& w : words) {
        Node* cur = root;
        for (char c : w) {
            int i = c - 'a';
            if (!cur->child[i]) cur->child[i] = new Node();
            cur = cur->child[i];
        }
        cur->isWord = true;
    }
    string path, best;
    dfs(root, path, best);
    return best;
}

int main() {
    cout << longestWord({"w", "wo", "wor", "worl", "world"}) << "\n";   // world
    cout << longestWord({"a", "banana", "app", "appl", "ap", "apply", "apple"}) << "\n";
    // apple
    return 0;
}
