/*
 * 166. Construct Binary Tree from Inorder and Postorder Traversal
 * Topic: Trees | Difficulty: Medium
 *
 * Rebuild a binary tree given its inorder and postorder sequences.
 *
 * Approach: the mirror of the preorder version - postorder gives the root last,
 * so consume the postorder array from the right and build the right subtree
 * before the left one.
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

static TreeNode* build(const vector<int>& post, int postL, int postR,
                       int inL, const unordered_map<int, int>& pos) {
    if (postL > postR) return nullptr;
    TreeNode* root = new TreeNode(post[postR]);
    int rootIn = pos.at(post[postR]);
    int leftSize = rootIn - inL;
    root->left = build(post, postL, postL + leftSize - 1, inL, pos);
    root->right = build(post, postL + leftSize, postR - 1, rootIn + 1, pos);
    return root;
}

TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
    unordered_map<int, int> pos;
    for (int i = 0; i < (int)inorder.size(); ++i) pos[inorder[i]] = i;
    return build(postorder, 0, postorder.size() - 1, 0, pos);
}

static void printPre(TreeNode* n) {
    if (!n) return;
    cout << n->val << " ";
    printPre(n->left);
    printPre(n->right);
}

int main() {
    TreeNode* root = buildTree({9, 3, 15, 20, 7}, {9, 15, 7, 20, 3});
    printPre(root);
    cout << "\n";   // 3 9 20 15 7
    return 0;
}
