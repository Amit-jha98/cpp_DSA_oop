// 95. Encode and Decode Strings (LeetCode Premium)
// Design an algorithm to encode a list of strings to a single string,
// and decode it back to the original list, handling any characters.
// Theory / Approach:
// Encode each string as length + delimiter + content. During decode, read the
// length first, then consume exactly that many characters.
//
// Why this works:
// Length-prefix encoding avoids ambiguity even when strings contain delimiters,
// digits, or empty content.
//
// Time Complexity: O(total characters)
// Space Complexity: O(total characters)
#include <bits/stdc++.h>
using namespace std;

class Codec {
public:
    // Encode each string as "<length>#<string>"
    string encode(vector<string>& strs) {
        string res;
        for (auto& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < (int)s.size()) {
            int j = i;
            while (s[j] != '#') ++j;
            int len = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, len);
            res.push_back(str);
            i = j + 1 + len;
        }
        return res;
    }
};

int main() {
    Codec codec;
    vector<string> strs = {"hello", "world", "foo#bar", ""};
    string encoded = codec.encode(strs);
    cout << "Encoded: " << encoded << endl;
    vector<string> decoded = codec.decode(encoded);
    cout << "Decoded: ";
    for (auto& s : decoded) cout << "[" << s << "] ";
    cout << endl;
    return 0;
}
