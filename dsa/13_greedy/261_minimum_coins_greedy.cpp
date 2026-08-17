/*
 * 261. Minimum Coins (Canonical Denominations)
 * Topic: Greedy | Difficulty: Easy
 *
 * Make an amount with the fewest notes and coins from a canonical currency
 * system.
 *
 * Approach: repeatedly take the largest denomination that still fits. This is
 * optimal only because the system is canonical (each denomination is at least
 * twice the previous, roughly speaking). For an arbitrary coin set greedy fails
 * and DP is required - see Coin Change.
 *
 * Time: O(n + answer)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> minCoins(int amount) {
    const int denom[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    vector<int> used;
    for (int d : denom)
        while (amount >= d) { used.push_back(d); amount -= d; }
    return used;
}

int main() {
    vector<int> r = minCoins(2093);
    for (int c : r) cout << c << " ";
    cout << "\n";                       // 2000 50 20 20 2 1
    cout << "count: " << r.size() << "\n";   // 6
    return 0;
}
