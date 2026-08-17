/*
 * 077. Partition List
 * Topic: Linked List | Difficulty: Medium
 *
 * Reorder the list so every node with value less than x comes before the nodes
 * with value >= x, preserving the original relative order in each part.
 *
 * Approach: build two separate chains behind two dummy heads while walking the
 * list once, then join the "less" chain to the "greater or equal" chain.
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

ListNode* partitionList(ListNode* head, int x) {
    ListNode lessDummy(0), geDummy(0);
    ListNode* lessTail = &lessDummy;
    ListNode* geTail = &geDummy;
    while (head) {
        if (head->val < x) { lessTail->next = head; lessTail = head; }
        else { geTail->next = head; geTail = head; }
        head = head->next;
    }
    geTail->next = nullptr;
    lessTail->next = geDummy.next;
    return lessDummy.next;
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int n : v) { tail->next = new ListNode(n); tail = tail->next; }
    return dummy.next;
}

int main() {
    ListNode* h = partitionList(build({1, 4, 3, 2, 5, 2}), 3);
    for (; h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 1 2 2 4 3 5
    return 0;
}
