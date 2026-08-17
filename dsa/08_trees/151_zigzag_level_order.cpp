/*
 * 151. Zigzag Level Order Traversal
 * Topic: Trees | Difficulty: Medium
 *
 * Traverse level by level, alternating the direction on each level.
 *
 * Approach: ordinary BFS, but reverse every other level before appending it.
 * Reversing the collected level is simpler and cheaper than trying to enqueue
 * children in alternating order.
 *
 * Time: O(n)   Space: O(width)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> out;
    if (!root) return out;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
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
        if (!leftToRight) reverse(level.begin(), level.end());
        leftToRight = !leftToRight;
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
    for (const auto& lvl : zigzagLevelOrder(root)) {
        for (int x : lvl) cout << x << " ";
        cout << "| ";
    }
    cout << "\n";   // 3 | 20 9 | 15 7 |
    return 0;
}
