/*
 * 157. Invert Binary Tree
 * Topic: Trees | Difficulty: Easy
 *
 * Mirror a binary tree by swapping every node's two children.
 *
 * Approach: swap the children at the current node, then recurse into both.
 * Because the swap is symmetric, doing it before or after the recursion gives
 * the same result.
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

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

static void printInorder(TreeNode* n) {
    if (!n) return;
    printInorder(n->left);
    cout << n->val << " ";
    printInorder(n->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    printInorder(invertTree(root));
    cout << "\n";   // 7 4 3 2 1
    return 0;
}
