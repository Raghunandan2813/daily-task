/*
 * 212. Prim's Minimum Spanning Tree
 * Topic: Graphs | Difficulty: Hard
 *
 * Find the total weight of a minimum spanning tree of a connected weighted
 * undirected graph.
 *
 * Approach: grow a single tree from an arbitrary vertex, always absorbing the
 * cheapest edge that leaves it. A min-heap of candidate edges makes finding that
 * edge O(log E). The cut property guarantees the greedy choice is safe.
 *
 * Time: O(E log V)   Space: O(V + E)
 */
#include <bits/stdc++.h>
using namespace std;

long long primMST(const vector<vector<pair<int, int> > >& adj) {
    int n = adj.size();
    vector<bool> inTree(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > > pq;    // (weight, vertex)
    pq.push(make_pair(0, 0));
    long long total = 0;
    int taken = 0;
    while (!pq.empty() && taken < n) {
        int w = pq.top().first, u = pq.top().second;
        pq.pop();
        if (inTree[u]) continue;
        inTree[u] = true;
        total += w;
        ++taken;
        for (const auto& e : adj[u])
            if (!inTree[e.first]) pq.push(make_pair(e.second, e.first));
    }
    return total;
}

int main() {
    vector<vector<pair<int, int> > > adj(5);
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    };
    addEdge(0, 1, 2); addEdge(0, 3, 6); addEdge(1, 2, 3);
    addEdge(1, 3, 8); addEdge(1, 4, 5); addEdge(2, 4, 7);
    cout << primMST(adj) << "\n";   // 16
    return 0;
}
