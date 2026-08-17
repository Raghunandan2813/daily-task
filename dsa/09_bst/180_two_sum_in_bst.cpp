/*
 * 180. Two Sum in a BST
 * Topic: BST | Difficulty: Easy
 *
 * Decide whether two distinct nodes sum to a target value.
 *
 * Approach: a BST inorder traversal is sorted, so run two iterators - one
 * forward (next smallest) and one backward (next largest) - and apply the usual
 * two-pointer sum test. Each iterator keeps its own stack, so the space is O(h)
 * rather than O(n) for a flattened array.
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

class BSTIterator {
    stack<TreeNode*> st;
    bool forward;
    void push(TreeNode* n) {
        while (n) { st.push(n); n = forward ? n->left : n->right; }
    }
public:
    BSTIterator(TreeNode* root, bool fwd) : forward(fwd) { push(root); }
    bool hasNext() const { return !st.empty(); }
    int next() {
        TreeNode* n = st.top();
        st.pop();
        push(forward ? n->right : n->left);
        return n->val;
    }
};

bool findTarget(TreeNode* root, int k) {
    if (!root) return false;
    BSTIterator lo(root, true), hi(root, false);
    if (!lo.hasNext() || !hi.hasNext()) return false;
    int a = lo.next(), b = hi.next();
    while (a < b) {
        int sum = a + b;
        if (sum == k) return true;
        if (sum < k) a = lo.next();
        else b = hi.next();
    }
    return false;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    cout << findTarget(root, 9) << "\n";    // 1
    cout << findTarget(root, 28) << "\n";   // 0
    return 0;
}
