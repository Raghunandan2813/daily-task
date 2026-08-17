/*
 * 169. Binary Tree Maximum Path Sum
 * Topic: Trees | Difficulty: Hard
 *
 * Find the largest sum along any path between two nodes. Values may be negative
 * and the path need not touch the root.
 *
 * Approach: post-order recursion returning the best downward path *starting* at
 * a node. Negative contributions are clamped to zero (better to skip that branch
 * entirely), and at each node the best path bending through it -
 * node + leftGain + rightGain - updates a global maximum.
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

static int gain(TreeNode* node, int& best) {
    if (!node) return 0;
    int l = max(0, gain(node->left, best));            // drop negative branches
    int r = max(0, gain(node->right, best));
    best = max(best, node->val + l + r);               // path bending here
    return node->val + max(l, r);                      // must go straight down
}

int maxPathSum(TreeNode* root) {
    int best = INT_MIN;
    gain(root, best);
    return best;
}

int main() {
    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(2);
    a->right = new TreeNode(3);
    cout << maxPathSum(a) << "\n";   // 6

    TreeNode* b = new TreeNode(-10);
    b->left = new TreeNode(9);
    b->right = new TreeNode(20);
    b->right->left = new TreeNode(15);
    b->right->right = new TreeNode(7);
    cout << maxPathSum(b) << "\n";   // 42
    return 0;
}
