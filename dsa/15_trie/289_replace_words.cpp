/*
 * 289. Replace Words with Roots
 * Topic: Trie | Difficulty: Medium
 *
 * Given a dictionary of roots, replace every word in a sentence by the shortest
 * root that is a prefix of it.
 *
 * Approach: store the roots in a trie and walk each word down it, stopping at
 * the first node marked as a root. Stopping early is what yields the *shortest*
 * matching root without needing to compare candidates.
 *
 * Time: O(total characters)   Space: O(dictionary size)
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* child[26];
    bool isRoot;
    Node() : isRoot(false) { for (int i = 0; i < 26; ++i) child[i] = NULL; }
};

static string shortestRoot(Node* root, const string& word) {
    Node* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) {
        int idx = word[i] - 'a';
        if (!cur->child[idx]) break;
        cur = cur->child[idx];
        if (cur->isRoot) return word.substr(0, i + 1);   // shortest match
    }
    return word;
}

string replaceWords(const vector<string>& dictionary, const string& sentence) {
    Node* root = new Node();
    for (const string& w : dictionary) {
        Node* cur = root;
        for (char c : w) {
            int i = c - 'a';
            if (!cur->child[i]) cur->child[i] = new Node();
            cur = cur->child[i];
        }
        cur->isRoot = true;
    }
    istringstream in(sentence);
    string word, out;
    while (in >> word) {
        if (!out.empty()) out += ' ';
        out += shortestRoot(root, word);
    }
    return out;
}

int main() {
    cout << replaceWords({"cat", "bat", "rat"},
                         "the cattle was rattled by the battery") << "\n";
    // the cat was rat by the bat
    return 0;
}
