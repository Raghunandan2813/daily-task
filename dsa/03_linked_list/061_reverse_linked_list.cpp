/*
 * 061. Reverse a Linked List
 * Topic: Linked List | Difficulty: Easy
 *
 * Reverse a singly linked list, both iteratively and recursively.
 *
 * Approach (iterative): carry three pointers - prev, cur, next - and repoint
 * each node backwards as we walk forward.
 * Approach (recursive): reverse the tail first, then make the node after us
 * point back at us and cut our own forward link.
 *
 * Time: O(n)   Space: O(1) iterative, O(n) recursive (call stack)
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* reverseIterative(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* reverseRecursive(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}
static void print(ListNode* h) {
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";
}

int main() {
    print(reverseIterative(build({1, 2, 3, 4, 5})));   // 5 4 3 2 1
    print(reverseRecursive(build({1, 2, 3})));         // 3 2 1
    return 0;
}
