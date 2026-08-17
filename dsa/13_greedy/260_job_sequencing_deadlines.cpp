/*
 * 260. Job Sequencing with Deadlines
 * Topic: Greedy | Difficulty: Medium
 *
 * Each job takes one unit of time, has a deadline and a profit. Schedule jobs to
 * maximise profit; a job earns nothing if it misses its deadline.
 *
 * Approach: sort by profit descending and place each job in the *latest* free
 * slot at or before its deadline. Scheduling late keeps the early slots open for
 * jobs with tighter deadlines, which is what makes the greedy choice safe.
 *
 * Time: O(n log n + n * maxDeadline)   Space: O(maxDeadline)
 */
#include <bits/stdc++.h>
using namespace std;

struct Job { int id, deadline, profit; };

pair<int, int> jobSequencing(vector<Job> jobs) {      // (count, total profit)
    sort(jobs.begin(), jobs.end(),
         [](const Job& a, const Job& b) { return a.profit > b.profit; });
    int maxDeadline = 0;
    for (const Job& j : jobs) maxDeadline = max(maxDeadline, j.deadline);

    vector<bool> slotUsed(maxDeadline + 1, false);
    int count = 0, profit = 0;
    for (const Job& j : jobs)
        for (int slot = j.deadline; slot >= 1; --slot)   // latest free slot
            if (!slotUsed[slot]) {
                slotUsed[slot] = true;
                ++count;
                profit += j.profit;
                break;
            }
    return make_pair(count, profit);
}

int main() {
    vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    pair<int, int> r = jobSequencing(jobs);
    cout << r.first << " " << r.second << "\n";   // 2 60
    return 0;
}
