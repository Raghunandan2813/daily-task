/*
 * 097. Design Circular Queue
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * Implement a fixed-capacity circular queue supporting enQueue, deQueue, Front,
 * Rear, isEmpty and isFull in O(1).
 *
 * Approach: a ring buffer with a head index and a live count. Storing the count
 * rather than a tail index removes the classic full-versus-empty ambiguity, and
 * the tail is derived as (head + count - 1) % capacity.
 *
 * Time: O(1) per operation   Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    vector<int> buf;
    int head, count;
public:
    explicit MyCircularQueue(int k) : buf(k), head(0), count(0) {}

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == (int)buf.size(); }

    bool enQueue(int value) {
        if (isFull()) return false;
        buf[(head + count) % buf.size()] = value;
        ++count;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % buf.size();
        --count;
        return true;
    }
    int Front() const { return isEmpty() ? -1 : buf[head]; }
    int Rear() const { return isEmpty() ? -1 : buf[(head + count - 1) % buf.size()]; }
};

int main() {
    MyCircularQueue q(3);
    cout << q.enQueue(1) << q.enQueue(2) << q.enQueue(3) << q.enQueue(4) << "\n"; // 1110
    cout << q.Rear() << "\n";       // 3
    cout << q.isFull() << "\n";     // 1
    q.deQueue();
    q.enQueue(4);
    cout << q.Rear() << "\n";       // 4
    cout << q.Front() << "\n";      // 2
    return 0;
}
