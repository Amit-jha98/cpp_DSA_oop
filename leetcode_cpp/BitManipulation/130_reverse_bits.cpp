// 130. Reverse Bits
// Reverse the bits of a given 32-bit unsigned integer.
// Theory / Approach:
// Build the answer bit by bit. Shift the result left, copy the lowest bit of n
// into it, then shift n right.
//
// Why this works:
// Reading bits from least significant to most significant and appending them to
// the result reverses their order.
//
// Time Complexity: O(32)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution sol;
    uint32_t n = 0b00000010100101000001111010011100;
    uint32_t res = sol.reverseBits(n);
    cout << "Input:  " << bitset<32>(n) << endl;
    cout << "Output: " << bitset<32>(res) << endl;
    cout << "Output (decimal): " << res << endl;
    return 0;
}
