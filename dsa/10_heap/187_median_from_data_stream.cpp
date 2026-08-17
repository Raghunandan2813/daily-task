/*
 * 187. Find Median from Data Stream
 * Topic: Heap | Difficulty: Hard
 *
 * Support adding numbers one at a time and querying the running median.
 *
 * Approach: two heaps splitting the data at the median. A max-heap holds the
 * lower half and a min-heap the upper half; keeping their sizes within one of
 * each other means the median is either the max-heap top or the average of both
 * tops.
 *
 * Time: O(log n) per insertion, O(1) per query   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> lower;                                    // max-heap
    priority_queue<int, vector<int>, greater<int> > upper;        // min-heap
public:
    void addNum(int num) {
        lower.push(num);
        upper.push(lower.top());                                  // funnel across
        lower.pop();
        if (upper.size() > lower.size()) {                        // rebalance
            lower.push(upper.top());
            upper.pop();
        }
    }
    double findMedian() const {
        if (lower.size() > upper.size()) return lower.top();
        return (lower.top() + upper.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << "\n";   // 1.5
    mf.addNum(3);
    cout << mf.findMedian() << "\n";   // 2
    return 0;
}
