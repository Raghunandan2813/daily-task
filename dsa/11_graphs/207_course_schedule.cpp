/*
 * 207. Course Schedule
 * Topic: Graphs | Difficulty: Medium
 *
 * Given prerequisite pairs, decide whether all courses can be finished.
 *
 * Approach: the courses form a directed graph with an edge from prerequisite to
 * course; finishing everything is possible exactly when that graph is acyclic.
 * Kahn's algorithm answers this directly - if it emits fewer than n courses, the
 * remainder sit in a cycle.
 *
 * Time: O(V + E)   Space: O(V + E)
 */
#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, const vector<vector<int> >& prerequisites) {
    vector<vector<int> > adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (const auto& p : prerequisites) {          // p = {course, prerequisite}
        adj[p[1]].push_back(p[0]);
        ++indegree[p[0]];
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) if (indegree[i] == 0) q.push(i);

    int done = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ++done;
        for (int v : adj[u]) if (--indegree[v] == 0) q.push(v);
    }
    return done == numCourses;
}

int main() {
    cout << canFinish(2, {{1, 0}}) << "\n";            // 1
    cout << canFinish(2, {{1, 0}, {0, 1}}) << "\n";    // 0
    return 0;
}
