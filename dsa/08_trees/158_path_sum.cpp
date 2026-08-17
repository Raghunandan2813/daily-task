/*
 * 158. Path Sum
 * Topic: Trees | Difficulty: Easy
 *
 * Decide whether some root-to-leaf path adds up to a target sum.
 *
 * Approach: subtract the node's value from the target as we descend. At a leaf,
 * success means the remainder is exactly zero. Testing for a leaf (not for null)
 * matters, since a null child of a one-armed node is not a valid path end.
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

bool hasPathSum(TreeNode* root, int target) {
    if (!root) return false;
    if (!root->left && !root->right) return target == root->val;
    int remain = target - root->val;
    return hasPathSum(root->left, remain) || hasPathSum(root->right, remain);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    cout << hasPathSum(root, 22) << "\n";   // 1
    cout << hasPathSum(root, 26) << "\n";   // 0
    return 0;
}
