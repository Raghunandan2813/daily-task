/*
 * 221. Articulation Points (Cut Vertices)
 * Topic: Graphs | Difficulty: Hard
 *
 * Find every vertex whose removal disconnects the graph.
 *
 * Approach: the same discovery-time and low-link machinery as bridges, with a
 * subtly different test. A non-root u is a cut vertex when some child v has
 * low[v] >= disc[u] (v's subtree cannot bypass u). The root is special: it is a
 * cut vertex only if it has more than one DFS child.
 *
 * Time: O(V + E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(const vector<vector<int> >& adj, int u, int parent, int& timer,
                vector<int>& disc, vector<int>& low, vector<bool>& isCut) {
    disc[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        if (disc[v] == -1) {
            ++children;
            dfs(adj, v, u, timer, disc, low, isCut);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= disc[u]) isCut[u] = true;
        } else low[u] = min(low[u], disc[v]);
    }
    if (parent == -1 && children > 1) isCut[u] = true;   // root special case
}

vector<int> articulationPoints(const vector<vector<int> >& adj) {
    int n = adj.size(), timer = 0;
    vector<int> disc(n, -1), low(n, -1);
    vector<bool> isCut(n, false);
    for (int i = 0; i < n; ++i)
        if (disc[i] == -1) dfs(adj, i, -1, timer, disc, low, isCut);
    vector<int> out;
    for (int i = 0; i < n; ++i) if (isCut[i]) out.push_back(i);
    return out;
}

int main() {
    vector<vector<int> > adj(5);
    auto addEdge = [&](int u, int v) { adj[u].push_back(v); adj[v].push_back(u); };
    addEdge(0, 1); addEdge(1, 2); addEdge(2, 0);
    addEdge(1, 3); addEdge(3, 4);
    for (int v : articulationPoints(adj)) cout << v << " ";
    cout << "\n";   // 1 3
    return 0;
}
