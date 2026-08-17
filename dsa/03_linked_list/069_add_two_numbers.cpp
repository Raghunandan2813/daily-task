/*
 * 069. Add Two Numbers
 * Topic: Linked List | Difficulty: Medium
 *
 * Two numbers are stored as linked lists with digits in reverse order. Return
 * their sum in the same format.
 *
 * Approach: walk both lists together adding digit + digit + carry. Reverse order
 * is convenient here because it puts the least significant digit first, which is
 * exactly where addition starts.
 *
 * Time: O(max(n, m))   Space: O(max(n, m)) for the result
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    int carry = 0;
    while (a || b || carry) {
        int sum = carry;
        if (a) { sum += a->val; a = a->next; }
        if (b) { sum += b->val; b = b->next; }
        carry = sum / 10;
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
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
    ListNode* h = addTwoNumbers(build({2, 4, 3}), build({5, 6, 4}));   // 342 + 465
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 7 0 8  (i.e. 807)
    return 0;
}
