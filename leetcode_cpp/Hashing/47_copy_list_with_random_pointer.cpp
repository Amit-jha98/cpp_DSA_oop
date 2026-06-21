// 47. Copy List with Random Pointer
// Deep copy a linked list where each node has a 'next' and a 'random'
// pointer that could point to any node in the list or null.
// Theory / Approach:
// Use a hash map from original node to copied node. First create all copied
// nodes, then wire each copy's next and random pointers through the map.
//
// Why this works:
// Random pointers may point anywhere, so the map gives direct access to the copy
// corresponding to any original node.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mapping;
        for (Node* cur = head; cur; cur = cur->next) {
            mapping[cur] = new Node(cur->val);
        }
        for (Node* cur = head; cur; cur = cur->next) {
            mapping[cur]->next = mapping[cur->next];
            mapping[cur]->random = mapping[cur->random];
        }
        return mapping[head];
    }
};

int main() {
    // Build: 1 -> 2 -> 3, with random pointers: 1->3, 2->1, 3->2
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2; n2->next = n3;
    n1->random = n3; n2->random = n1; n3->random = n2;

    Solution sol;
    Node* copy = sol.copyRandomList(n1);

    cout << "Copied list values: ";
    for (Node* cur = copy; cur; cur = cur->next) cout << cur->val << " ";
    cout << "\nCopied list random pointers (values): ";
    for (Node* cur = copy; cur; cur = cur->next) cout << (cur->random ? cur->random->val : -1) << " ";
    cout << "\nDistinct nodes from original: " << (copy != n1) << endl;
    return 0;
}
