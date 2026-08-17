/*
 * 200. Topological Sort (Kahn's Algorithm)
 * Topic: Graphs | Difficulty: Medium
 *
 * Produce a topological order using in-degrees, and detect a cycle if one exists.
 *
 * Approach: repeatedly emit any vertex with in-degree zero and decrement the
 * in-degrees of its successors. If fewer than V vertices come out, the leftovers
 * form a cycle - which makes Kahn's algorithm a cycle detector as well as a
 * sorter.
 *
 * Time: O(V + E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> kahn(const vector<vector<int> >& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; ++u)
        for (int v : adj[u]) ++indegree[v];

    queue<int> q;
    for (int i = 0; i < n; ++i) if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) if (--indegree[v] == 0) q.push(v);
    }
    if ((int)order.size() != n) return {};          // a cycle exists
    return order;
}

int main() {
    vector<vector<int> > dag(6);
    dag[5] = vector<int>{0, 2};
    dag[4] = vector<int>{0, 1};
    dag[2] = vector<int>{3};
    dag[3] = vector<int>{1};
    for (int v : kahn(dag)) cout << v << " ";
    cout << "\n";   // 4 5 0 2 3 1

    vector<vector<int> > cyclic(2);
    cyclic[0] = vector<int>{1};
    cyclic[1] = vector<int>{0};
    cout << "cycle -> size " << kahn(cyclic).size() << "\n";   // 0
    return 0;
}
