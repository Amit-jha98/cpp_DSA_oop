// 63. Middle of the Linked List
// Return the middle node of the linked list (second middle if even length).
// Theory / Approach:
// Use slow and fast pointers. Slow moves one step while fast moves two; when
// fast reaches the end, slow is at the middle.
//
// Why this works:
// Fast travels twice as far as slow, so slow has covered half the list when fast
// finishes.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    cout << "Middle of [1,2,3,4,5]: "; printList(sol.middleNode(head));

    ListNode* head2 = buildList({1,2,3,4,5,6});
    cout << "Middle of [1,2,3,4,5,6]: "; printList(sol.middleNode(head2));
    return 0;
}
