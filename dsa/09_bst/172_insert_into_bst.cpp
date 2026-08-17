/*
 * 172. Insert into a Binary Search Tree
 * Topic: BST | Difficulty: Medium
 *
 * Insert a value into a BST, keeping it a valid BST. The value is not already
 * present.
 *
 * Approach: descend as a search would until the correct child slot is null, and
 * attach the new node there. A new value always becomes a leaf, so no
 * restructuring is required.
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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    TreeNode* cur = root;
    while (true) {
        if (val < cur->val) {
            if (!cur->left) { cur->left = new TreeNode(val); return root; }
            cur = cur->left;
        } else {
            if (!cur->right) { cur->right = new TreeNode(val); return root; }
            cur = cur->right;
        }
    }
}

static void inorder(TreeNode* n) {
    if (!n) return;
    inorder(n->left);
    cout << n->val << " ";
    inorder(n->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    insertIntoBST(root, 5);
    inorder(root);
    cout << "\n";   // 2 4 5 7
    return 0;
}
