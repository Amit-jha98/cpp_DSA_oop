// 118. Add and Search Word - Data structure design
// Design a data structure that supports adding words and searching,
// where the search word may contain '.' to match any letter.
// Theory / Approach:
// Use a trie for stored words. For normal characters, follow one child; for '.',
// try every existing child recursively.
//
// Why this works:
// The wildcard can represent any single character, so branching over trie
// children explores exactly all matching possibilities.
//
// Time Complexity: O(26^dots * length) worst case
// Space Complexity: O(total inserted characters)
#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
    WordDictionary() {
        children.assign(26, nullptr);
        isEnd = false;
    }

    void addWord(string word) {
        WordDictionary* node = this;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new WordDictionary();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, this);
    }

private:
    vector<WordDictionary*> children;
    bool isEnd;

    bool searchHelper(const string& word, int idx, WordDictionary* node) {
        if (!node) return false;
        if (idx == (int)word.size()) return node->isEnd;
        char c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && searchHelper(word, idx + 1, node->children[i])) return true;
            }
            return false;
        } else {
            return searchHelper(word, idx + 1, node->children[c - 'a']);
        }
    }
};

int main() {
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    cout << boolalpha;
    cout << "search(\"pad\") -> " << wd.search("pad") << endl; // false
    cout << "search(\"bad\") -> " << wd.search("bad") << endl; // true
    cout << "search(\".ad\") -> " << wd.search(".ad") << endl; // true
    cout << "search(\"b..\") -> " << wd.search("b..") << endl; // true
    return 0;
}
