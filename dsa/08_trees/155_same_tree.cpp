/*
 * 155. Same Tree
 * Topic: Trees | Difficulty: Easy
 *
 * Decide whether two binary trees are structurally identical with equal values.
 *
 * Approach: compare the roots, then recurse pairwise on the left and right
 * children. Two null pointers match; one null and one node do not.
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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main() {
    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(2);
    a->right = new TreeNode(3);

    TreeNode* b = new TreeNode(1);
    b->left = new TreeNode(2);
    b->right = new TreeNode(3);
    cout << isSameTree(a, b) << "\n";   // 1

    TreeNode* c = new TreeNode(1);
    c->right = new TreeNode(2);
    cout << isSameTree(a, c) << "\n";   // 0
    return 0;
}
