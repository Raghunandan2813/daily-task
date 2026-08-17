/*
 * 206. Is Graph Bipartite?
 * Topic: Graphs | Difficulty: Medium
 *
 * Decide whether the vertices can be split into two sets so that every edge
 * crosses between them.
 *
 * Approach: two-colour the graph with BFS, giving each neighbour the opposite
 * colour. A conflict - an edge whose endpoints already share a colour - proves
 * an odd-length cycle, which is exactly what makes a graph non-bipartite. Every
 * component is checked.
 *
 * Time: O(V + E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(const vector<vector<int> >& adj) {
    int n = adj.size();
    vector<int> colour(n, -1);
    for (int start = 0; start < n; ++start) {
        if (colour[start] != -1) continue;
        colour[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (colour[v] == -1) { colour[v] = 1 - colour[u]; q.push(v); }
                else if (colour[v] == colour[u]) return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int> > even(4);                 // 4-cycle: bipartite
    even[0] = vector<int>{1, 3};
    even[1] = vector<int>{0, 2};
    even[2] = vector<int>{1, 3};
    even[3] = vector<int>{0, 2};
    cout << isBipartite(even) << "\n";   // 1

    vector<vector<int> > odd(3);                  // triangle: not bipartite
    odd[0] = vector<int>{1, 2};
    odd[1] = vector<int>{0, 2};
    odd[2] = vector<int>{0, 1};
    cout << isBipartite(odd) << "\n";    // 0
    return 0;
}
