// 119. Word Search II
// Given a board and a list of words, find all words that can be formed
// by sequentially adjacent cells, using a Trie + DFS for efficiency.
// Theory / Approach:
// Build a trie of all words, then backtrack on the board. DFS follows trie edges
// and records a word whenever a terminal trie node is reached.
//
// Why this works:
// The trie prunes paths that are not prefixes of any target word, while DFS
// checks all valid board paths without reusing cells.
//
// Time Complexity: O(mn * 4^L) worst case, usually pruned by the trie
// Space Complexity: O(total word characters)
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string word = ""; // non-empty if a word ends here
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto& w : words) insertWord(root, w);

        int m = board.size(), n = board[0].size();
        vector<string> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }
private:
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& res) {
        if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size()) return;
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;

        TrieNode* next = node->children[c - 'a'];
        if (!next->word.empty()) {
            res.push_back(next->word);
            next->word = ""; // avoid duplicates
        }

        board[i][j] = '#'; // mark visited
        dfs(board, i + 1, j, next, res);
        dfs(board, i - 1, j, next, res);
        dfs(board, i, j + 1, next, res);
        dfs(board, i, j - 1, next, res);
        board[i][j] = c; // restore
    }
};

int main() {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};

    Solution sol;
    auto res = sol.findWords(board, words);
    cout << "Found words: ";
    for (auto& w : res) cout << w << " ";
    cout << endl;
    return 0;
}
