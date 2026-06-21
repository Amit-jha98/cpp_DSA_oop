// 102. Max Stack
// Design a stack supporting push, pop, top, peekMax, and popMax in
// O(log n) time using two ordered multisets.
// Theory / Approach:
// Keep push order in a vector and value order in an ordered set. The set gives
// the current maximum, while the vector gives normal stack top behavior.
//
// Why this works:
// Each pushed value gets a unique id, so duplicates are distinguishable. popMax
// removes the largest (value, id) from the set, then removes the matching entry
// from the stack vector.
//
// Time Complexity: O(log n) for push/pop/peekMax, O(n) for popMax in this implementation
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class MaxStack {
public:
    MaxStack() {}

    void push(int x) {
        int id = nextId++;
        stackData.push_back({id, x});
        sortedByVal.insert({x, id});
    }

    int pop() {
        auto [id, val] = stackData.back();
        stackData.pop_back();
        sortedByVal.erase({val, id});
        return val;
    }

    int top() {
        return stackData.back().second;
    }

    int peekMax() {
        return sortedByVal.rbegin()->first;
    }

    int popMax() {
        auto it = prev(sortedByVal.end());
        int val = it->first, id = it->second;
        sortedByVal.erase(it);
        // remove from stackData
        for (auto sit = stackData.begin(); sit != stackData.end(); ++sit) {
            if (sit->first == id) { stackData.erase(sit); break; }
        }
        return val;
    }

private:
    int nextId = 0;
    vector<pair<int,int>> stackData; // (id, value), in push order
    set<pair<int,int>> sortedByVal;  // (value, id), sorted ascending
};

int main() {
    MaxStack ms;
    ms.push(5);
    ms.push(1);
    ms.push(5);
    cout << "top() -> " << ms.top() << endl;       // 5
    cout << "popMax() -> " << ms.popMax() << endl;  // 5 (the top one)
    cout << "top() -> " << ms.top() << endl;       // 1
    cout << "peekMax() -> " << ms.peekMax() << endl; // 5
    cout << "pop() -> " << ms.pop() << endl;        // 1
    cout << "top() -> " << ms.top() << endl;        // 5
    return 0;
}
