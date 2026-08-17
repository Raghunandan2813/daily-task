/*
 * 150. Binary Tree Level Order Traversal
 * Topic: Trees | Difficulty: Medium
 *
 * Return the node values grouped level by level, top to bottom.
 *
 * Approach: BFS with a queue. Recording the queue size at the start of each
 * round tells us exactly how many nodes belong to the current level, which is
 * what lets the output be grouped rather than flat.
 *
 * Time: O(n)   Space: O(width of the tree)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> out;
    if (!root) return out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        out.push_back(level);
    }
    return out;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    for (const auto& lvl : levelOrder(root)) {
        for (int x : lvl) cout << x << " ";
        cout << "| ";
    }
    cout << "\n";   // 3 | 9 20 | 15 7 |
    return 0;
}
