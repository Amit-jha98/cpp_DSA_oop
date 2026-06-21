// 56. Add Two Numbers
// Add two numbers represented as linked lists (digits stored in reverse order).
// Theory / Approach:
// Traverse both linked lists digit by digit, adding values with a carry. Create
// a new node for each result digit.
//
// Why this works:
// The lists store numbers in reverse order, so normal elementary addition works
// from head to tail.
//
// Time Complexity: O(max(m, n))
// Space Complexity: O(max(m, n)) for the output list.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
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
    ListNode* l1 = buildList({2,4,3}); // represents 342
    ListNode* l2 = buildList({5,6,4}); // represents 465
    ListNode* res = sol.addTwoNumbers(l1, l2);
    cout << "342 + 465 = ";
    printList(res); // expect 7 -> 0 -> 8 (807)
    return 0;
}
