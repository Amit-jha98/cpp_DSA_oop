// 59. Merge Two Sorted Lists
// Merge two sorted linked lists into one sorted list.
// Theory / Approach:
// Use a dummy head and repeatedly append the smaller current node from the two
// sorted lists. Attach the leftover list at the end.
//
// Why this works:
// The smallest remaining value must be at the head of one of the lists, so the
// greedy choice preserves sorted order.
//
// Time Complexity: O(m + n)
// Space Complexity: O(1) extra space.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) { cur->next = l1; l1 = l1->next; }
            else { cur->next = l2; l2 = l2->next; }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
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
    ListNode* l1 = buildList({1,2,4});
    ListNode* l2 = buildList({1,3,4});
    ListNode* merged = sol.mergeTwoLists(l1, l2);
    cout << "Merged: "; printList(merged);
    return 0;
}
