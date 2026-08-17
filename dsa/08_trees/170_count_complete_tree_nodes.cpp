/*
 * 170. Count Complete Tree Nodes
 * Topic: Trees | Difficulty: Medium
 *
 * Count the nodes of a complete binary tree in better than O(n).
 *
 * Approach: measure the left spine and right spine heights. If they match, the
 * subtree is perfect and holds 2^h - 1 nodes, countable instantly. Otherwise
 * recurse into both children - only one branch of the recursion ever hits the
 * imperfect case at each level.
 *
 * Time: O(log^2 n)   Space: O(log n)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

static int leftHeight(TreeNode* n) {
    int h = 0;
    while (n) { ++h; n = n->left; }
    return h;
}
static int rightHeight(TreeNode* n) {
    int h = 0;
    while (n) { ++h; n = n->right; }
    return h;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    int lh = leftHeight(root), rh = rightHeight(root);
    if (lh == rh) return (1 << lh) - 1;                // perfect subtree
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    cout << countNodes(root) << "\n";   // 6
    return 0;
}
