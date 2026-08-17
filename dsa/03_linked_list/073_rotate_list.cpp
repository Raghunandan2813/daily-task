/*
 * 073. Rotate List
 * Topic: Linked List | Difficulty: Medium
 *
 * Rotate the list to the right by k places.
 *
 * Approach: measure the length while walking to the tail, close the list into a
 * ring, then break it open again at the new tail, which sits
 * (length - k % length) steps from the head.
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

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    int len = 1;
    ListNode* tail = head;
    while (tail->next) { tail = tail->next; ++len; }
    k %= len;
    if (k == 0) return head;
    tail->next = head;                          // make it circular
    ListNode* newTail = head;
    for (int i = 1; i < len - k; ++i) newTail = newTail->next;
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    ListNode* h = rotateRight(build({1, 2, 3, 4, 5}), 2);
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 4 5 1 2 3
    return 0;
}
