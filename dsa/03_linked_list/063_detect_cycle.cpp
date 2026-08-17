/*
 * 063. Linked List Cycle Detection
 * Topic: Linked List | Difficulty: Easy
 *
 * Determine whether a linked list contains a cycle.
 *
 * Approach: Floyd's tortoise and hare. If a cycle exists the fast pointer laps
 * the slow one and they must meet; otherwise the fast pointer reaches the end.
 *
 * Time: O(n)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(0);
    ListNode* d = new ListNode(-4);
    a->next = b; b->next = c; c->next = d; d->next = b;   // cycle back to b
    cout << hasCycle(a) << "\n";   // 1

    ListNode* x = new ListNode(1);
    x->next = new ListNode(2);
    cout << hasCycle(x) << "\n";   // 0
    return 0;
}
