/*
 * 148. Iterative Preorder Traversal
 * Topic: Trees | Difficulty: Medium
 *
 * Produce the preorder sequence without recursion.
 *
 * Approach: a stack seeded with the root. Pop and visit a node, then push its
 * right child before its left one so the left subtree is processed first.
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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        out.push_back(node->val);
        if (node->right) st.push(node->right);       // right first, so left pops first
        if (node->left) st.push(node->left);
    }
    return out;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    for (int x : preorderTraversal(root)) cout << x << " ";
    cout << "\n";   // 1 2 4 3
    return 0;
}
