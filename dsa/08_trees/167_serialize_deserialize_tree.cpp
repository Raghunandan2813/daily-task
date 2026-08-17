/*
 * 167. Serialize and Deserialize Binary Tree
 * Topic: Trees | Difficulty: Hard
 *
 * Encode a binary tree as a string and decode it back to the identical tree.
 *
 * Approach: preorder with explicit null markers. Recording nulls is what makes
 * the single sequence unambiguous - without them, a preorder traversal alone
 * cannot determine the shape.
 *
 * Time: O(n) both ways   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

static void encode(TreeNode* n, string& out) {
    if (!n) { out += "# "; return; }
    out += to_string(n->val) + " ";
    encode(n->left, out);
    encode(n->right, out);
}

string serialize(TreeNode* root) {
    string out;
    encode(root, out);
    return out;
}

static TreeNode* decode(istringstream& in) {
    string token;
    if (!(in >> token) || token == "#") return nullptr;
    TreeNode* node = new TreeNode(stoi(token));
    node->left = decode(in);
    node->right = decode(in);
    return node;
}

TreeNode* deserialize(const string& data) {
    istringstream in(data);
    return decode(in);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string s = serialize(root);
    cout << s << "\n";                       // 1 2 # # 3 4 # # 5 # #
    cout << serialize(deserialize(s)) << "\n";   // identical round trip
    return 0;
}
