/*
 * 267. Huffman Encoding
 * Topic: Greedy | Difficulty: Hard
 *
 * Build an optimal prefix-free binary code from character frequencies.
 *
 * Approach: repeatedly merge the two least frequent nodes under a new parent,
 * using a min-heap. The rarest symbols end up deepest and therefore get the
 * longest codes, which is exactly what minimises the total encoded length.
 * Because codes only ever sit at leaves, no code is a prefix of another.
 *
 * Time: O(n log n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int freq;
    char ch;
    Node* left;
    Node* right;
    Node(int f, char c) : freq(f), ch(c), left(NULL), right(NULL) {}
    Node(int f, Node* l, Node* r) : freq(f), ch(0), left(l), right(r) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) const { return a->freq > b->freq; }
};

static void collect(Node* n, string code, map<char, string>& out) {
    if (!n) return;
    if (!n->left && !n->right) { out[n->ch] = code.empty() ? "0" : code; return; }
    collect(n->left, code + "0", out);
    collect(n->right, code + "1", out);
}

map<char, string> huffman(const map<char, int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (map<char, int>::const_iterator it = freq.begin(); it != freq.end(); ++it)
        pq.push(new Node(it->second, it->first));
    while (pq.size() > 1) {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();
        pq.push(new Node(a->freq + b->freq, a, b));
    }
    map<char, string> codes;
    if (!pq.empty()) collect(pq.top(), "", codes);
    return codes;
}

int main() {
    map<char, int> freq;
    freq['a'] = 5; freq['b'] = 9; freq['c'] = 12;
    freq['d'] = 13; freq['e'] = 16; freq['f'] = 45;
    map<char, string> codes = huffman(freq);
    int totalBits = 0;
    for (map<char, string>::iterator it = codes.begin(); it != codes.end(); ++it) {
        cout << it->first << ": " << it->second << "\n";
        totalBits += freq[it->first] * it->second.size();
    }
    cout << "total bits: " << totalBits << "\n";   // 224
    return 0;
}
