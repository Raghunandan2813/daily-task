/*
 * 222. Cheapest Flights Within K Stops
 * Topic: Graphs | Difficulty: Medium
 *
 * Find the cheapest route from src to dst using at most k intermediate stops.
 *
 * Approach: Bellman-Ford limited to k+1 rounds, since a route with k stops uses
 * at most k+1 edges. Each round relaxes from a snapshot of the previous round's
 * distances - without that copy, a single round could chain several edges and
 * silently exceed the stop limit. Dijkstra does not apply directly because the
 * cheapest route may use more hops than allowed.
 *
 * Time: O(k * E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, const vector<vector<int> >& flights,
                      int src, int dst, int k) {
    const int INF = INT_MAX / 2;
    vector<int> dist(n, INF);
    dist[src] = 0;
    for (int round = 0; round <= k; ++round) {
        vector<int> prev = dist;                    // snapshot of last round
        for (const auto& f : flights) {
            int u = f[0], v = f[1], w = f[2];
            if (prev[u] + w < dist[v]) dist[v] = prev[u] + w;
        }
    }
    return dist[dst] == INF ? -1 : dist[dst];
}

int main() {
    vector<vector<int> > flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << findCheapestPrice(3, flights, 0, 2, 1) << "\n";   // 200
    cout << findCheapestPrice(3, flights, 0, 2, 0) << "\n";   // 500
    return 0;
}
