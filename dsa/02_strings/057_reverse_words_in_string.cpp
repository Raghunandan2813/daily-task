/*
 * 057. Reverse Words in a String
 * Topic: Strings | Difficulty: Medium
 *
 * Reverse the order of the words, collapsing runs of spaces and trimming the
 * leading and trailing ones.
 *
 * Approach: scan from the right, and for each word found, locate its start and
 * append the whole word to the output. This handles the spacing rules naturally
 * without any tokenising pass.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

string reverseWords(const string& s) {
    string out;
    int i = s.size() - 1;
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') --i;
        if (i < 0) break;
        int end = i;
        while (i >= 0 && s[i] != ' ') --i;
        if (!out.empty()) out += ' ';
        out += s.substr(i + 1, end - i);
    }
    return out;
}

int main() {
    cout << "[" << reverseWords("the sky is blue") << "]\n";     // [blue is sky the]
    cout << "[" << reverseWords("  hello   world  ") << "]\n";   // [world hello]
    return 0;
}
