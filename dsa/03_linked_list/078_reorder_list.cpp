/*
 * 078. Reorder List
 * Topic: Linked List | Difficulty: Medium
 *
 * Reorder L0 -> L1 -> ... -> Ln as L0 -> Ln -> L1 -> Ln-1 -> ... in place.
 *
 * Approach: three classic steps - find the middle, reverse the second half, then
 * interleave the two halves node by node.
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

void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) { slow = slow->next; fast = fast->next->next; }

    ListNode* second = slow->next;               // reverse the second half
    slow->next = nullptr;
    ListNode* prev = nullptr;
    while (second) {
        ListNode* next = second->next;
        second->next = prev;
        prev = second;
        second = next;
    }

    ListNode* first = head;                      // interleave
    second = prev;
    while (second) {
        ListNode* n1 = first->next;
        ListNode* n2 = second->next;
        first->next = second;
        second->next = n1;
        first = n1;
        second = n2;
    }
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    ListNode* h = build({1, 2, 3, 4, 5});
    reorderList(h);
    for (ListNode* p = h; p; p = p->next) cout << p->val << " ";
    cout << "\n";   // 1 5 2 4 3
    return 0;
}
