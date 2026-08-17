/*
 * 153. Diameter of Binary Tree
 * Topic: Trees | Difficulty: Easy
 *
 * Return the length (in edges) of the longest path between any two nodes. The
 * path need not pass through the root.
 *
 * Approach: one post-order pass. At each node the best path *through* it is
 * leftHeight + rightHeight, so track that as a running maximum while the
 * recursion returns heights upward. Computing heights separately would cost
 * O(n^2).
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

static int height(TreeNode* node, int& best) {
    if (!node) return 0;
    int l = height(node->left, best);
    int r = height(node->right, best);
    best = max(best, l + r);                          // path through this node
    return 1 + max(l, r);
}

int diameterOfBinaryTree(TreeNode* root) {
    int best = 0;
    height(root, best);
    return best;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << diameterOfBinaryTree(root) << "\n";   // 3
    return 0;
}
