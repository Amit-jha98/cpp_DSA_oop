// 126. Sum of Two Integers
// Calculate the sum of two integers without using '+' or '-', using
// bitwise operations.
// Theory / Approach:
// Add without '+' by using XOR for sum bits without carry and AND shifted left
// for carry bits. Repeat until there is no carry.
//
// Why this works:
// Binary addition separates into bitwise sum and carry. Iterating propagates
// carries until the final sum remains.
//
// Time Complexity: O(1) for fixed-width integers
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};

int main() {
    Solution sol;
    cout << "a=1, b=2 -> " << sol.getSum(1, 2) << endl;
    cout << "a=2, b=3 -> " << sol.getSum(2, 3) << endl;
    cout << "a=-2, b=3 -> " << sol.getSum(-2, 3) << endl;
    return 0;
}
