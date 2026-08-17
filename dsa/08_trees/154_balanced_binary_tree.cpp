/*
 * 154. Balanced Binary Tree
 * Topic: Trees | Difficulty: Easy
 *
 * Decide whether every node's two subtrees differ in height by at most one.
 *
 * Approach: a single post-order pass returning the height, or -1 as a sentinel
 * meaning "already unbalanced". The sentinel propagates straight to the root, so
 * the whole check costs one traversal instead of recomputing heights per node.
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

static int check(TreeNode* node) {
    if (!node) return 0;
    int l = check(node->left);
    if (l == -1) return -1;
    int r = check(node->right);
    if (r == -1) return -1;
    if (abs(l - r) > 1) return -1;
    return 1 + max(l, r);
}

bool isBalanced(TreeNode* root) { return check(root) != -1; }

int main() {
    TreeNode* a = new TreeNode(3);
    a->left = new TreeNode(9);
    a->right = new TreeNode(20);
    a->right->left = new TreeNode(15);
    a->right->right = new TreeNode(7);
    cout << isBalanced(a) << "\n";   // 1

    TreeNode* b = new TreeNode(1);
    b->left = new TreeNode(2);
    b->left->left = new TreeNode(3);
    b->left->left->left = new TreeNode(4);
    cout << isBalanced(b) << "\n";   // 0
    return 0;
}
