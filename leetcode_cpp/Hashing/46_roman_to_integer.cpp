// 46. Roman to Integer
// Convert a roman numeral string to an integer.
// Theory / Approach:
// Map each Roman symbol to its value. Scan left to right; if a symbol is smaller
// than the symbol after it, subtract it, otherwise add it.
//
// Why this works:
// Roman numerals use subtraction only when a smaller value appears before a
// larger one, such as IV or IX. All other symbols contribute positively.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> val = {
            {'I',1},{'V',5},{'X',10},{'L',50},
            {'C',100},{'D',500},{'M',1000}
        };
        int total = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && val[s[i]] < val[s[i+1]]) {
                total -= val[s[i]];
            } else {
                total += val[s[i]];
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    cout << "s=\"III\" -> " << sol.romanToInt("III") << endl;
    cout << "s=\"LVIII\" -> " << sol.romanToInt("LVIII") << endl;
    cout << "s=\"MCMXCIV\" -> " << sol.romanToInt("MCMXCIV") << endl;
    return 0;
}
