/*
 * 218. Alien Dictionary
 * Topic: Graphs | Difficulty: Hard
 *
 * Given words sorted by an unknown alphabet, recover a valid letter ordering.
 *
 * Approach: each adjacent pair of words reveals one ordering constraint - the
 * first position where they differ. Those constraints form a directed graph, and
 * a topological sort of it is the alphabet. An invalid input (a longer word
 * preceding its own prefix) is rejected up front.
 *
 * Time: O(total characters + 26^2)   Space: O(26^2)
 */
#include <bits/stdc++.h>
using namespace std;

string alienOrder(const vector<string>& words) {
    vector<vector<bool> > edge(26, vector<bool>(26, false));
    vector<bool> present(26, false);
    for (const string& w : words)
        for (char c : w) present[c - 'a'] = true;

    for (int i = 0; i + 1 < (int)words.size(); ++i) {
        const string& a = words[i];
        const string& b = words[i + 1];
        int len = min(a.size(), b.size()), j = 0;
        while (j < len && a[j] == b[j]) ++j;
        if (j == len) {
            if (a.size() > b.size()) return "";      // invalid ordering
        } else edge[a[j] - 'a'][b[j] - 'a'] = true;
    }

    vector<int> indegree(26, 0);
    for (int u = 0; u < 26; ++u)
        for (int v = 0; v < 26; ++v)
            if (edge[u][v]) ++indegree[v];

    queue<int> q;
    for (int i = 0; i < 26; ++i) if (present[i] && indegree[i] == 0) q.push(i);

    string out;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        out += char('a' + u);
        for (int v = 0; v < 26; ++v)
            if (edge[u][v] && --indegree[v] == 0) q.push(v);
    }
    int total = count(present.begin(), present.end(), true);
    return (int)out.size() == total ? out : "";      // leftover means a cycle
}

int main() {
    cout << alienOrder({"wrt", "wrf", "er", "ett", "rftt"}) << "\n";   // wertf
    cout << "[" << alienOrder({"abc", "ab"}) << "]\n";                 // [] invalid
    return 0;
}
