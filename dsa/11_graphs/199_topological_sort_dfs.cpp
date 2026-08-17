/*
 * 199. Topological Sort (DFS)
 * Topic: Graphs | Difficulty: Medium
 *
 * Order the vertices of a DAG so that every edge points forward in the ordering.
 *
 * Approach: DFS and push each vertex onto a stack once all its descendants are
 * finished. A vertex therefore lands below everything it depends on, so reading
 * the stack top-down gives a valid topological order.
 *
 * Time: O(V + E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

static void dfs(const vector<vector<int> >& adj, int u, vector<bool>& seen,
                vector<int>& order) {
    seen[u] = true;
    for (int v : adj[u]) if (!seen[v]) dfs(adj, v, seen, order);
    order.push_back(u);                            // post-order
}

vector<int> topologicalSort(const vector<vector<int> >& adj) {
    vector<bool> seen(adj.size(), false);
    vector<int> order;
    for (int i = 0; i < (int)adj.size(); ++i)
        if (!seen[i]) dfs(adj, i, seen, order);
    reverse(order.begin(), order.end());
    return order;
}

int main() {
    vector<vector<int> > adj(6);
    adj[5] = vector<int>{0, 2};
    adj[4] = vector<int>{0, 1};
    adj[2] = vector<int>{3};
    adj[3] = vector<int>{1};
    for (int v : topologicalSort(adj)) cout << v << " ";
    cout << "\n";   // 5 4 2 3 1 0
    return 0;
}
