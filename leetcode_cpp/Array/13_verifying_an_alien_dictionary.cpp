// 13. Verifying an Alien Dictionary
// Given words and a custom alphabet order, determine if the words
// are sorted lexicographically according to that order.
// Theory / Approach:
// Convert the alien alphabet into a rank table, then compare each adjacent pair
// of words using those ranks instead of normal character order.
//
// Why this works:
// A list is sorted if every neighboring pair is sorted. The first differing
// character determines word order; if no difference exists, the shorter word must come first.
//
// Time Complexity: O(total characters)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int rank[26];
        for (int i = 0; i < (int)order.size(); ++i) rank[order[i]-'a'] = i;
        for (int i = 0; i + 1 < (int)words.size(); ++i) {
            if (!inOrder(words[i], words[i+1], rank)) return false;
        }
        return true;
    }
private:
    bool inOrder(const string& a, const string& b, int rank[26]) {
        int n = min(a.size(), b.size());
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) return rank[a[i]-'a'] < rank[b[i]-'a'];
        }
        return a.size() <= b.size();
    }
};

int main() {
    Solution sol;
    vector<string> words = {"hello","leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    cout << boolalpha;
    cout << "Words: [hello, leetcode], order=" << order << "\n";
    cout << "Sorted: " << sol.isAlienSorted(words, order) << endl;

    vector<string> words2 = {"word","world","row"};
    string order2 = "worldabcefghijkmnpqstuvxyz";
    cout << "Words: [word, world, row], order=" << order2 << "\n";
    cout << "Sorted: " << sol.isAlienSorted(words2, order2) << endl;
    return 0;
}
