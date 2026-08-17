/*
 * 195. Breadth-First Search Traversal
 * Topic: Graphs | Difficulty: Easy
 *
 * Visit every vertex reachable from a source in order of increasing distance.
 *
 * Approach: a queue plus a visited array. Marking a vertex when it is *enqueued*
 * rather than when it is dequeued is what stops it being queued twice. Because
 * BFS expands in layers, it also yields shortest paths on unweighted graphs.
 *
 * Time: O(V + E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(const vector<vector<int> >& adj, int source) {
    vector<bool> seen(adj.size(), false);
    vector<int> order;
    queue<int> q;
    seen[source] = true;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (!seen[v]) { seen[v] = true; q.push(v); }
    }
    return order;
}

int main() {
    vector<vector<int> > adj(6);
    adj[0] = vector<int>{1, 2};
    adj[1] = vector<int>{0, 3};
    adj[2] = vector<int>{0, 4};
    adj[3] = vector<int>{1, 5};
    adj[4] = vector<int>{2};
    adj[5] = vector<int>{3};
    for (int v : bfs(adj, 0)) cout << v << " ";
    cout << "\n";   // 0 1 2 3 4 5
    return 0;
}
