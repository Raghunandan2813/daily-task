/*
 * 181. Recover Binary Search Tree
 * Topic: BST | Difficulty: Hard
 *
 * Exactly two nodes of a BST were swapped by mistake. Restore the tree without
 * changing its structure.
 *
 * Approach: an inorder walk of a correct BST is strictly increasing, so each
 * descent marks a violation. If the two swapped nodes are adjacent in inorder
 * there is one violation; if they are far apart there are two. Record the first
 * offender at the first dip and the second offender at the last dip, then swap
 * their values.
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

static void walk(TreeNode* node, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
    if (!node) return;
    walk(node->left, prev, first, second);
    if (prev && prev->val > node->val) {
        if (!first) first = prev;                      // first dip
        second = node;                                 // latest dip
    }
    prev = node;
    walk(node->right, prev, first, second);
}

void recoverTree(TreeNode* root) {
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    walk(root, prev, first, second);
    if (first && second) swap(first->val, second->val);
}

static void inorder(TreeNode* n) {
    if (!n) return;
    inorder(n->left);
    cout << n->val << " ";
    inorder(n->right);
}

int main() {
    TreeNode* root = new TreeNode(3);      // 1 and 3 are swapped
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    recoverTree(root);
    inorder(root);
    cout << "\n";   // 1 2 3 4
    return 0;
}
