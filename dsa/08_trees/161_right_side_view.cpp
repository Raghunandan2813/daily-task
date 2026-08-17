/*
 * 161. Binary Tree Right Side View
 * Topic: Trees | Difficulty: Medium
 *
 * Return the values visible when the tree is viewed from the right - the last
 * node of each level.
 *
 * Approach: level-order BFS, recording only the final node dequeued at each
 * level. Swapping that to the first node would give the left side view.
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

vector<int> rightSideView(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (i == levelSize - 1) out.push_back(node->val);   // rightmost
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return out;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    for (int x : rightSideView(root)) cout << x << " ";
    cout << "\n";   // 1 3 4
    return 0;
}
