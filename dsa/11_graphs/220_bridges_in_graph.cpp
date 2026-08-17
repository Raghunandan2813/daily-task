/*
 * 220. Bridges in a Graph (Tarjan)
 * Topic: Graphs | Difficulty: Hard
 *
 * Find every edge whose removal increases the number of connected components.
 *
 * Approach: Tarjan's algorithm. During DFS record each vertex's discovery time
 * and its low-link - the earliest discovery time reachable from its subtree via
 * one back edge. Edge (u, v) is a bridge exactly when low[v] > disc[u], meaning
 * v's subtree has no alternative route back above u.
 *
 * Time: O(V + E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(const vector<vector<int> >& adj, int u, int parent, int& timer,
                vector<int>& disc, vector<int>& low,
                vector<pair<int, int> >& bridges) {
    disc[u] = low[u] = timer++;
    for (int v : adj[u]) {
        if (v == parent) continue;
        if (disc[v] == -1) {
            dfs(adj, v, u, timer, disc, low, bridges);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) bridges.push_back(make_pair(u, v));
        } else low[u] = min(low[u], disc[v]);       // back edge
    }
}

vector<pair<int, int> > findBridges(const vector<vector<int> >& adj) {
    int n = adj.size(), timer = 0;
    vector<int> disc(n, -1), low(n, -1);
    vector<pair<int, int> > bridges;
    for (int i = 0; i < n; ++i)
        if (disc[i] == -1) dfs(adj, i, -1, timer, disc, low, bridges);
    return bridges;
}

int main() {
    vector<vector<int> > adj(5);
    auto addEdge = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    addEdge(0, 1); addEdge(1, 2); addEdge(2, 0);    // a cycle: no bridges inside
    addEdge(1, 3); addEdge(3, 4);                   // a tail: both are bridges
    for (const auto& b : findBridges(adj)) cout << b.first << "-" << b.second << " ";
    cout << "\n";   // 3-4 1-3
    return 0;
}
