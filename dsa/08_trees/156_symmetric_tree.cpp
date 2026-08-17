/*
 * 156. Symmetric Tree
 * Topic: Trees | Difficulty: Easy
 *
 * Decide whether a tree is a mirror image of itself around its centre.
 *
 * Approach: compare two pointers walking down in mirrored directions - the left
 * child of one against the right child of the other. This is the same-tree check
 * with the child pairing crossed over.
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

static bool mirror(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return a->val == b->val && mirror(a->left, b->right) && mirror(a->right, b->left);
}

bool isSymmetric(TreeNode* root) { return !root || mirror(root->left, root->right); }

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << isSymmetric(root) << "\n";   // 1

    root->right->right->val = 99;
    cout << isSymmetric(root) << "\n";   // 0
    return 0;
}
