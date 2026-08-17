/*
 * 088. Implement Stack using Queues
 * Topic: Stack & Queue | Difficulty: Easy
 *
 * Build a LIFO stack backed only by FIFO queues.
 *
 * Approach: single queue, costly push. After enqueuing a new element, rotate the
 * queue by moving the preceding n-1 elements to the back, which leaves the newest
 * element at the front where pop can reach it.
 *
 * Time: O(n) push, O(1) pop/top   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 1; i < (int)q.size(); ++i) { q.push(q.front()); q.pop(); }
    }
    int pop() { int v = q.front(); q.pop(); return v; }
    int top() const { return q.front(); }
    bool empty() const { return q.empty(); }
};

int main() {
    MyStack st;
    st.push(1); st.push(2); st.push(3);
    cout << st.top() << "\n";    // 3
    cout << st.pop() << "\n";    // 3
    cout << st.pop() << "\n";    // 2
    cout << st.empty() << "\n";  // 0
    return 0;
}
