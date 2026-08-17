/*
 * 252. Best Time to Buy and Sell Stock III
 * Topic: Dynamic Programming | Difficulty: Hard
 *
 * Maximise profit with at most two transactions (buy then sell, no overlap).
 *
 * Approach: track four running states in one pass - the best balance after the
 * first buy, first sell, second buy and second sell. Each state is built from
 * the previous one, so the whole two-transaction problem collapses to four
 * variables instead of a table.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
    for (int p : prices) {
        buy1  = max(buy1, -p);                       // spent p
        sell1 = max(sell1, buy1 + p);                // closed transaction 1
        buy2  = max(buy2, sell1 - p);                // reinvested
        sell2 = max(sell2, buy2 + p);                // closed transaction 2
    }
    return sell2;
}

int main() {
    cout << maxProfit({3, 3, 5, 0, 0, 3, 1, 4}) << "\n";   // 6
    cout << maxProfit({1, 2, 3, 4, 5}) << "\n";            // 4
    cout << maxProfit({7, 6, 4, 3, 1}) << "\n";            // 0
    return 0;
}
