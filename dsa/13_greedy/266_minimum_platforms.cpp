/*
 * 266. Minimum Number of Railway Platforms
 * Topic: Greedy | Difficulty: Medium
 *
 * Given train arrival and departure times, find the minimum number of platforms
 * needed so no train waits.
 *
 * Approach: sort arrivals and departures independently and sweep both with two
 * pointers, treating each as an event. An arrival before the next departure
 * needs a new platform; otherwise a platform frees up. The peak concurrent count
 * is the answer. Pairing which train uses which platform is unnecessary.
 *
 * Time: O(n log n)   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int minPlatforms(vector<int> arrival, vector<int> departure) {
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int n = arrival.size(), i = 0, j = 0, current = 0, best = 0;
    while (i < n) {
        if (arrival[i] <= departure[j]) { ++current; ++i; best = max(best, current); }
        else { --current; ++j; }
    }
    return best;
}

int main() {
    cout << minPlatforms({900, 940, 950, 1100, 1500, 1800},
                         {910, 1200, 1120, 1130, 1900, 2000}) << "\n";   // 3
    cout << minPlatforms({900, 1100, 1235}, {1000, 1200, 1240}) << "\n"; // 1
    return 0;
}
