/*
 * 197. Detect Cycle in an Undirected Graph
 * Topic: Graphs | Difficulty: Medium
 *
 * Decide whether an undirected graph contains a cycle.
 *
 * Approach: BFS carrying each vertex's parent. Reaching an already-visited
 * vertex that is not the parent means we found a second route to it, hence a
 * cycle. The parent check is essential - every undirected edge would otherwise
 * look like a two-vertex cycle. All components are scanned.
 *
 * Time: O(V + E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

bool hasCycle(const vector<vector<int> >& adj) {
    int n = adj.size();
    vector<bool> seen(n, false);
    for (int start = 0; start < n; ++start) {
        if (seen[start]) continue;
        queue<pair<int, int> > q;                  // (vertex, parent)
        q.push(make_pair(start, -1));
        seen[start] = true;
        while (!q.empty()) {
            int u = q.front().first, parent = q.front().second;
            q.pop();
            for (int v : adj[u]) {
                if (!seen[v]) { seen[v] = true; q.push(make_pair(v, u)); }
                else if (v != parent) return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int> > cyclic(4);
    cyclic[0] = vector<int>{1, 2};
    cyclic[1] = vector<int>{0, 2};
    cyclic[2] = vector<int>{0, 1};
    cyclic[3] = vector<int>{};
    cout << hasCycle(cyclic) << "\n";   // 1

    vector<vector<int> > tree(3);
    tree[0] = vector<int>{1};
    tree[1] = vector<int>{0, 2};
    tree[2] = vector<int>{1};
    cout << hasCycle(tree) << "\n";     // 0
    return 0;
}
