/*
 * 068. Intersection of Two Linked Lists
 * Topic: Linked List | Difficulty: Easy
 *
 * Return the node where two singly linked lists merge, or null if they never do.
 *
 * Approach: two pointers that switch lists on reaching the end. Each pointer
 * then travels lenA + lenB steps in total, so they arrive at the junction
 * simultaneously (or at null together).
 *
 * Time: O(n + m)   Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* a, ListNode* b) {
    if (!a || !b) return nullptr;
    ListNode* p = a;
    ListNode* q = b;
    while (p != q) {
        p = p ? p->next : b;
        q = q ? q->next : a;
    }
    return p;
}

int main() {
    ListNode* shared = new ListNode(8);
    shared->next = new ListNode(4);

    ListNode* a = new ListNode(4);
    a->next = new ListNode(1);
    a->next->next = shared;

    ListNode* b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = shared;

    ListNode* hit = getIntersectionNode(a, b);
    cout << (hit ? hit->val : -1) << "\n";   // 8
    return 0;
}
