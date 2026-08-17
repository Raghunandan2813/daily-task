/*
 * 165. Construct Binary Tree from Preorder and Inorder Traversal
 * Topic: Trees | Difficulty: Medium
 *
 * Rebuild a binary tree given its preorder and inorder sequences (values are
 * distinct).
 *
 * Approach: preorder gives the root first; locating that root in the inorder
 * sequence splits it into the left and right subtrees and tells us their sizes,
 * which in turn slices the preorder array. A hash map of inorder positions turns
 * the lookup into O(1).
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

static TreeNode* build(const vector<int>& pre, int preL, int preR,
                       int inL, const unordered_map<int, int>& pos) {
    if (preL > preR) return nullptr;
    TreeNode* root = new TreeNode(pre[preL]);
    int rootIn = pos.at(pre[preL]);
    int leftSize = rootIn - inL;
    root->left = build(pre, preL + 1, preL + leftSize, inL, pos);
    root->right = build(pre, preL + leftSize + 1, preR, rootIn + 1, pos);
    return root;
}

TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    unordered_map<int, int> pos;
    for (int i = 0; i < (int)inorder.size(); ++i) pos[inorder[i]] = i;
    return build(preorder, 0, preorder.size() - 1, 0, pos);
}

static void printPost(TreeNode* n) {
    if (!n) return;
    printPost(n->left);
    printPost(n->right);
    cout << n->val << " ";
}

int main() {
    TreeNode* root = buildTree({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7});
    printPost(root);
    cout << "\n";   // 9 15 7 20 3
    return 0;
}
