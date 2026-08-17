/*
 * 002. Best Time to Buy and Sell Stock
 * Topic: Arrays | Difficulty: Easy
 *
 * prices[i] is the price of a stock on day i. Choose one day to buy and a later
 * day to sell to maximise profit. Return 0 if no profit is possible.
 *
 * Approach: sweep left to right keeping the minimum price seen so far; the best
 * profit ending at day i is prices[i] - minSoFar.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int best = 0, minSoFar = INT_MAX;
    for (int p : prices) {
        minSoFar = min(minSoFar, p);
        best = max(best, p - minSoFar);
    }
    return best;
}

int main() {
    cout << maxProfit({7, 1, 5, 3, 6, 4}) << "\n";   // 5
    cout << maxProfit({7, 6, 4, 3, 1}) << "\n";      // 0
    return 0;
}
