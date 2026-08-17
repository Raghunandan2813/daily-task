/*
 * 110. Letter Combinations of a Phone Number
 * Topic: Recursion & Backtracking | Difficulty: Medium
 *
 * Map a string of digits (2-9) to every letter combination it could spell on an
 * old phone keypad.
 *
 * Approach: DFS over the digit positions, appending each candidate letter for
 * the current digit before recursing to the next one.
 *
 * Time: O(4^n) - up to four letters per digit   Space: O(n) recursion
 */
#include <bits/stdc++.h>
using namespace std;

static const char* KEYS[] = {"", "", "abc", "def", "ghi", "jkl",
                             "mno", "pqrs", "tuv", "wxyz"};

static void dfs(const string& digits, int i, string& cur, vector<string>& out) {
    if (i == (int)digits.size()) { out.push_back(cur); return; }
    const char* letters = KEYS[digits[i] - '0'];
    for (int k = 0; letters[k]; ++k) {
        cur.push_back(letters[k]);
        dfs(digits, i + 1, cur, out);
        cur.pop_back();
    }
}

vector<string> letterCombinations(const string& digits) {
    vector<string> out;
    if (digits.empty()) return out;
    string cur;
    dfs(digits, 0, cur, out);
    return out;
}

int main() {
    for (const string& s : letterCombinations("23")) cout << s << " ";
    cout << "\n";   // ad ae af bd be bf cd ce cf
    return 0;
}
