/*
 * 160. Lowest Common Ancestor of a Binary Tree
 * Topic: Trees | Difficulty: Medium
 *
 * Find the deepest node that has both given nodes as descendants (a node counts
 * as its own descendant).
 *
 * Approach: post-order recursion returning "a target, or the LCA found below".
 * If both subtrees return non-null, the current node is the split point and
 * therefore the LCA; otherwise propagate whichever side found something.
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if (l && r) return root;                          // split point
    return l ? l : r;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    cout << lowestCommonAncestor(root, root->left, root->right)->val << "\n";        // 3
    cout << lowestCommonAncestor(root, root->left, root->left->right)->val << "\n";  // 5
    return 0;
}
