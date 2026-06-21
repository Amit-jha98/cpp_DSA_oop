// 61. Remove Nth Node From End Of List
// Remove the nth node from the end of the list and return its head,
// in one pass using two pointers.
// Theory / Approach:
// Use two pointers with a gap of n nodes. Move both together until the front
// pointer reaches the end; the back pointer is before the node to remove.
//
// Why this works:
// The fixed gap converts "nth from the end" into a single forward pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        for (int i = 0; i < n; ++i) fast = fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
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
    ListNode* head = buildList({1,2,3,4,5});
    ListNode* res = sol.removeNthFromEnd(head, 2);
    cout << "Remove 2nd from end of [1,2,3,4,5]: "; printList(res);
    return 0;
}
