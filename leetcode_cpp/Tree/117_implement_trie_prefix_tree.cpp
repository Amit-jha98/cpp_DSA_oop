// 117. Implement Trie (Prefix Tree)
// A trie supporting insert, search (exact word), and startsWith (prefix).
// Theory / Approach:
// Store words in a trie where each edge represents a character. Mark nodes that
// end complete words, and follow character edges for search/prefix checks.
//
// Why this works:
// Words sharing prefixes share trie nodes, so checking a prefix is just walking
// the path for its characters.
//
// Time Complexity: O(length) per operation
// Space Complexity: O(total inserted characters)
#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie() {
        children.assign(26, nullptr);
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new Trie();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = find(word);
        return node && node->isEnd;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    vector<Trie*> children;
    bool isEnd;

    Trie* find(const string& s) {
        Trie* node = this;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->children[idx]) return nullptr;
            node = node->children[idx];
        }
        return node;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << boolalpha;
    cout << "search(\"apple\") -> " << trie.search("apple") << endl;   // true
    cout << "search(\"app\") -> " << trie.search("app") << endl;       // false
    cout << "startsWith(\"app\") -> " << trie.startsWith("app") << endl; // true
    trie.insert("app");
    cout << "search(\"app\") -> " << trie.search("app") << endl;       // true
    return 0;
}
