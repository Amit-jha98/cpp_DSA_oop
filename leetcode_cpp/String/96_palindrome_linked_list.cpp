// 96. Palindrome Linked List
// Determine if a singly linked list is a palindrome, O(n) time, O(1) space.
// Theory / Approach:
// Find the middle of the list, reverse the second half, then compare the first
// half and reversed second half node by node.
//
// Why this works:
// A palindrome has matching values from both ends. Reversing the second half
// lets a singly linked list be compared from the middle outward in linear time.
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse second half
        ListNode* secondHalf = reverse(slow->next);
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        bool result = true;
        while (p2) {
            if (p1->val != p2->val) { result = false; break; }
            p1 = p1->next;
            p2 = p2->next;
        }
        slow->next = reverse(secondHalf); // restore list
        return result;
    }
private:
    ListNode* reverse(ListNode* head) {
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

int main() {
    Solution sol;
    cout << boolalpha;
    ListNode* l1 = buildList({1,2,2,1});
    cout << "[1,2,2,1] -> " << sol.isPalindrome(l1) << endl;
    ListNode* l2 = buildList({1,2});
    cout << "[1,2] -> " << sol.isPalindrome(l2) << endl;
    return 0;
}
