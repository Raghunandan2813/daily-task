/*
 * 087. Implement Queue using Stacks
 * Topic: Stack & Queue | Difficulty: Easy
 *
 * Build a FIFO queue backed only by LIFO stacks.
 *
 * Approach: two stacks. Pushes always go to `in`. A pop or peek drains `in` into
 * `out` only when `out` is empty, which reverses the order. Each element moves
 * between the stacks at most once, so the amortised cost is O(1).
 *
 * Time: O(1) amortised per operation   Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> in, out;
    void shift() {
        if (out.empty())
            while (!in.empty()) { out.push(in.top()); in.pop(); }
    }
public:
    void push(int x) { in.push(x); }
    int pop() { shift(); int v = out.top(); out.pop(); return v; }
    int peek() { shift(); return out.top(); }
    bool empty() const { return in.empty() && out.empty(); }
};

int main() {
    MyQueue q;
    q.push(1); q.push(2);
    cout << q.peek() << "\n";    // 1
    cout << q.pop() << "\n";     // 1
    cout << q.empty() << "\n";   // 0
    return 0;
}
