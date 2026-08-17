/*
 * 178. Floor and Ceil in a BST
 * Topic: BST | Difficulty: Medium
 *
 * The floor is the largest value <= the target; the ceil is the smallest value
 * >= the target. Return -1 when one does not exist.
 *
 * Approach: a single descent for each. Every time the current node satisfies the
 * bound it is recorded as the best candidate, then we move in the direction that
 * could tighten it.
 *
 * Time: O(h) each   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

int findFloor(TreeNode* root, int key) {
    int best = -1;
    while (root) {
        if (root->val == key) return key;
        if (root->val < key) { best = root->val; root = root->right; }
        else root = root->left;
    }
    return best;
}

int findCeil(TreeNode* root, int key) {
    int best = -1;
    while (root) {
        if (root->val == key) return key;
        if (root->val > key) { best = root->val; root = root->left; }
        else root = root->right;
    }
    return best;
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    cout << findFloor(root, 5) << " " << findCeil(root, 5) << "\n";     // 4 6
    cout << findFloor(root, 1) << " " << findCeil(root, 15) << "\n";    // -1 -1
    return 0;
}
