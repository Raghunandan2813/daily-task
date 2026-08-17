/*
 * 285. Word Search II
 * Topic: Trie | Difficulty: Hard
 *
 * Find every word from a dictionary that can be spelled by walking through
 * adjacent cells of a grid without reusing a cell.
 *
 * Approach: running Word Search once per word is far too slow. Instead build a
 * trie of the whole dictionary and DFS the grid once, descending the trie in
 * lockstep with the path. A missing trie child prunes the branch immediately, so
 * one traversal tests all words at once. Found words are cleared from their node
 * to avoid duplicates.
 *
 * Time: O(m * n * 4^L)   Space: O(total dictionary characters)
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* child[26];
    string word;                                     // non-empty at a word end
    Node() { for (int i = 0; i < 26; ++i) child[i] = NULL; }
};

static void insert(Node* root, const string& w) {
    Node* cur = root;
    for (char c : w) {
        int i = c - 'a';
        if (!cur->child[i]) cur->child[i] = new Node();
        cur = cur->child[i];
    }
    cur->word = w;
}

static void dfs(vector<vector<char> >& board, int r, int c, Node* node,
                vector<string>& out) {
    if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return;
    char ch = board[r][c];
    if (ch == '#') return;
    Node* next = node->child[ch - 'a'];
    if (!next) return;                               // no dictionary word fits
    if (!next->word.empty()) { out.push_back(next->word); next->word.clear(); }

    board[r][c] = '#';
    dfs(board, r + 1, c, next, out);
    dfs(board, r - 1, c, next, out);
    dfs(board, r, c + 1, next, out);
    dfs(board, r, c - 1, next, out);
    board[r][c] = ch;
}

vector<string> findWords(vector<vector<char> > board, const vector<string>& words) {
    Node* root = new Node();
    for (const string& w : words) insert(root, w);
    vector<string> out;
    for (int r = 0; r < (int)board.size(); ++r)
        for (int c = 0; c < (int)board[0].size(); ++c)
            dfs(board, r, c, root, out);
    return out;
}

int main() {
    vector<string> raw = {"oaan", "etae", "ihkr", "iflv"};
    vector<vector<char> > board;
    for (const string& row : raw) board.push_back(vector<char>(row.begin(), row.end()));
    vector<string> found = findWords(board, {"oath", "pea", "eat", "rain"});
    sort(found.begin(), found.end());
    for (const string& w : found) cout << w << " ";
    cout << "\n";   // eat oath
    return 0;
}
