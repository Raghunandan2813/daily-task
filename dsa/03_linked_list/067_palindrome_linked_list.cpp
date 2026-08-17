/*
 * 067. Palindrome Linked List
 * Topic: Linked List | Difficulty: Easy
 *
 * Decide whether the values in a singly linked list form a palindrome, using
 * O(1) extra space.
 *
 * Approach: find the middle with slow/fast pointers, reverse the second half in
 * place, then walk both halves in lockstep comparing values. The list is
 * restored before returning.
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

static ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* second = reverseList(slow->next);
    ListNode* p = head;
    ListNode* q = second;
    bool ok = true;
    while (q) {
        if (p->val != q->val) { ok = false; break; }
        p = p->next;
        q = q->next;
    }
    slow->next = reverseList(second);
    return ok;
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    cout << isPalindrome(build({1, 2, 2, 1})) << "\n";   // 1
    cout << isPalindrome(build({1, 2, 3})) << "\n";      // 0
    return 0;
}
