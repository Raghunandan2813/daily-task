/*
 * 208. Course Schedule II
 * Topic: Graphs | Difficulty: Medium
 *
 * Return a valid order in which to take all courses, or an empty list if no such
 * order exists.
 *
 * Approach: the same Kahn traversal as the decision version, but collecting the
 * emitted vertices. The order in which in-degrees reach zero is precisely a
 * topological order.
 *
 * Time: O(V + E)   Space: O(V + E)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, const vector<vector<int> >& prerequisites) {
    vector<vector<int> > adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (const auto& p : prerequisites) {
        adj[p[1]].push_back(p[0]);
        ++indegree[p[0]];
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) if (--indegree[v] == 0) q.push(v);
    }
    if ((int)order.size() != numCourses) return {};   // cycle
    return order;
}

int main() {
    for (int c : findOrder(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}})) cout << c << " ";
    cout << "\n";   // 0 1 2 3
    cout << "impossible size: " << findOrder(2, {{1, 0}, {0, 1}}).size() << "\n";  // 0
    return 0;
}
