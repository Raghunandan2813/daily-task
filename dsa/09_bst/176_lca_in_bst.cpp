/*
 * 176. Lowest Common Ancestor of a BST
 * Topic: BST | Difficulty: Easy
 *
 * Find the lowest common ancestor of two nodes in a BST.
 *
 * Approach: the BST ordering makes this far simpler than the general tree case.
 * Walk down from the root: if both values are smaller go left, if both are
 * larger go right; the first node that sits between them (or equals one of them)
 * is the split point and hence the LCA.
 *
 * Time: O(h)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    while (root) {
        if (p < root->val && q < root->val) root = root->left;
        else if (p > root->val && q > root->val) root = root->right;
        else return root;
    }
    return nullptr;
}

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    cout << lowestCommonAncestor(root, 2, 8)->val << "\n";   // 6
    cout << lowestCommonAncestor(root, 2, 4)->val << "\n";   // 2
    return 0;
}
