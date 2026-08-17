/*
 * 041. Group Anagrams
 * Topic: Strings | Difficulty: Medium
 *
 * Group a list of strings so that anagrams end up in the same bucket.
 *
 * Approach: two strings are anagrams iff their sorted forms are identical, so
 * the sorted string is a canonical key for a hash map of buckets.
 *
 * Time: O(n * k log k) for n strings of length k   Space: O(n * k)
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(const vector<string>& words) {
    unordered_map<string, vector<string>> buckets;
    for (const string& w : words) {
        string key = w;
        sort(key.begin(), key.end());
        buckets[key].push_back(w);
    }
    vector<vector<string>> out;
    for (auto& kv : buckets) out.push_back(kv.second);
    return out;
}

int main() {
    for (const auto& g : groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"})) {
        cout << "[";
        for (const string& w : g) cout << w << " ";
        cout << "] ";
    }
    cout << "\n";   // [bat] [tan nat] [eat tea ate] (order of groups may vary)
    return 0;
}
