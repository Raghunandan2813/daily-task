/*
 * 196. Depth-First Search Traversal
 * Topic: Graphs | Difficulty: Easy
 *
 * Visit every vertex reachable from a source, going as deep as possible before
 * backtracking. Both a recursive and an iterative version are shown.
 *
 * Approach: recursion mirrors the call stack naturally; the iterative version
 * uses an explicit stack and must check "already visited" at pop time, since a
 * vertex can be pushed more than once before it is first processed.
 *
 * Time: O(V + E)   Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;

static void dfsRec(const vector<vector<int> >& adj, int u, vector<bool>& seen,
                   vector<int>& order) {
    seen[u] = true;
    order.push_back(u);
    for (int v : adj[u]) if (!seen[v]) dfsRec(adj, v, seen, order);
}

vector<int> dfsRecursive(const vector<vector<int> >& adj, int source) {
    vector<bool> seen(adj.size(), false);
    vector<int> order;
    dfsRec(adj, source, seen, order);
    return order;
}

vector<int> dfsIterative(const vector<vector<int> >& adj, int source) {
    vector<bool> seen(adj.size(), false);
    vector<int> order;
    stack<int> st;
    st.push(source);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (seen[u]) continue;                    // may have been pushed twice
        seen[u] = true;
        order.push_back(u);
        for (int i = (int)adj[u].size() - 1; i >= 0; --i)
            if (!seen[adj[u][i]]) st.push(adj[u][i]);
    }
    return order;
}

int main() {
    vector<vector<int> > adj(5);
    adj[0] = vector<int>{1, 2};
    adj[1] = vector<int>{0, 3};
    adj[2] = vector<int>{0, 4};
    adj[3] = vector<int>{1};
    adj[4] = vector<int>{2};
    for (int v : dfsRecursive(adj, 0)) cout << v << " ";
    cout << "\n";   // 0 1 3 2 4
    for (int v : dfsIterative(adj, 0)) cout << v << " ";
    cout << "\n";   // 0 1 3 2 4
    return 0;
}
