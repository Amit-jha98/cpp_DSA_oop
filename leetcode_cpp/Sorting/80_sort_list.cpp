// 80. Sort List
// Sort a linked list in O(n log n) time using merge sort.
// Theory / Approach:
// Use merge sort on the linked list. Split with slow/fast pointers, sort each
// half recursively, then merge the two sorted halves.
//
// Why this works:
// Merge sort works well for linked lists because merging can be done by pointer
// rewiring without random access.
//
// Time Complexity: O(n log n)
// Space Complexity: O(log n) recursion stack.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = findMiddleAndSplit(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
private:
    ListNode* findMiddleAndSplit(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr; // split
        return mid;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
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
    ListNode* head = buildList({4,2,1,3});
    ListNode* sorted = sol.sortList(head);
    cout << "Sorted: "; printList(sorted);
    return 0;
}
