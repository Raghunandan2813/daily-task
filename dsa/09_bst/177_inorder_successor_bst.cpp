/*
 * 177. Inorder Successor in a BST
 * Topic: BST | Difficulty: Medium
 *
 * Find the smallest value strictly greater than a given target.
 *
 * Approach: descend from the root. Whenever the current node exceeds the target
 * it becomes the best candidate so far and we move left looking for a tighter
 * one; otherwise the successor must lie to the right.
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

TreeNode* inorderSuccessor(TreeNode* root, int target) {
    TreeNode* best = nullptr;
    while (root) {
        if (root->val > target) { best = root; root = root->left; }
        else root = root->right;
    }
    return best;
}

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    cout << inorderSuccessor(root, 8)->val << "\n";    // 10
    cout << inorderSuccessor(root, 14)->val << "\n";   // 20
    cout << (inorderSuccessor(root, 22) ? 1 : 0) << "\n";   // 0
    return 0;
}
