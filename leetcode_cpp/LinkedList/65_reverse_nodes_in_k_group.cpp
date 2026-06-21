// 65. Reverse Nodes in k-Group
// Reverse nodes of a linked list k at a time. If the number of remaining
// nodes is fewer than k, leave them as is.
// Theory / Approach:
// Process the list in groups of k. Before reversing, confirm that a full group
// exists; then reverse exactly k links and connect the group back.
//
// Why this works:
// Each complete block is independent after its boundaries are known. Incomplete
// trailing blocks are left unchanged.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        int count = 0;
        while (node && count < k) { node = node->next; ++count; }
        if (count < k) return head; // fewer than k nodes left, don't reverse

        ListNode* prev = reverseKGroup(node, k); // recursively process the rest
        ListNode* cur = head;
        for (int i = 0; i < k; ++i) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
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
    cout << "Original: "; printList(head);
    ListNode* res = sol.reverseKGroup(head, 2);
    cout << "Reversed in groups of 2: "; printList(res);
    return 0;
}
