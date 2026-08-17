/*
 * 066. Remove Nth Node From End of List
 * Topic: Linked List | Difficulty: Medium
 *
 * Delete the nth node counting from the end and return the head.
 *
 * Approach: two pointers separated by n+1 steps (measured from a dummy head).
 * When the leading pointer falls off the end, the trailing one sits just before
 * the node to unlink, so a single pass suffices.
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* lead = &dummy;
    ListNode* trail = &dummy;
    for (int i = 0; i <= n; ++i) lead = lead->next;
    while (lead) { lead = lead->next; trail = trail->next; }
    ListNode* doomed = trail->next;
    trail->next = doomed->next;
    delete doomed;
    return dummy.next;
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    ListNode* h = removeNthFromEnd(build({1, 2, 3, 4, 5}), 2);
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 1 2 3 5
    return 0;
}
