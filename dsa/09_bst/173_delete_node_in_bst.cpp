/*
 * 173. Delete Node in a BST
 * Topic: BST | Difficulty: Medium
 *
 * Remove a value from a BST while keeping it valid.
 *
 * Approach: three cases. A node with zero or one child is simply replaced by
 * that child. A node with two children is replaced by its inorder successor -
 * the smallest value in its right subtree - which is then deleted recursively
 * from that subtree (and is guaranteed to fall into an easier case).
 *
 * Time: O(h)   Space: O(h)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) { TreeNode* r = root->right; delete root; return r; }
        if (!root->right) { TreeNode* l = root->left; delete root; return l; }
        TreeNode* succ = root->right;                  // smallest on the right
        while (succ->left) succ = succ->left;
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }
    return root;
}

static void inorder(TreeNode* n) {
    if (!n) return;
    inorder(n->left);
    cout << n->val << " ";
    inorder(n->right);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    root = deleteNode(root, 3);
    inorder(root);
    cout << "\n";   // 2 4 5 6 7
    return 0;
}
