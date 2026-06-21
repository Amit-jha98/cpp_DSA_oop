// 85. Fizz Buzz
// For each number 1..n: "FizzBuzz" if divisible by 15, "Fizz" by 3,
// "Buzz" by 5, otherwise the number itself.
// Theory / Approach:
// Iterate from 1 to n and apply divisibility rules: multiples of 3 become Fizz,
// multiples of 5 become Buzz, and multiples of both become FizzBuzz.
//
// Why this works:
// Divisibility by 15 captures numbers divisible by both 3 and 5, so checking it
// first handles the combined case.
//
// Time Complexity: O(n)
// Space Complexity: O(1) extra space, excluding the output.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) res.push_back("FizzBuzz");
            else if (i % 3 == 0) res.push_back("Fizz");
            else if (i % 5 == 0) res.push_back("Buzz");
            else res.push_back(to_string(i));
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto res = sol.fizzBuzz(15);
    for (auto& s : res) cout << s << " ";
    cout << endl;
    return 0;
}
