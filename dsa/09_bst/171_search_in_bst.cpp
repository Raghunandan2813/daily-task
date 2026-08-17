/*
 * 171. Search in a Binary Search Tree
 * Topic: BST | Difficulty: Easy
 *
 * Return the subtree rooted at the node with the given value, or null.
 *
 * Approach: exploit the BST ordering - a smaller target can only be in the left
 * subtree and a larger one only in the right, so each comparison discards half
 * the remaining tree. Iteration avoids the recursion stack entirely.
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

TreeNode* searchBST(TreeNode* root, int target) {
    while (root && root->val != target)
        root = (target < root->val) ? root->left : root->right;
    return root;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    TreeNode* found = searchBST(root, 2);
    cout << (found ? found->val : -1) << "\n";   // 2
    cout << (searchBST(root, 5) ? 1 : 0) << "\n";   // 0
    return 0;
}
