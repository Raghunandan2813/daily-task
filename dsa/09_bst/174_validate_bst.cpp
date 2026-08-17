/*
 * 174. Validate Binary Search Tree
 * Topic: BST | Difficulty: Medium
 *
 * Decide whether a binary tree satisfies the BST property.
 *
 * Approach: pass an allowed (min, max) range down the recursion, narrowing it at
 * each step. Checking only against the immediate parent is the classic bug - a
 * node can be a valid child yet still violate an ancestor's bound. long long
 * bounds let INT_MIN and INT_MAX appear as real values.
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

static bool valid(TreeNode* n, long long lo, long long hi) {
    if (!n) return true;
    if (n->val <= lo || n->val >= hi) return false;
    return valid(n->left, lo, n->val) && valid(n->right, n->val, hi);
}

bool isValidBST(TreeNode* root) { return valid(root, LLONG_MIN, LLONG_MAX); }

int main() {
    TreeNode* a = new TreeNode(2);
    a->left = new TreeNode(1);
    a->right = new TreeNode(3);
    cout << isValidBST(a) << "\n";   // 1

    TreeNode* b = new TreeNode(5);
    b->left = new TreeNode(1);
    b->right = new TreeNode(4);
    b->right->left = new TreeNode(3);
    b->right->right = new TreeNode(6);
    cout << isValidBST(b) << "\n";   // 0
    return 0;
}
