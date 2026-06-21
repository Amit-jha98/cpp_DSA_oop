// 98. Min Stack
// Design a stack that supports push, pop, top, and retrieving the
// minimum element in O(1) time.
// Theory / Approach:
// Keep a normal value stack and a second stack of minimum values so far. On pop,
// remove from the min stack when the popped value is the current minimum.
//
// Why this works:
// The min stack mirrors the history of minima, so the current minimum is always
// available in O(1).
//
// Time Complexity: O(1) per operation
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
        else minSt.push(minSt.top());
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }

private:
    stack<int> st;
    stack<int> minSt;
};

int main() {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << "getMin() -> " << ms.getMin() << endl; // -3
    ms.pop();
    cout << "top() -> " << ms.top() << endl;       // 0
    cout << "getMin() -> " << ms.getMin() << endl; // -2
    return 0;
}
