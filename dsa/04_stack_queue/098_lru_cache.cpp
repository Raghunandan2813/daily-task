/*
 * 098. LRU Cache
 * Topic: Stack & Queue | Difficulty: Medium
 *
 * Design a cache with a fixed capacity that evicts the least recently used key
 * when full. get and put must both run in O(1).
 *
 * Approach: a doubly linked list keeps keys in recency order (most recent at the
 * front) and a hash map gives O(1) access to each key's list node. Every access
 * splices its node to the front; eviction removes the back.
 *
 * Time: O(1) per operation   Space: O(capacity)
 */
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int, int>> items;                                 // (key, value)
    unordered_map<int, list<pair<int, int>>::iterator> index;
public:
    explicit LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = index.find(key);
        if (it == index.end()) return -1;
        items.splice(items.begin(), items, it->second);          // mark as recent
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = index.find(key);
        if (it != index.end()) {
            it->second->second = value;
            items.splice(items.begin(), items, it->second);
            return;
        }
        if ((int)items.size() == cap) {
            index.erase(items.back().first);
            items.pop_back();
        }
        items.push_front(make_pair(key, value));
        index[key] = items.begin();
    }
};

int main() {
    LRUCache c(2);
    c.put(1, 1);
    c.put(2, 2);
    cout << c.get(1) << "\n";   // 1
    c.put(3, 3);                // evicts key 2
    cout << c.get(2) << "\n";   // -1
    c.put(4, 4);                // evicts key 1
    cout << c.get(1) << "\n";   // -1
    cout << c.get(3) << "\n";   // 3
    cout << c.get(4) << "\n";   // 4
    return 0;
}
