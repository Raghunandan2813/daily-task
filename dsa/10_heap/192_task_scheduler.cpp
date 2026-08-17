/*
 * 192. Task Scheduler
 * Topic: Heap | Difficulty: Medium
 *
 * Identical tasks must be separated by at least n cooling intervals. Find the
 * least total time to run every task.
 *
 * Approach: a counting formula beats simulation here. The most frequent task
 * fixes the skeleton: (maxCount - 1) full frames of length (n + 1), plus one
 * slot for each task tied at that frequency. If there are enough distinct tasks
 * to fill every idle slot, the answer is simply the number of tasks.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int leastInterval(const vector<char>& tasks, int n) {
    vector<int> count(26, 0);
    for (char t : tasks) ++count[t - 'A'];
    int maxCount = *max_element(count.begin(), count.end());
    int tiedAtMax = count_if(count.begin(), count.end(),
                             [maxCount](int c) { return c == maxCount; });
    int skeleton = (maxCount - 1) * (n + 1) + tiedAtMax;
    return max<int>(skeleton, tasks.size());
}

int main() {
    cout << leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2) << "\n";   // 8
    cout << leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 0) << "\n";   // 6
    cout << leastInterval({'A', 'C', 'A', 'B', 'D', 'B'}, 1) << "\n";   // 6
    return 0;
}
