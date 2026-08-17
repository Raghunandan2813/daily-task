/*
 * 152. Maximum Depth of Binary Tree
 * Topic: Trees | Difficulty: Easy
 *
 * Return the number of nodes on the longest root-to-leaf path.
 *
 * Approach: the depth of a tree is one plus the deeper of its two subtrees, a
 * three-line recursion. An empty subtree contributes depth 0, which is the base
 * case.
 *
 * Time: O(n)   Space: O(h)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << maxDepth(root) << "\n";   // 3
    return 0;
}
