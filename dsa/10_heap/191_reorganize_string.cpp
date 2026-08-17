/*
 * 191. Reorganize String
 * Topic: Heap | Difficulty: Medium
 *
 * Rearrange a string so no two adjacent characters are equal, or report that it
 * is impossible.
 *
 * Approach: greedily place the most frequent remaining character that differs
 * from the last one placed, using a max-heap on counts. Holding the previous
 * character aside for one round is what guarantees it is never placed twice in a
 * row. It is impossible exactly when some character exceeds (n+1)/2 occurrences.
 *
 * Time: O(n log 26) = O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

string reorganizeString(const string& s) {
    vector<int> count(26, 0);
    for (char c : s) ++count[c - 'a'];

    priority_queue<pair<int, char> > heap;                // (count, letter)
    for (int i = 0; i < 26; ++i)
        if (count[i]) heap.push(make_pair(count[i], char('a' + i)));

    string out;
    pair<int, char> held = make_pair(0, ' ');             // cooling down one round
    while (!heap.empty()) {
        pair<int, char> cur = heap.top();
        heap.pop();
        out += cur.second;
        if (held.first > 0) heap.push(held);
        held = make_pair(cur.first - 1, cur.second);
    }
    return out.size() == s.size() ? out : "";
}

int main() {
    cout << reorganizeString("aab") << "\n";        // aba
    cout << "[" << reorganizeString("aaab") << "]\n";   // [] (impossible)
    return 0;
}
