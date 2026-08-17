/*
 * 190. Connect Ropes with Minimum Cost
 * Topic: Heap | Difficulty: Medium
 *
 * Joining two ropes costs the sum of their lengths. Connect all ropes into one
 * at minimum total cost.
 *
 * Approach: greedily join the two shortest ropes each time, using a min-heap.
 * The intuition is that a rope joined early gets counted in every later sum, so
 * the shortest ropes should be the ones absorbed most often. This is exactly the
 * Huffman coding construction.
 *
 * Time: O(n log n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

long long minCostToConnect(const vector<int>& ropes) {
    priority_queue<long long, vector<long long>, greater<long long> > heap
        (ropes.begin(), ropes.end());
    long long total = 0;
    while (heap.size() > 1) {
        long long a = heap.top(); heap.pop();
        long long b = heap.top(); heap.pop();
        total += a + b;
        heap.push(a + b);
    }
    return total;
}

int main() {
    cout << minCostToConnect({4, 3, 2, 6}) << "\n";      // 29
    cout << minCostToConnect({1, 2, 3, 4, 5}) << "\n";   // 33
    return 0;
}
