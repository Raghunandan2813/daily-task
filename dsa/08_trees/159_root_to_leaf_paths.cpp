/*
 * 159. Binary Tree Paths (Root to Leaf)
 * Topic: Trees | Difficulty: Easy
 *
 * List every root-to-leaf path as a string like "1->2->5".
 *
 * Approach: DFS carrying the current path in a vector, appending on the way down
 * and popping on the way back - the standard backtracking pattern. A path is
 * emitted only at a leaf.
 *
 * Time: O(n * h) including string building   Space: O(h)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

static void dfs(TreeNode* node, vector<int>& path, vector<string>& out) {
    if (!node) return;
    path.push_back(node->val);
    if (!node->left && !node->right) {
        string s;
        for (size_t i = 0; i < path.size(); ++i) {
            if (i) s += "->";
            s += to_string(path[i]);
        }
        out.push_back(s);
    } else {
        dfs(node->left, path, out);
        dfs(node->right, path, out);
    }
    path.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<int> path;
    vector<string> out;
    dfs(root, path, out);
    return out;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    for (const string& p : binaryTreePaths(root)) cout << p << " ";
    cout << "\n";   // 1->2->5 1->3
    return 0;
}
