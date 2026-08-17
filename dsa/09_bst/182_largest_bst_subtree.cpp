/*
 * 182. Largest BST Subtree
 * Topic: BST | Difficulty: Hard
 *
 * Find the number of nodes in the largest subtree that is itself a valid BST.
 *
 * Approach: one post-order pass returning, for each subtree, its min value, max
 * value, node count and whether it is a BST. A node forms a BST when both
 * children do and its value fits strictly between the left subtree's max and the
 * right subtree's min. Bottom-up aggregation avoids re-validating subtrees.
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

struct Info {
    int minVal, maxVal, size;
    bool isBST;
};

static Info walk(TreeNode* node, int& best) {
    if (!node) {
        Info empty = {INT_MAX, INT_MIN, 0, true};
        return empty;
    }
    Info l = walk(node->left, best);
    Info r = walk(node->right, best);

    Info cur;
    cur.isBST = l.isBST && r.isBST && l.maxVal < node->val && node->val < r.minVal;
    cur.size = cur.isBST ? l.size + r.size + 1 : 0;
    cur.minVal = min(node->val, l.minVal);
    cur.maxVal = max(node->val, r.maxVal);
    if (cur.isBST) best = max(best, cur.size);
    return cur;
}

int largestBSTSubtree(TreeNode* root) {
    int best = 0;
    walk(root, best);
    return best;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);      // breaks the BST property
    cout << largestBSTSubtree(root) << "\n";   // 3
    return 0;
}
