/*
 * 163. Vertical Order Traversal
 * Topic: Trees | Difficulty: Hard
 *
 * Group node values by their horizontal distance from the root, ordering columns
 * left to right and, within a column, top to bottom.
 *
 * Approach: BFS assigning each node a column (parent's column -/+ 1) and a row.
 * A map keyed by column keeps the columns sorted automatically, and BFS order
 * guarantees rows come out top-down.
 *
 * Time: O(n log n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> out;
    if (!root) return out;
    map<int, vector<int>> columns;                     // column -> values
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int col = q.front().second;
        q.pop();
        columns[col].push_back(node->val);
        if (node->left) q.push(make_pair(node->left, col - 1));
        if (node->right) q.push(make_pair(node->right, col + 1));
    }
    for (auto& kv : columns) out.push_back(kv.second);
    return out;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    for (const auto& col : verticalOrder(root)) {
        for (int x : col) cout << x << " ";
        cout << "| ";
    }
    cout << "\n";   // 9 | 3 15 | 20 | 7 |
    return 0;
}
