// 41. Alien Dictionary (LeetCode Premium)
// Given a list of words sorted lexicographically by alien language rules,
// derive the order of letters. Returns "" if no valid order exists.
// Theory / Approach:
// Compare adjacent sorted words to discover the first differing character; that
// gives a directed ordering edge. Then topologically sort the character graph.
//
// Why this works:
// Only the first difference between adjacent words determines dictionary order.
// A valid alphabet order is any topological ordering of those constraints.
//
// Time Complexity: O(total characters + V + E)
// Space Complexity: O(V + E)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indeg;
        for (auto& w : words) for (char c : w) indeg[c] = 0;

        for (int i = 0; i + 1 < (int)words.size(); ++i) {
            string& a = words[i];
            string& b = words[i+1];
            int minLen = min(a.size(), b.size());
            bool found = false;
            for (int j = 0; j < minLen; ++j) {
                if (a[j] != b[j]) {
                    if (!adj[a[j]].count(b[j])) {
                        adj[a[j]].insert(b[j]);
                        indeg[b[j]]++;
                    }
                    found = true;
                    break;
                }
            }
            // Invalid case: prefix appears after the longer word, e.g. "abc" before "ab"
            if (!found && a.size() > b.size()) return "";
        }

        queue<char> q;
        for (auto& [c, d] : indeg) if (d == 0) q.push(c);
        string res;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            res.push_back(c);
            for (char nxt : adj[c]) {
                if (--indeg[nxt] == 0) q.push(nxt);
            }
        }
        if (res.size() != indeg.size()) return "";
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"wrt","wrf","er","ett","rftt"};
    cout << "Words: [wrt,wrf,er,ett,rftt]\n";
    cout << "Alien Order: " << sol.alienOrder(words) << endl;

    vector<string> words2 = {"z","x","z"};
    cout << "Words: [z,x,z]\n";
    cout << "Alien Order: \"" << sol.alienOrder(words2) << "\" (empty = invalid)" << endl;
    return 0;
}
