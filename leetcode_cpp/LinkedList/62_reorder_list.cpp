// 62. Reorder List
// Reorder list L0->L1->...->Ln-1->Ln to L0->Ln->L1->Ln-1->L2->Ln-2->...
// Theory / Approach:
// Find the middle, reverse the second half, then merge the first half and
// reversed second half alternately.
//
// Why this works:
// The desired order takes nodes from the front, then back, then front, then back.
// Reversing the second half makes the back nodes available in forward order.
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse second half
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while (second) {
            ListNode* nxt = second->next;
            second->next = prev;
            prev = second;
            second = nxt;
        }
        // Merge two halves
        ListNode* first = head;
        second = prev;
        while (second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
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
    sol.reorderList(head);
    cout << "Reordered: "; printList(head);
    return 0;
}
