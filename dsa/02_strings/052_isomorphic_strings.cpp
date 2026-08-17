/*
 * 052. Isomorphic Strings
 * Topic: Strings | Difficulty: Easy
 *
 * Two strings are isomorphic if the characters of one can be replaced to obtain
 * the other, with a consistent one-to-one mapping.
 *
 * Approach: keep two maps, s->t and t->s, both required so the mapping stays
 * bijective. Any conflict with a previously recorded pairing rejects the input.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(const string& s, const string& t) {
    if (s.size() != t.size()) return false;
    vector<int> mapST(128, -1), mapTS(128, -1);
    for (int i = 0; i < (int)s.size(); ++i) {
        unsigned char a = s[i], b = t[i];
        if (mapST[a] == -1 && mapTS[b] == -1) {
            mapST[a] = b;
            mapTS[b] = a;
        } else if (mapST[a] != b || mapTS[b] != a) return false;
    }
    return true;
}

int main() {
    cout << isIsomorphic("egg", "add") << "\n";       // 1
    cout << isIsomorphic("foo", "bar") << "\n";       // 0
    cout << isIsomorphic("paper", "title") << "\n";   // 1
    return 0;
}
