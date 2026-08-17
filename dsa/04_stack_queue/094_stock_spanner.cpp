/*
 * 094. Online Stock Spanner
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * For each incoming price, report the span: the number of consecutive days up to
 * today whose price was less than or equal to today's.
 *
 * Approach: a monotonic decreasing stack of (price, span) pairs. Popping every
 * entry with a price <= today's collapses those days into today's span, so each
 * day is pushed and popped at most once.
 *
 * Time: O(1) amortised per call   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
    vector<pair<int, int>> st;                    // (price, span)
public:
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.back().first <= price) {
            span += st.back().second;
            st.pop_back();
        }
        st.push_back(make_pair(price, span));
        return span;
    }
};

int main() {
    StockSpanner s;
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    for (int p : prices) cout << s.next(p) << " ";
    cout << "\n";   // 1 1 1 2 1 4 6
    return 0;
}
