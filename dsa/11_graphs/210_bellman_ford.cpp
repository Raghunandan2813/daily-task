/*
 * 210. Bellman-Ford Algorithm
 * Topic: Graphs | Difficulty: Hard
 *
 * Shortest paths from a source in a graph that may contain negative edge
 * weights, with detection of negative cycles.
 *
 * Approach: relax every edge V-1 times. Any shortest path uses at most V-1
 * edges, so after that many rounds all distances are final. If a V-th round can
 * still improve something, a negative cycle is reachable.
 *
 * Time: O(V * E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };

// Returns false if a negative cycle is reachable from src.
bool bellmanFord(int n, const vector<Edge>& edges, int src, vector<long long>& dist) {
    const long long INF = LLONG_MAX / 4;
    dist.assign(n, INF);
    dist[src] = 0;
    for (int round = 0; round < n - 1; ++round)
        for (const Edge& e : edges)
            if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;

    for (const Edge& e : edges)                     // one extra round
        if (dist[e.u] < INF && dist[e.u] + e.w < dist[e.v]) return false;
    return true;
}

int main() {
    vector<Edge> edges = {{0, 1, 4}, {0, 2, 5}, {1, 2, -3}, {2, 3, 4}, {3, 1, 1}};
    vector<long long> dist;
    cout << bellmanFord(4, edges, 0, dist) << "\n";   // 1 (no negative cycle)
    for (long long d : dist) cout << d << " ";
    cout << "\n";   // 0 4 1 5

    vector<Edge> neg = {{0, 1, 1}, {1, 2, -1}, {2, 1, -1}};
    cout << bellmanFord(3, neg, 0, dist) << "\n";     // 0 (negative cycle)
    return 0;
}
