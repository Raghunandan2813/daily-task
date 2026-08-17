/*
 * 168. Flatten Binary Tree to Linked List
 * Topic: Trees | Difficulty: Medium
 *
 * Rearrange the tree in place into a right-skewed list following preorder.
 *
 * Approach: Morris-style rewiring. For each node with a left child, find the
 * rightmost node of that left subtree - the preorder predecessor of the current
 * right subtree - graft the right subtree there, then move the whole left
 * subtree over to the right. No stack needed.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void flatten(TreeNode* root) {
    TreeNode* cur = root;
    while (cur) {
        if (cur->left) {
            TreeNode* pred = cur->left;
            while (pred->right) pred = pred->right;   // rightmost of left subtree
            pred->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
        cur = cur->right;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    flatten(root);
    for (TreeNode* n = root; n; n = n->right) cout << n->val << " ";
    cout << "\n";   // 1 2 3 4 5 6
    return 0;
}
