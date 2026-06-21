// 48. Word Ladder
// Find the length of the shortest transformation sequence from beginWord
// to endWord, changing one letter at a time, each intermediate word must
// exist in wordList.
// Theory / Approach:
// Use BFS from beginWord. For each word, change one character at a time and
// enqueue dictionary words that have not been visited.
//
// Why this works:
// Each transformation has equal cost, so BFS reaches endWord using the fewest
// transformations.
//
// Time Complexity: O(N * L * 26)
// Space Complexity: O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int level = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string word = q.front(); q.pop();
                if (word == endWord) return level;
                for (int j = 0; j < (int)word.size(); ++j) {
                    char orig = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig) continue;
                        word[j] = c;
                        if (dict.count(word) && !visited.count(word)) {
                            visited.insert(word);
                            q.push(word);
                        }
                    }
                    word[j] = orig;
                }
            }
            ++level;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << "beginWord=hit, endWord=cog\n";
    cout << "Ladder Length: " << sol.ladderLength("hit", "cog", wordList) << endl;
    return 0;
}
