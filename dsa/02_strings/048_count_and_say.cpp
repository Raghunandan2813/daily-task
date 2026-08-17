/*
 * 048. Count and Say
 * Topic: Strings | Difficulty: Medium
 *
 * The sequence starts at "1"; each term describes the previous one by reading
 * off its runs, e.g. "1211" is read as "one 1, one 2, two 1s" -> "111221".
 *
 * Approach: iterate n-1 times, each time doing a run-length pass over the
 * current term to build the next one.
 *
 * Time: O(n * length of result)   Space: O(length of result)
 */
#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    string cur = "1";
    for (int t = 1; t < n; ++t) {
        string next;
        for (int i = 0; i < (int)cur.size(); ) {
            int j = i;
            while (j < (int)cur.size() && cur[j] == cur[i]) ++j;
            next += to_string(j - i);
            next += cur[i];
            i = j;
        }
        cur = next;
    }
    return cur;
}

int main() {
    for (int i = 1; i <= 5; ++i) cout << countAndSay(i) << "\n";
    // 1 / 11 / 21 / 1211 / 111221
    return 0;
}
