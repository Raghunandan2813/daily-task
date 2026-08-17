/*
 * 253. Best Time to Buy and Sell Stock with Cooldown
 * Topic: Dynamic Programming | Difficulty: Medium
 *
 * Unlimited transactions, but after selling you must sit out one day before
 * buying again.
 *
 * Approach: a three-state machine per day - holding a stock, just sold (in
 * cooldown), or free to buy. Buying is only allowed from the `rest` state, which
 * is what encodes the one-day cooldown; `rest` in turn absorbs yesterday's sale.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int hold = INT_MIN, sold = 0, rest = 0;
    for (int p : prices) {
        int prevSold = sold;
        sold = hold + p;                             // sell today
        hold = max(hold, rest - p);                  // buy only from rest
        rest = max(rest, prevSold);                  // cooldown finishes
    }
    return max(sold, rest);
}

int main() {
    cout << maxProfit({1, 2, 3, 0, 2}) << "\n";   // 3
    cout << maxProfit({1}) << "\n";               // 0
    return 0;
}
