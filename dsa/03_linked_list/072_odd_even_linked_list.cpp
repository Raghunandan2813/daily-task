/*
 * 072. Odd Even Linked List
 * Topic: Linked List | Difficulty: Medium
 *
 * Group nodes at odd positions before nodes at even positions, preserving the
 * relative order within each group.
 *
 * Approach: weave the list into two chains in one pass, keeping the head of the
 * even chain so the odd tail can be attached to it at the end.
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

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    ListNode* h = oddEvenList(build({1, 2, 3, 4, 5}));
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 1 3 5 2 4
    return 0;
}
