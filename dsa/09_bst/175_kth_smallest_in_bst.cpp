/*
 * 175. Kth Smallest Element in a BST
 * Topic: BST | Difficulty: Medium
 *
 * Return the k-th smallest value (1-indexed).
 *
 * Approach: an inorder traversal of a BST emits values in sorted order, so run
 * an iterative inorder and stop as soon as k values have been produced. That
 * makes the cost O(h + k) rather than a full O(n) traversal.
 *
 * Time: O(h + k)   Space: O(h)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->left; }
        cur = st.top();
        st.pop();
        if (--k == 0) return cur->val;
        cur = cur->right;
    }
    return -1;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    cout << kthSmallest(root, 3) << "\n";   // 3
    cout << kthSmallest(root, 1) << "\n";   // 1
    return 0;
}
