/*
 * 080. Swap Nodes in Pairs
 * Topic: Linked List | Difficulty: Medium
 *
 * Swap every two adjacent nodes, changing links rather than values.
 *
 * Approach: keep a `prev` pointer (starting at a dummy head) and rewire the
 * three links involved in each swap, then advance prev two nodes.
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

ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    while (prev->next && prev->next->next) {
        ListNode* first = prev->next;
        ListNode* second = first->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
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
    ListNode* h = swapPairs(build({1, 2, 3, 4}));
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 2 1 4 3
    ListNode* g = swapPairs(build({1, 2, 3}));
    for (; g; g = g->next) cout << g->val << " ";
    cout << "\n";   // 2 1 3
    return 0;
}
