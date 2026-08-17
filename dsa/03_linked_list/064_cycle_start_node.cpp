/*
 * 064. Find the Node Where the Cycle Begins
 * Topic: Linked List | Difficulty: Medium
 *
 * Return the node where the cycle starts, or null if the list is acyclic.
 *
 * Approach: after the tortoise and hare meet, reset one pointer to the head and
 * advance both one step at a time. The distance from the head to the cycle entry
 * equals the distance from the meeting point to the entry, so they meet there.
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

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) { slow = slow->next; fast = fast->next; }
            return slow;
        }
    }
    return nullptr;
}

int main() {
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(0);
    ListNode* d = new ListNode(-4);
    a->next = b; b->next = c; c->next = d; d->next = b;
    cout << detectCycle(a)->val << "\n";   // 2
    return 0;
}
