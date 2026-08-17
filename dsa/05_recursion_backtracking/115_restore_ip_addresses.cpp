/*
 * 115. Restore IP Addresses
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * Insert dots into a digit string to form every valid IPv4 address. Each octet
 * must be 0-255 with no leading zeroes.
 *
 * Approach: backtrack over the four octets, trying segment lengths of 1 to 3 at
 * each step. Pruning on the remaining character count keeps the search tiny.
 *
 * Time: O(1) - at most 3^4 splits   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static bool validOctet(const string& s) {
    if (s.empty() || s.size() > 3) return false;
    if (s.size() > 1 && s[0] == '0') return false;     // no leading zero
    return stoi(s) <= 255;
}

static void dfs(const string& s, int start, int part, vector<string>& cur,
                vector<string>& out) {
    int remaining = (int)s.size() - start;
    if (part == 4) {
        if (remaining == 0) out.push_back(cur[0] + "." + cur[1] + "." + cur[2] + "." + cur[3]);
        return;
    }
    int partsLeft = 4 - part;
    if (remaining < partsLeft || remaining > partsLeft * 3) return;   // prune
    for (int len = 1; len <= 3 && start + len <= (int)s.size(); ++len) {
        string piece = s.substr(start, len);
        if (!validOctet(piece)) continue;
        cur.push_back(piece);
        dfs(s, start + len, part + 1, cur, out);
        cur.pop_back();
    }
}

vector<string> restoreIpAddresses(const string& s) {
    vector<string> cur, out;
    dfs(s, 0, 0, cur, out);
    return out;
}

int main() {
    for (const string& ip : restoreIpAddresses("25525511135")) cout << ip << " ";
    cout << "\n";   // 255.255.11.135 255.255.111.35
    return 0;
}
