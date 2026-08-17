/*
 * 198. Detect Cycle in a Directed Graph
 * Topic: Graphs | Difficulty: Medium
 *
 * Decide whether a directed graph contains a cycle.
 *
 * Approach: DFS with three colours. White means unvisited, grey means on the
 * current recursion path, black means fully explored. An edge into a grey vertex
 * is a back edge and proves a cycle. The parent trick used for undirected graphs
 * does not work here - direction matters.
 *
 * Time: O(V + E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

static bool dfs(const vector<vector<int> >& adj, int u, vector<int>& colour) {
    colour[u] = 1;                                 // grey: on the current path
    for (int v : adj[u]) {
        if (colour[v] == 1) return true;           // back edge
        if (colour[v] == 0 && dfs(adj, v, colour)) return true;
    }
    colour[u] = 2;                                 // black: done
    return false;
}

bool hasCycle(const vector<vector<int> >& adj) {
    vector<int> colour(adj.size(), 0);
    for (int i = 0; i < (int)adj.size(); ++i)
        if (colour[i] == 0 && dfs(adj, i, colour)) return true;
    return false;
}

int main() {
    vector<vector<int> > cyclic(4);
    cyclic[0] = vector<int>{1};
    cyclic[1] = vector<int>{2};
    cyclic[2] = vector<int>{0};
    cyclic[3] = vector<int>{};
    cout << hasCycle(cyclic) << "\n";   // 1

    vector<vector<int> > dag(4);
    dag[0] = vector<int>{1, 2};
    dag[1] = vector<int>{3};
    dag[2] = vector<int>{3};
    dag[3] = vector<int>{};
    cout << hasCycle(dag) << "\n";      // 0
    return 0;
}
