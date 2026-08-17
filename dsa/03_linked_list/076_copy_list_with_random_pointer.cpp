/*
 * 076. Copy List with Random Pointer
 * Topic: Linked List | Difficulty: Medium
 *
 * Deep-copy a list where each node also has a random pointer to any node (or
 * null), using O(1) extra space.
 *
 * Approach: interleave. First weave a copy of each node directly after its
 * original, so copy->random is simply original->random->next. Then unweave the
 * two lists apart.
 *
 * Time: O(n)   Space: O(1) extra
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int v) : val(v), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    for (Node* p = head; p; ) {                  // 1. weave copies in
        Node* copy = new Node(p->val);
        copy->next = p->next;
        p->next = copy;
        p = copy->next;
    }
    for (Node* p = head; p; p = p->next->next)   // 2. wire up random pointers
        p->next->random = p->random ? p->random->next : nullptr;

    Node* newHead = head->next;                  // 3. separate the two lists
    for (Node* p = head; p; ) {
        Node* copy = p->next;
        p->next = copy->next;
        copy->next = p->next ? p->next->next : nullptr;
        p = p->next;
    }
    return newHead;
}

int main() {
    Node* a = new Node(7);
    Node* b = new Node(13);
    Node* c = new Node(11);
    a->next = b; b->next = c;
    b->random = a; c->random = a;

    for (Node* p = copyRandomList(a); p; p = p->next)
        cout << p->val << "(" << (p->random ? p->random->val : -1) << ") ";
    cout << "\n";   // 7(-1) 13(7) 11(7)
    return 0;
}
