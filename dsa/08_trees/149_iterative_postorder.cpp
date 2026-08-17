/*
 * 149. Iterative Postorder Traversal
 * Topic: Trees | Difficulty: Hard
 *
 * Produce the postorder sequence without recursion.
 *
 * Approach: run a modified preorder that visits root, right, left - the exact
 * reverse of postorder - then reverse the result. This uses one stack instead of
 * the usual two-stack or last-visited-pointer schemes.
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

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        out.push_back(node->val);
        if (node->left) st.push(node->left);         // gives root, right, left
        if (node->right) st.push(node->right);
    }
    reverse(out.begin(), out.end());
    return out;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    for (int x : postorderTraversal(root)) cout << x << " ";
    cout << "\n";   // 4 5 2 3 1
    return 0;
}
