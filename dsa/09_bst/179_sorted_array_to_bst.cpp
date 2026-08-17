/*
 * 179. Convert Sorted Array to Height-Balanced BST
 * Topic: BST | Difficulty: Easy
 *
 * Build a height-balanced BST from a sorted array.
 *
 * Approach: pick the middle element as the root so both halves get the same
 * number of nodes, then recurse on each half. Choosing the midpoint is exactly
 * what keeps the two subtree heights within one of each other.
 *
 * Time: O(n)   Space: O(log n) recursion
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

static TreeNode* build(const vector<int>& a, int lo, int hi) {
    if (lo > hi) return nullptr;
    int mid = lo + (hi - lo) / 2;
    TreeNode* root = new TreeNode(a[mid]);
    root->left = build(a, lo, mid - 1);
    root->right = build(a, mid + 1, hi);
    return root;
}

TreeNode* sortedArrayToBST(const vector<int>& a) {
    return build(a, 0, (int)a.size() - 1);
}

static void printLevels(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* n = q.front();
        q.pop();
        cout << n->val << " ";
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
    }
    cout << "\n";
}

int main() {
    printLevels(sortedArrayToBST({-10, -3, 0, 5, 9}));   // 0 -10 5 -3 9
    return 0;
}
