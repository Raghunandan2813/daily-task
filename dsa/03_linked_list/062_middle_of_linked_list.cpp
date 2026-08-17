/*
 * 062. Middle of the Linked List
 * Topic: Linked List | Difficulty: Easy
 *
 * Return the middle node; for an even-length list return the second middle.
 *
 * Approach: slow and fast pointers. The fast pointer advances two steps per one
 * step of the slow pointer, so when it runs off the end the slow pointer sits at
 * the middle.
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

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    cout << middleNode(build({1, 2, 3, 4, 5}))->val << "\n";      // 3
    cout << middleNode(build({1, 2, 3, 4, 5, 6}))->val << "\n";   // 4
    return 0;
}
