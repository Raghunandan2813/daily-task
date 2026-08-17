/*
 * 146. Binary Tree Traversals (Recursive)
 * Topic: Trees | Difficulty: Easy
 *
 * Produce the inorder, preorder and postorder sequences of a binary tree.
 *
 * Approach: the three orders differ only in where the node itself is visited
 * relative to its subtrees - before (pre), between (in), or after (post). For a
 * BST, inorder yields the values in sorted order.
 *
 * Time: O(n)   Space: O(h) recursion, h = tree height
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, vector<int>& out) {
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->val);
    inorder(root->right, out);
}

void preorder(TreeNode* root, vector<int>& out) {
    if (!root) return;
    out.push_back(root->val);
    preorder(root->left, out);
    preorder(root->right, out);
}

void postorder(TreeNode* root, vector<int>& out) {
    if (!root) return;
    postorder(root->left, out);
    postorder(root->right, out);
    out.push_back(root->val);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> a, b, c;
    inorder(root, a);
    preorder(root, b);
    postorder(root, c);
    for (int x : a) cout << x << " "; cout << "\n";   // 4 2 5 1 3
    for (int x : b) cout << x << " "; cout << "\n";   // 1 2 4 5 3
    for (int x : c) cout << x << " "; cout << "\n";   // 4 5 2 3 1
    return 0;
}
