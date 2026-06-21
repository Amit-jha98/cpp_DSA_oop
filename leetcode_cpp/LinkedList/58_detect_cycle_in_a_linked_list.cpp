// 58. Detect Cycle in a Linked List
// Determine if a linked list has a cycle (Floyd's Tortoise and Hare).
// Theory / Approach:
// Use Floyd's slow and fast pointers. Slow moves one step, fast moves two. If
// they meet, a cycle exists; if fast reaches null, there is no cycle.
//
// Why this works:
// Inside a cycle, the faster pointer gains one node per step on the slow pointer,
// so it must eventually catch up.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    // Build list 1->2->3->4 with a cycle back to node 2
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2;
    cout << boolalpha;
    cout << "List with cycle -> " << sol.hasCycle(n1) << endl;

    ListNode* m1 = new ListNode(1);
    ListNode* m2 = new ListNode(2);
    m1->next = m2;
    cout << "List without cycle -> " << sol.hasCycle(m1) << endl;
    return 0;
}
