/*
 * 079. Merge k Sorted Lists
 * Topic: Linked List | Difficulty: Hard
 *
 * Merge k sorted linked lists into one sorted list.
 *
 * Approach: a min-heap holding the current head of each list. Popping the global
 * minimum and pushing its successor keeps the heap at size <= k, so each of the
 * n nodes costs O(log k).
 *
 * Time: O(n log k)   Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

struct Greater {
    bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; }
};

ListNode* mergeKLists(const vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Greater> pq;
    for (ListNode* h : lists) if (h) pq.push(h);
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        tail->next = node;
        tail = node;
        if (node->next) pq.push(node->next);
    }
    tail->next = nullptr;
    return dummy.next;
}

static ListNode* build(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) { tail->next = new ListNode(x); tail = tail->next; }
    return dummy.next;
}

int main() {
    vector<ListNode*> lists = {build({1, 4, 5}), build({1, 3, 4}), build({2, 6})};
    for (ListNode* h = mergeKLists(lists); h; h = h->next) cout << h->val << " ";
    cout << "\n";   // 1 1 2 3 4 4 5 6
    return 0;
}
