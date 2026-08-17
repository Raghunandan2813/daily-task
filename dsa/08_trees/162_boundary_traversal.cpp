/*
 * 162. Boundary Traversal of Binary Tree
 * Topic: Trees | Difficulty: Medium
 *
 * Print the boundary anticlockwise: root, then the left boundary top-down, then
 * all leaves left to right, then the right boundary bottom-up.
 *
 * Approach: three separate walks. The left and right boundary walks prefer the
 * child on their own side and fall back to the other, and both stop before
 * leaves so the leaf pass does not duplicate them.
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

static bool isLeaf(TreeNode* n) { return n && !n->left && !n->right; }

static void addLeaves(TreeNode* n, vector<int>& out) {
    if (!n) return;
    if (isLeaf(n)) { out.push_back(n->val); return; }
    addLeaves(n->left, out);
    addLeaves(n->right, out);
}

vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    if (!isLeaf(root)) out.push_back(root->val);

    for (TreeNode* n = root->left; n && !isLeaf(n); )   // left boundary, top-down
        { out.push_back(n->val); n = n->left ? n->left : n->right; }

    addLeaves(root, out);

    vector<int> rightSide;                              // right boundary, bottom-up
    for (TreeNode* n = root->right; n && !isLeaf(n); )
        { rightSide.push_back(n->val); n = n->right ? n->right : n->left; }
    out.insert(out.end(), rightSide.rbegin(), rightSide.rend());
    return out;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    for (int x : boundaryTraversal(root)) cout << x << " ";
    cout << "\n";   // 1 2 4 5 6 3
    return 0;
}
