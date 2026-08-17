/*
 * 215. Number of Provinces
 * Topic: Graphs | Difficulty: Medium
 *
 * Given an adjacency matrix of cities, count the connected components.
 *
 * Approach: union every connected pair, then count the remaining distinct roots.
 * Only the upper triangle needs scanning since the matrix is symmetric. A DFS
 * per unvisited city would work equally well.
 *
 * Time: O(n^2 * alpha(n))   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    int components;
    explicit DSU(int n) : parent(n), components(n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) { parent[b] = a; --components; }
    }
};

int findCircleNum(const vector<vector<int> >& isConnected) {
    int n = isConnected.size();
    DSU dsu(n);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (isConnected[i][j]) dsu.unite(i, j);
    return dsu.components;
}

int main() {
    cout << findCircleNum({{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << "\n";   // 2
    cout << findCircleNum({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}) << "\n";   // 3
    return 0;
}
