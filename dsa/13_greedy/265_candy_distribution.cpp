/*
 * 265. Candy Distribution
 * Topic: Greedy | Difficulty: Hard
 *
 * Each child has a rating. Every child gets at least one candy, and a child with
 * a higher rating than a neighbour must get more candies than that neighbour.
 * Minimise the total.
 *
 * Approach: two sweeps. Left to right enforces the constraint against the left
 * neighbour; right to left enforces it against the right neighbour, taking the
 * maximum so the first pass is not undone. One pass alone cannot satisfy both
 * directions.
 *
 * Time: O(n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int candy(const vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);
    for (int i = 1; i < n; ++i)
        if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
    for (int i = n - 2; i >= 0; --i)
        if (ratings[i] > ratings[i + 1])
            candies[i] = max(candies[i], candies[i + 1] + 1);
    return accumulate(candies.begin(), candies.end(), 0);
}

int main() {
    cout << candy({1, 0, 2}) << "\n";   // 5
    cout << candy({1, 2, 2}) << "\n";   // 4
    return 0;
}
