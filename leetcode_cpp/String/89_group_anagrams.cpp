// 89. Group Anagrams
// Group strings that are anagrams of each other.
// Theory / Approach:
// Use a canonical key for each word, commonly its sorted letters. Words with the
// same key are anagrams and belong in the same hash map bucket.
//
// Why this works:
// Sorting removes order information while preserving character multiset, which
// is exactly what defines an anagram.
//
// Time Complexity: O(n * k log k)
// Space Complexity: O(nk)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (auto& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& [key, group] : groups) res.push_back(group);
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    auto res = sol.groupAnagrams(strs);
    cout << "Groups:\n";
    for (auto& g : res) {
        cout << "[";
        for (int i = 0; i < (int)g.size(); ++i) cout << g[i] << (i+1<(int)g.size()?",":"");
        cout << "]\n";
    }
    return 0;
}
