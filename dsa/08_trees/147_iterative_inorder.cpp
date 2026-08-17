/*
 * 147. Iterative Inorder Traversal
 * Topic: Trees | Difficulty: Medium
 *
 * Produce the inorder sequence without recursion.
 *
 * Approach: an explicit stack replaces the call stack. Walk as far left as
 * possible pushing nodes, then pop to visit and move to the right child. The
 * stack holds exactly the ancestors whose right subtree is still pending.
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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> out;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->left; }
        cur = st.top();
        st.pop();
        out.push_back(cur->val);
        cur = cur->right;
    }
    return out;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    for (int x : inorderTraversal(root)) cout << x << " ";
    cout << "\n";   // 1 3 2
    return 0;
}
