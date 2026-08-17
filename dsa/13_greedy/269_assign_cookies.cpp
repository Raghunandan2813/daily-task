/*
 * 269. Assign Cookies
 * Topic: Greedy | Difficulty: Easy
 *
 * Each child has a greed factor and each cookie a size. A child is content if
 * given a cookie at least as large as their greed. Maximise the number of
 * content children.
 *
 * Approach: sort both lists and match with two pointers, giving the smallest
 * adequate cookie to the least greedy remaining child. Spending a larger cookie
 * than necessary can only waste it, so this greedy pairing is optimal.
 *
 * Time: O(n log n + m log m)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> greed, vector<int> cookies) {
    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());
    int child = 0, cookie = 0;
    while (child < (int)greed.size() && cookie < (int)cookies.size()) {
        if (cookies[cookie] >= greed[child]) ++child;    // this child is content
        ++cookie;
    }
    return child;
}

int main() {
    cout << findContentChildren({1, 2, 3}, {1, 1}) << "\n";   // 1
    cout << findContentChildren({1, 2}, {1, 2, 3}) << "\n";   // 2
    return 0;
}
