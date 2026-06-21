// 57. Reverse a Linked List
// Reverse a singly linked list, iteratively.
// Theory / Approach:
// Iterate through the list while keeping previous, current, and next pointers.
// Redirect current->next to previous, then advance all pointers.
//
// Why this works:
// Reversing each link once changes the direction of the entire chain. The
// previous pointer becomes the new head at the end.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
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
    ListNode* reversed = sol.reverseList(head);
    cout << "Reversed: "; printList(reversed);
    return 0;
}
