// 73. LRU Cache
// Design a data structure for a Least Recently Used cache, supporting
// get and put in O(1) time, using a hash map + doubly linked list.
// Theory / Approach:
// Combine a hash map with a doubly linked list. The map gives O(1) access to
// nodes, and the list keeps most recently used items at the front.
//
// Why this works:
// On get/put, moving a node to the front updates recency. When capacity is
// exceeded, the tail is the least recently used item to evict.
//
// Time Complexity: O(1) per get/put
// Space Complexity: O(capacity)
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        // Move to front (most recently used)
        order.splice(order.begin(), order, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            it->second->second = value;
            order.splice(order.begin(), order, it->second);
            return;
        }
        if ((int)order.size() == cap) {
            auto last = order.back();
            mp.erase(last.first);
            order.pop_back();
        }
        order.emplace_front(key, value);
        mp[key] = order.begin();
    }

private:
    int cap;
    list<pair<int,int>> order; // front = most recently used
    unordered_map<int, list<pair<int,int>>::iterator> mp;
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << "get(1) = " << cache.get(1) << endl;   // 1
    cache.put(3, 3); // evicts key 2
    cout << "get(2) = " << cache.get(2) << endl;   // -1
    cache.put(4, 4); // evicts key 1
    cout << "get(1) = " << cache.get(1) << endl;   // -1
    cout << "get(3) = " << cache.get(3) << endl;   // 3
    cout << "get(4) = " << cache.get(4) << endl;   // 4
    return 0;
}
