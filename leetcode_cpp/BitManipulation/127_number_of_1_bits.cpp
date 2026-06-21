// 127. Number of 1 Bits
// Count the number of set bits ('1's) in the binary representation of
// an unsigned integer (Hamming weight).
// Theory / Approach:
// Repeatedly clear the lowest set bit using n & (n - 1), counting how many times
// this can be done before n becomes zero.
//
// Why this works:
// Subtracting 1 flips the lowest set bit and all bits after it; ANDing removes
// exactly that lowest set bit.
//
// Time Complexity: O(number of set bits)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1); // clear the lowest set bit
            ++count;
        }
        return count;
    }
};

int main() {
    Solution sol;
    cout << "n=00000000000000000000000000001011 -> " << sol.hammingWeight(11) << endl; // 3
    cout << "n=00000000000000000000000010000000 -> " << sol.hammingWeight(128) << endl; // 1
    return 0;
}
