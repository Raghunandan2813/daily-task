/*
 * 075. Sort List (Merge Sort on a Linked List)
 * Topic: Linked List | Difficulty: Medium
 *
 * Sort a linked list in O(n log n) time with constant extra space beyond the
 * recursion stack.
 *
 * Approach: merge sort suits linked lists because splitting is O(1) once the
 * middle is known and merging needs no auxiliary array. Split with slow/fast
 * pointers, sort both halves, then merge.
 *
 * Time: O(n log n)   Space: O(log n) recursion
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

static ListNode* mergeTwo(ListNode* a, ListNode* b) {
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

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    ListNode* second = slow->next;
    slow->next = nullptr;                        // cut into two halves
    return mergeTwo(sortList(head), sortList(second));
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    ListNode* h = sortList(build({4, 2, 1, 3}));
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 1 2 3 4
    return 0;
}
