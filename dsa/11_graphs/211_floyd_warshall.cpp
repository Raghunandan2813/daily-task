/*
 * 211. Floyd-Warshall All-Pairs Shortest Paths
 * Topic: Graphs | Difficulty: Hard
 *
 * Compute the shortest distance between every pair of vertices.
 *
 * Approach: dynamic programming over intermediate vertices. After processing k,
 * dist[i][j] holds the best path using only vertices 0..k as intermediates, so
 * looping k on the outside is essential - swapping the loop order breaks the
 * recurrence.
 *
 * Time: O(V^3)   Space: O(V^2)
 */
#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX / 4;

void floydWarshall(vector<vector<long long> >& dist) {
    int n = dist.size();
    for (int k = 0; k < n; ++k)                     // intermediate vertex
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
    int n = 4;
    vector<vector<long long> > dist(n, vector<long long>(n, INF));
    for (int i = 0; i < n; ++i) dist[i][i] = 0;
    dist[0][1] = 5; dist[0][3] = 10;
    dist[1][2] = 3; dist[2][3] = 1;

    floydWarshall(dist);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << (dist[i][j] >= INF ? -1 : dist[i][j]) << " ";
        cout << "\n";
    }
    // 0 5 8 9 / -1 0 3 4 / -1 -1 0 1 / -1 -1 -1 0
    return 0;
}
