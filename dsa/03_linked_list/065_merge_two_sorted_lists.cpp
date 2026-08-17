/*
 * 065. Merge Two Sorted Lists
 * Topic: Linked List | Difficulty: Easy
 *
 * Splice two sorted lists into one sorted list, reusing the existing nodes.
 *
 * Approach: a dummy head removes the special case for the first node. Repeatedly
 * append whichever list currently exposes the smaller value, then attach the
 * remaining tail.
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

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (a && b) {
        if (a->val <= b->val) { tail->next = a; a = a->next; }
        else { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    ListNode* h = mergeTwoLists(build({1, 2, 4}), build({1, 3, 4}));
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 1 1 2 3 4 4
    return 0;
}
