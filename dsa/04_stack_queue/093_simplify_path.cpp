/*
 * 093. Simplify Path
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * Convert an absolute Unix-style path into its canonical form, resolving "." and
 * ".." and collapsing repeated slashes.
 *
 * Approach: split on '/' and treat the directory list as a stack. ".." pops, "."
 * and empty segments are ignored, anything else is pushed.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

string simplifyPath(const string& path) {
    vector<string> stack;
    stringstream ss(path);
    string token;
    while (getline(ss, token, '/')) {
        if (token.empty() || token == ".") continue;
        if (token == "..") { if (!stack.empty()) stack.pop_back(); }
        else stack.push_back(token);
    }
    string out;
    for (const string& dir : stack) out += "/" + dir;
    return out.empty() ? "/" : out;
}

int main() {
    cout << simplifyPath("/home/") << "\n";           // /home
    cout << simplifyPath("/../") << "\n";             // /
    cout << simplifyPath("/a/./b/../../c/") << "\n";  // /c
    return 0;
}
