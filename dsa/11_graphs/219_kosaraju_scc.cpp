/*
 * 219. Strongly Connected Components (Kosaraju)
 * Topic: Graphs | Difficulty: Hard
 *
 * Partition a directed graph into strongly connected components - maximal sets
 * where every vertex reaches every other.
 *
 * Approach: two passes. First DFS the graph pushing vertices onto a stack in
 * finish order. Then DFS the reversed graph, taking roots off that stack; each
 * tree produced is one SCC. Reversing keeps a DFS from escaping its own
 * component, which is why the second pass isolates them cleanly.
 *
 * Time: O(V + E)   Space: O(V + E)
 */
#include <bits/stdc++.h>
using namespace std;

static void order(const vector<vector<int> >& adj, int u, vector<bool>& seen,
                  vector<int>& finish) {
    seen[u] = true;
    for (int v : adj[u]) if (!seen[v]) order(adj, v, seen, finish);
    finish.push_back(u);
}

static void collect(const vector<vector<int> >& rev, int u, vector<bool>& seen,
                    vector<int>& comp) {
    seen[u] = true;
    comp.push_back(u);
    for (int v : rev[u]) if (!seen[v]) collect(rev, v, seen, comp);
}

vector<vector<int> > kosaraju(const vector<vector<int> >& adj) {
    int n = adj.size();
    vector<bool> seen(n, false);
    vector<int> finish;
    for (int i = 0; i < n; ++i) if (!seen[i]) order(adj, i, seen, finish);

    vector<vector<int> > rev(n);
    for (int u = 0; u < n; ++u)
        for (int v : adj[u]) rev[v].push_back(u);

    fill(seen.begin(), seen.end(), false);
    vector<vector<int> > sccs;
    for (int i = n - 1; i >= 0; --i) {
        int u = finish[i];
        if (seen[u]) continue;
        vector<int> comp;
        collect(rev, u, seen, comp);
        sort(comp.begin(), comp.end());
        sccs.push_back(comp);
    }
    return sccs;
}

int main() {
    vector<vector<int> > adj(5);
    adj[0] = vector<int>{2};
    adj[1] = vector<int>{0};
    adj[2] = vector<int>{1};
    adj[3] = vector<int>{4};
    for (const auto& c : kosaraju(adj)) {
        cout << "{";
        for (int v : c) cout << v << " ";
        cout << "} ";
    }
    cout << "\n";   // {0 1 2} {3} {4}
    return 0;
}
