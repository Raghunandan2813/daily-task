/*
 * 268. Lemonade Change
 * Topic: Greedy | Difficulty: Easy
 *
 * Each lemonade costs $5 and customers pay with $5, $10 or $20 bills. Starting
 * with no change, decide whether every customer can be served.
 *
 * Approach: track how many $5 and $10 bills are in hand. For a $20, prefer to
 * give one $10 plus one $5 over three $5s - $5 bills are the more flexible
 * currency, so spending them last keeps future options open.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(const vector<int>& bills) {
    int fives = 0, tens = 0;
    for (int b : bills) {
        if (b == 5) ++fives;
        else if (b == 10) {
            if (fives == 0) return false;
            --fives; ++tens;
        } else {
            if (tens > 0 && fives > 0) { --tens; --fives; }   // preferred
            else if (fives >= 3) fives -= 3;
            else return false;
        }
    }
    return true;
}

int main() {
    cout << lemonadeChange({5, 5, 5, 10, 20}) << "\n";   // 1
    cout << lemonadeChange({5, 5, 10, 10, 20}) << "\n";  // 0
    return 0;
}
