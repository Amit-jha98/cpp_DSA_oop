// 79. Largest Number
// Arrange a list of non-negative integers to form the largest number.
// Theory / Approach:
// Convert numbers to strings and sort by which concatenation is larger: a+b or
// b+a. Join the sorted strings.
//
// Why this works:
// For any two numbers, the better relative order is the one that creates the
// larger combined prefix. Sorting with that rule maximizes the whole number.
//
// Time Complexity: O(n log n * k)
// Space Complexity: O(nk)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int n : nums) strs.push_back(to_string(n));
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if (strs[0] == "0") return "0"; // all zeros
        string res;
        for (auto& s : strs) res += s;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10,2};
    cout << "Input: [10,2] -> " << sol.largestNumber(nums) << endl;
    vector<int> nums2 = {3,30,34,5,9};
    cout << "Input: [3,30,34,5,9] -> " << sol.largestNumber(nums2) << endl;
    vector<int> nums3 = {0,0};
    cout << "Input: [0,0] -> " << sol.largestNumber(nums3) << endl;
    return 0;
}
