/*
 * 213. Kruskal's Minimum Spanning Tree
 * Topic: Graphs | Difficulty: Hard
 *
 * Build a minimum spanning tree by considering edges in increasing weight order.
 *
 * Approach: sort all edges, then add each one unless its endpoints are already
 * connected. A disjoint set union structure answers that connectivity question
 * in near-constant time, and it is what stops cycles from forming.
 *
 * Time: O(E log E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank_;
    explicit DSU(int n) : parent(n), rank_(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b]) ++rank_[a];
        return true;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& o) const { return w < o.w; }
};

long long kruskalMST(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long total = 0;
    int used = 0;
    for (const Edge& e : edges) {
        if (dsu.unite(e.u, e.v)) { total += e.w; if (++used == n - 1) break; }
    }
    return total;
}

int main() {
    vector<Edge> edges = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3},
                          {1, 3, 8}, {1, 4, 5}, {2, 4, 7}};
    cout << kruskalMST(5, edges) << "\n";   // 16
    return 0;
}
