/*
 * 164. Top View of Binary Tree
 * Topic: Trees | Difficulty: Medium
 *
 * Print the nodes visible when looking down at the tree from above, left to
 * right.
 *
 * Approach: BFS tracking each node's horizontal distance. The first node seen at
 * a given distance is the one on top, and BFS visits shallower nodes first, so
 * simply refusing to overwrite an existing entry gives the right answer.
 *
 * Time: O(n log n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<int> topView(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    map<int, int> seen;                                // distance -> value
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();
        if (seen.find(hd) == seen.end()) seen[hd] = node->val;
        if (node->left) q.push(make_pair(node->left, hd - 1));
        if (node->right) q.push(make_pair(node->right, hd + 1));
    }
    for (auto& kv : seen) out.push_back(kv.second);
    return out;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);
    for (int x : topView(root)) cout << x << " ";
    cout << "\n";   // 2 1 3 6
    return 0;
}
