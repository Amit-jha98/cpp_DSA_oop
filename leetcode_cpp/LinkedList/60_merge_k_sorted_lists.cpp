// 60. Merge K Sorted Lists
// Merge k sorted linked lists into one sorted list, using a min-heap.
// Theory / Approach:
// Use a min-heap containing the current head of each list. Repeatedly pop the
// smallest node and push its next node.
//
// Why this works:
// Among sorted lists, the global next smallest node must be one of the current
// list heads. The heap finds it efficiently.
//
// Time Complexity: O(N log k)
// Space Complexity: O(k)
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (ListNode* l : lists) if (l) pq.push(l);

        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};

ListNode* buildList(vector<int> vals) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int v : vals) { cur->next = new ListNode(v); cur = cur->next; }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) { cout << head->val; if (head->next) cout << " -> "; head = head->next; }
    cout << endl;
}

int main() {
    Solution sol;
    vector<ListNode*> lists = {buildList({1,4,5}), buildList({1,3,4}), buildList({2,6})};
    ListNode* merged = sol.mergeKLists(lists);
    cout << "Merged: "; printList(merged);
    return 0;
}
