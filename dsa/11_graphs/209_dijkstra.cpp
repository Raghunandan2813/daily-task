/*
 * 209. Dijkstra's Shortest Path
 * Topic: Graphs | Difficulty: Hard
 *
 * Find the shortest distance from a source to every vertex in a graph with
 * non-negative edge weights.
 *
 * Approach: greedily settle the closest unsettled vertex, using a min-heap keyed
 * on tentative distance. Non-negative weights are what make the greedy choice
 * safe - a settled distance can never be improved later. Stale heap entries are
 * skipped by comparing against the recorded distance.
 *
 * Time: O((V + E) log V)   Space: O(V + E)
 */
#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(const vector<vector<pair<int, int> > >& adj, int src) {
    const long long INF = LLONG_MAX;
    vector<long long> dist(adj.size(), INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                   greater<pair<long long, int> > > pq;
    dist[src] = 0;
    pq.push(make_pair(0LL, src));
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;                  // stale entry
        for (const auto& e : adj[u]) {
            int v = e.first, w = e.second;
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<pair<int, int> > > adj(5);        // (neighbour, weight)
    adj[0].push_back(make_pair(1, 4));
    adj[0].push_back(make_pair(2, 1));
    adj[2].push_back(make_pair(1, 2));
    adj[1].push_back(make_pair(3, 1));
    adj[2].push_back(make_pair(3, 5));
    adj[3].push_back(make_pair(4, 3));
    for (long long d : dijkstra(adj, 0)) cout << d << " ";
    cout << "\n";   // 0 3 1 4 7
    return 0;
}
