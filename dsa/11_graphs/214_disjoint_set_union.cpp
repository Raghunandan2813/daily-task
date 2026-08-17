/*
 * 214. Disjoint Set Union (Union-Find)
 * Topic: Graphs | Difficulty: Medium
 *
 * Maintain a partition of n elements under union and "same set?" queries.
 *
 * Approach: each set is a tree identified by its root. Two optimisations make it
 * fast: path compression flattens the tree during find, and union by size always
 * hangs the smaller tree under the larger. Together they give an amortised cost
 * of the inverse Ackermann function - effectively constant.
 *
 * Time: O(alpha(n)) amortised per operation   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size_;
    int components;
public:
    explicit DSU(int n) : parent(n), size_(n, 1), components(n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);   // path compression
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (size_[a] < size_[b]) swap(a, b);               // union by size
        parent[b] = a;
        size_[a] += size_[b];
        --components;
        return true;
    }
    bool connected(int a, int b) { return find(a) == find(b); }
    int count() const { return components; }
};

int main() {
    DSU dsu(6);
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    cout << dsu.connected(0, 2) << "\n";   // 1
    cout << dsu.connected(0, 3) << "\n";   // 0
    cout << dsu.count() << "\n";           // 3  ({0,1,2}, {3,4}, {5})
    return 0;
}
