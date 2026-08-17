/*
 * 071. Remove Duplicates from Sorted List II
 * Topic: Linked List | Difficulty: Medium
 *
 * Delete every node that has a duplicate, leaving only values that appeared
 * exactly once.
 *
 * Approach: a dummy head handles deletions at the front. `prev` trails the last
 * kept node; whenever a run of equal values is longer than one, skip the whole
 * run by relinking prev past it.
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

ListNode* deleteDuplicatesII(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* cur = head;
    while (cur) {
        if (cur->next && cur->val == cur->next->val) {
            int dup = cur->val;
            while (cur && cur->val == dup) cur = cur->next;
            prev->next = cur;                  // skip the entire run
        } else {
            prev = cur;
            cur = cur->next;
        }
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
    ListNode* h = deleteDuplicatesII(build({1, 2, 3, 3, 4, 4, 5}));
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 1 2 5
    return 0;
}
