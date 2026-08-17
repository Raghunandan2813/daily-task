/*
 * 074. Reverse Nodes in k-Group
 * Topic: Linked List | Difficulty: Hard
 *
 * Reverse the list k nodes at a time. A trailing group shorter than k is left
 * untouched.
 *
 * Approach: for each group, first confirm k nodes are available by probing
 * ahead. If so reverse exactly k links, then reconnect the reversed block
 * between the previous group tail and the rest of the list.
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

ListNode* reverseKGroup(ListNode* head, int k) {
    if (k <= 1) return head;
    ListNode dummy(0);
    dummy.next = head;
    ListNode* groupPrev = &dummy;
    while (true) {
        ListNode* probe = groupPrev;
        for (int i = 0; i < k && probe; ++i) probe = probe->next;
        if (!probe) break;                       // fewer than k nodes remain

        ListNode* prev = probe->next;            // node just after this group
        ListNode* cur = groupPrev->next;
        ListNode* groupTail = cur;               // becomes the tail once reversed
        for (int i = 0; i < k; ++i) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        groupPrev->next = prev;
        groupPrev = groupTail;
    }
    return dummy.next;
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    ListNode* h = reverseKGroup(build({1, 2, 3, 4, 5}), 2);
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 2 1 4 3 5
    ListNode* g = reverseKGroup(build({1, 2, 3, 4, 5}), 3);
    for (; g; g = g->next) cout << g->val << " ";
    cout << "\n";   // 3 2 1 4 5
    return 0;
}
