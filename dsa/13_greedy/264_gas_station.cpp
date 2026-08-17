/*
 * 264. Gas Station
 * Topic: Greedy | Difficulty: Medium
 *
 * Find the starting station from which a circular tour can be completed, or -1.
 *
 * Approach: two observations collapse this to one pass. If the total gas is less
 * than the total cost, no start works. Otherwise, whenever the running tank goes
 * negative at station i, no station in the segment just traversed can be a valid
 * start, so restart the candidate at i+1 - and by the first observation, the
 * final candidate must succeed.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < (int)gas.size(); ++i) {
        int gain = gas[i] - cost[i];
        total += gain;
        tank += gain;
        if (tank < 0) { start = i + 1; tank = 0; }
    }
    return total >= 0 ? start : -1;
}

int main() {
    cout << canCompleteCircuit({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}) << "\n";   // 3
    cout << canCompleteCircuit({2, 3, 4}, {3, 4, 3}) << "\n";               // -1
    return 0;
}
