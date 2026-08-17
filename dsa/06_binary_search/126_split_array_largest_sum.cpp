/*
 * 126. Split Array Largest Sum
 * Topic: Binary Search | Difficulty: Hard
 *
 * Split an array into k non-empty contiguous parts so that the largest part sum
 * is as small as possible.
 *
 * Approach: binary search on the answer. For a candidate cap, greedily start a
 * new part whenever adding the next element would exceed it; the number of parts
 * that produces is monotone in the cap, so the smallest feasible cap is the
 * answer.
 *
 * Time: O(n log(total sum))   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

static int partsNeeded(const vector<int>& a, long long cap) {
    int parts = 1;
    long long sum = 0;
    for (int x : a) {
        if (sum + x > cap) { ++parts; sum = 0; }
        sum += x;
    }
    return parts;
}

int splitArray(const vector<int>& a, int k) {
    long long lo = *max_element(a.begin(), a.end());
    long long hi = accumulate(a.begin(), a.end(), 0LL);
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (partsNeeded(a, mid) <= k) hi = mid;
        else lo = mid + 1;
    }
    return (int)lo;
}

int main() {
    cout << splitArray({7, 2, 5, 10, 8}, 2) << "\n";   // 18
    cout << splitArray({1, 2, 3, 4, 5}, 2) << "\n";    // 9
    return 0;
}
