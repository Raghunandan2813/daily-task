/*
 * 259. Fractional Knapsack
 * Topic: Greedy | Difficulty: Medium
 *
 * Maximise value within a weight capacity, where items may be broken into
 * fractions.
 *
 * Approach: sort by value-to-weight ratio and take the densest items first,
 * splitting the last one to fill the remaining capacity exactly. Allowing
 * fractions is what makes greedy optimal here - the 0/1 version needs DP,
 * because a partial item cannot patch up the leftover space.
 *
 * Time: O(n log n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

struct Item { int weight, value; };

double fractionalKnapsack(vector<Item> items, int capacity) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });
    double total = 0;
    for (const Item& it : items) {
        if (capacity == 0) break;
        if (it.weight <= capacity) { total += it.value; capacity -= it.weight; }
        else { total += (double)it.value * capacity / it.weight; capacity = 0; }
    }
    return total;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    cout << fractionalKnapsack(items, 50) << "\n";   // 240
    return 0;
}
