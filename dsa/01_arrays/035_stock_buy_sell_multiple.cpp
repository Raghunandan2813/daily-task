/*
 * 035. Best Time to Buy and Sell Stock II
 * Topic: Arrays | Difficulty: Medium
 *
 * You may complete as many transactions as you like (buy then sell, never
 * holding two positions at once). Maximise total profit.
 *
 * Approach: every upward step can be banked independently, because buying at
 * day i and selling at day j telescopes into the sum of consecutive daily gains.
 * So sum every positive difference between adjacent days.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int maxProfitII(const vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < (int)prices.size(); ++i)
        profit += max(0, prices[i] - prices[i - 1]);
    return profit;
}

int main() {
    cout << maxProfitII({7, 1, 5, 3, 6, 4}) << "\n";   // 7
    cout << maxProfitII({1, 2, 3, 4, 5}) << "\n";      // 4
    cout << maxProfitII({7, 6, 4, 3, 1}) << "\n";      // 0
    return 0;
}
