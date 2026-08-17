/*
 * 070. Remove Duplicates from Sorted List
 * Topic: Linked List | Difficulty: Easy
 *
 * Delete duplicates so that each value appears only once.
 *
 * Approach: because the list is sorted, equal values are adjacent. Walk once and
 * unlink any node whose value matches its predecessor.
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

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;
    while (cur && cur->next) {
        if (cur->val == cur->next->val) {
            ListNode* doomed = cur->next;
            cur->next = doomed->next;
            delete doomed;
        } else cur = cur->next;
    }
    return head;
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    ListNode* h = deleteDuplicates(build({1, 1, 2, 3, 3}));
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 1 2 3
    return 0;
}
