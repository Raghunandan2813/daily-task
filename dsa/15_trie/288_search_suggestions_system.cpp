/*
 * 288. Search Suggestions System
 * Topic: Trie | Difficulty: Medium
 *
 * As a search word is typed one character at a time, suggest up to three
 * lexicographically smallest products sharing the current prefix.
 *
 * Approach: sort the products, then keep a shrinking window with two pointers.
 * Because the list is sorted, all matches for a prefix form a contiguous block,
 * so each new character only ever narrows that block - the pointers never move
 * backwards.
 *
 * Time: O(n log n + total prefix length)   Space: O(1) beyond the output
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<string> > suggestedProducts(vector<string> products,
                                          const string& searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string> > out;
    int lo = 0, hi = (int)products.size() - 1;
    for (int i = 0; i < (int)searchWord.size(); ++i) {
        char c = searchWord[i];
        while (lo <= hi && (i >= (int)products[lo].size() || products[lo][i] != c)) ++lo;
        while (lo <= hi && (i >= (int)products[hi].size() || products[hi][i] != c)) --hi;
        vector<string> group;
        for (int k = 0; k < 3 && lo + k <= hi; ++k) group.push_back(products[lo + k]);
        out.push_back(group);
    }
    return out;
}

int main() {
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    for (const auto& g : suggestedProducts(products, "mouse")) {
        cout << "[";
        for (const string& s : g) cout << s << " ";
        cout << "] ";
    }
    cout << "\n";
    // [mobile moneypot monitor] [mobile moneypot monitor] [mouse mousepad]
    // [mouse mousepad] [mouse mousepad]
    return 0;
}
